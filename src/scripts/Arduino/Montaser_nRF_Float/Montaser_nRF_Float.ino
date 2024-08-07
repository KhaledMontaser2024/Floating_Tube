/*
  This code is designed to back and forth communicate between Two nRF sensors using nRF24 library. 
  in my aplication im sending and receiving from two nodes named "Station" and "Float". Basicly 
  Float node send array of values to station node then after station node makes sure data are 
  right it sends back a command message to float and the cycle goes on. 

  NOTE that same code can be used in both transceivers with only ONE change in (role) variable.
  created by Khaled Montaser.
  CrocoMarine ROV team.
*/
/*10/4*/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

#define CE_PIN 7 
#define CSN_PIN 8

#define MotorDriver1EN1 3
#define Motor_T1		    5
#define Motor_T2		    6

#define Down            0
#define Up              16
#define Stop            2

uint8_t x =5;
void RadioConfigure(void);    // open the included "RF24.h" to accuratly change configuration otherwise leave it is it is

///////// Functions to handle Float node //////////// 
void ReceiveCommandsFromStation(void);
void OperationOnTheReceivedCommand(void);
void SendPresserReadings(void);
void SendTimeStamp(void);
void GoFish(void);

//////////////////////////////////////////////////////

/////////// Functions to handle Float Movement//////////
void Float_Direction(char direction);
void GetReadings(int direction);

////////////////////////////////////////////////////////


unsigned int PresserReadings [16] = {0};
unsigned int TimeStamp [16] = {0};
bool SendingDone = false;
unsigned int ReceiveStationCommand = 0;
unsigned long ReadingTime =0;

Adafruit_BMP280 bmp; // I2C
RF24 radio(CE_PIN, CSN_PIN);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL }; //ONE pipe from Tx to Rx and the other from Rx to Tx 

void setup() 
{
  // Serial.begin(9600);
  // printf_begin();
  pinMode(MotorDriver1EN1, OUTPUT);
  pinMode(Motor_T1, OUTPUT);
  pinMode(Motor_T2, OUTPUT);  
  bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  radio.begin();
  RadioConfigure();
  // radio.printDetails();  
}

void loop() 
{
  // radio.stopListening();
  // radio.write(&x,sizeof(x));
  // Serial.println("done");
  ReceiveCommandsFromStation();
  OperationOnTheReceivedCommand();
}

void RadioConfigure(void)
{
  radio.setRetries(15,15);
  radio.setPayloadSize(32);
  radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);
  radio.setAutoAck(true);  
  return;
}

////////////////////////// Float Movement //////////////////////////////////////////

void GetReadings(int direction)
{
  switch (direction)
  {
    case Up:    
      for (int i=8 ; i<16 ; i++)
      { 
        PresserReadings[i] = bmp.readPressure()/100;
        TimeStamp[i] = ReadingTime/1000;
        Serial.println(TimeStamp[i]);
        delay(500);
      }
    break;

    case Down:
      
      for (int i=0 ; i<12 ; i++)
      {
        PresserReadings[i] = bmp.readPressure()/100;
        TimeStamp[i] = ReadingTime/1000;
        Serial.println(TimeStamp[i]);
        if (PresserReadings[i] == PresserReadings[i-1] && PresserReadings[i] == PresserReadings[i-2])
        {
          break;
        }
        delay(500);
      }
    break;

    default:
    break;
  }
  return;
}
void Float_Direction(char direction)
{
  switch(direction)
  {
  	case Down:
    	digitalWrite(Motor_T2,LOW);
  		digitalWrite(Motor_T1,HIGH);
  		
      break;
  	
    case Up:
    	digitalWrite(Motor_T2,HIGH);
  		digitalWrite(Motor_T1,LOW);
  		break;
  	
    case Stop:
     	digitalWrite(Motor_T2,LOW);
  		digitalWrite(Motor_T1,LOW);
  		break;
  	
    default:
  		break;
  }
 return;
}

/////////////////////////////// Tx Side /////////////////////////////////////////////
void ReceiveCommandsFromStation(void)
{ 
  radio.startListening(); //Rx Mode
  while (!radio.available()){}
  radio.read(&ReceiveStationCommand, sizeof(ReceiveStationCommand));
  // Serial.println(ReceiveStationCommand);
  radio.flush_rx();
  return;
}

void OperationOnTheReceivedCommand(void)
{
  switch (ReceiveStationCommand)
  {
    case 1:
      ReadingTime = millis();
      GoFish();
      SendPresserReadings();
      SendTimeStamp();
      ReceiveStationCommand = 0;
    break;
    
    case 2:
      SendPresserReadings();
      SendTimeStamp();
      ReceiveStationCommand = 0;
    break;

    default:
    break;
  }
  return;
}



void SendPresserReadings(void)
{
  radio.stopListening(); //Tx Mode
  ///////////////////////// Sending ///////////////////////////////////
  while (!SendingDone) 
  {
    SendingDone= radio.write(PresserReadings, sizeof(PresserReadings));
  }
  SendingDone = false;
  //////////////////////////////////////////////////////////////////////
  radio.flush_tx();
  return;
}

void SendTimeStamp(void)
{  
  radio.stopListening(); //Tx Mode
  ////////////////////// Sending /////////////////////////
  while (!SendingDone) 
  {
    SendingDone= radio.write(TimeStamp, sizeof(TimeStamp));
  }
  SendingDone = false;
  /////////////////////////////////////////////////////////
  radio.flush_tx();
  return;
}
void GoFish(void)
{
  Float_Direction(Down);
  delay(200);
  Float_Direction(Stop);
  GetReadings(Down);
  Float_Direction(Up);
  delay(200);
  Float_Direction(Stop);
  GetReadings(Up);

 return;
}
