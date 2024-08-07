#ifndef _ROS_float_task_floatMsg_h
#define _ROS_float_task_floatMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace float_task
{

  class floatMsg : public ros::Msg
  {
    public:
      uint16_t readings[32];

    floatMsg():
      readings()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 32; i++){
      *(outbuffer + offset + 0) = (this->readings[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->readings[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->readings[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 32; i++){
      this->readings[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->readings[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->readings[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "float_task/floatMsg"; };
    virtual const char * getMD5() override { return "7095b24568c2d0192664ba6b55ccf9e4"; };

  };

}
#endif
