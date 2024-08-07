#ifndef _ROS_rov_system_ButtonsStateMessage_h
#define _ROS_rov_system_ButtonsStateMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rov_system/MotionMessage.h"

namespace rov_system
{

  class ButtonsStateMessage : public ros::Msg
  {
    public:
      typedef uint8_t _CommunicationData_type;
      _CommunicationData_type CommunicationData;
      typedef uint8_t _ArduinoData_type;
      _ArduinoData_type ArduinoData;
      typedef rov_system::MotionMessage _MotionData_type;
      _MotionData_type MotionData;

    ButtonsStateMessage():
      CommunicationData(0),
      ArduinoData(0),
      MotionData()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->CommunicationData >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CommunicationData);
      *(outbuffer + offset + 0) = (this->ArduinoData >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ArduinoData);
      offset += this->MotionData.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->CommunicationData =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->CommunicationData);
      this->ArduinoData =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ArduinoData);
      offset += this->MotionData.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rov_system/ButtonsStateMessage"; };
    virtual const char * getMD5() override { return "5e8729ce83d117224342e9fd52378d67"; };

  };

}
#endif
