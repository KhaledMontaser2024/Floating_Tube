
#include <SPI.h>
#include <ros.h>
#include "float_task/floatMsg.h"
#include "std_msgs/UInt16.h"
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

#define CE_PIN 9 
#define CSN_PIN 10

#define HasPresser 1
#define HasTime 2

unsigned int ReceivedPresserReadings [16] = {0};
unsigned int ReceivedTimeReadings [16] = {0};

unsigned int StationCommand = 0;
unsigned int AckSignal = 0;
unsigned int FloatState = 0;

bool CommandCheck =false;
bool doneReceiving = false;
bool doneSending = false;
uint8_t x =0;
ros::NodeHandle nh;
void RadioConfigure(void);    // open the included "RF24.h" to accuratly change configuration otherwise leave it is it is
bool TryReceiveReplyFromFloat(void);
void SendCommandsToFloat(unsigned int Command);
void OperationOnTheReceivedSignal(void);


void CommandHandler(const std_msgs::UInt16& msg)
{
  StationCommand = msg.data;
 if (StationCommand == 1 || StationCommand == 2 )
  { 
    SendCommandsToFloat(StationCommand);
    FloatState = 1;
  }
} 


std_msgs::UInt16 StationCommands;
ros::Subscriber <std_msgs::UInt16> CommandSub("/station_to_float",CommandHandler);
float_task::floatMsg PresserReadings;
ros::Publisher FloatPublisher("/float_to_station",&PresserReadings);


///////////////////////////////////////////////////////

RF24 radio(CE_PIN, CSN_PIN);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL }; //ONE pipe from Tx to Rx and the other from Rx to Tx 

void setup() 
{
  // Serial.begin(9600);
  // printf_begin();
  nh.initNode();
  nh.advertise(FloatPublisher);
  nh.subscribe(CommandSub);
  radio.begin();
  RadioConfigure();
  // radio.printDetails();

}

void loop() 
{  
  // radio.startListening();
  // while(!radio.available())
  // {

  // }
  // radio.read(&x, sizeof(x));
  // Serial.println(x);

  if (TryReceiveReplyFromFloat())
  {
    OperationOnTheReceivedSignal();
  }
  nh.spinOnce();
}

void RadioConfigure(void)
{  
  radio.setRetries(15,15);
  radio.setPayloadSize(32);
  radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);
  radio.setAutoAck(true);
  return;
}


////////////////////////// Rx Side ///////////////////////////////////////

void SendCommandsToFloat(unsigned int Command) // see if you can minimize the size of the variable
{
  radio.stopListening(); //Tx Mode 

  ///////////////////////// Sending ///////////////////////////
  while (!doneSending)
  {
    doneSending = radio.write(&Command, sizeof(unsigned int)); 
  }
  doneSending = false;
  ////////////////////////////////////////////////////////////

  radio.flush_tx();  
  radio.flush_rx();
  
  // nh.loginfo("command Sent");  
  return;
}

bool TryReceiveReplyFromFloat(void)
{ 
  radio.startListening(); //Rx Mode

  if(!radio.available())
  {
    //nh.loginfo("Wating for float ...");
    return false; 
  } 
  
  switch(FloatState)
  {
    case HasPresser: 
      radio.read(ReceivedPresserReadings, sizeof(ReceivedPresserReadings));
      radio.flush_rx();
      FloatState = 2;      

    break;

    case HasTime:
      radio.read(ReceivedTimeReadings, sizeof(ReceivedTimeReadings));
      radio.flush_rx();
      FloatState = 0;
      return true;      
    break;

    default:
    break;
  }

  return false;
}

void OperationOnTheReceivedSignal(void)
{ 
  for (int i=0;i<16;i++)
  {
    PresserReadings.readings[i] = ReceivedPresserReadings[i];
    PresserReadings.readings[i+16] = ReceivedTimeReadings[i];
    
  }
 
  FloatPublisher.publish(&PresserReadings);

  return;
}