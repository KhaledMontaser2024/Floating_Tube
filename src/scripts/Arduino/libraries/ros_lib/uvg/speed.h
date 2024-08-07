#ifndef _ROS_uvg_speed_h
#define _ROS_uvg_speed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace uvg
{

  class speed : public ros::Msg
  {
    public:
      typedef uint8_t _motor1_type;
      _motor1_type motor1;
      typedef uint8_t _motor2_type;
      _motor2_type motor2;
      typedef uint8_t _motor3_type;
      _motor3_type motor3;
      typedef uint8_t _motor4_type;
      _motor4_type motor4;
      typedef uint8_t _Motion_type;
      _Motion_type Motion;

    speed():
      motor1(0),
      motor2(0),
      motor3(0),
      motor4(0),
      Motion(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor1);
      *(outbuffer + offset + 0) = (this->motor2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor2);
      *(outbuffer + offset + 0) = (this->motor3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor3);
      *(outbuffer + offset + 0) = (this->motor4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor4);
      *(outbuffer + offset + 0) = (this->Motion >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Motion);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->motor1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor1);
      this->motor2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor2);
      this->motor3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor3);
      this->motor4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor4);
      this->Motion =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Motion);
     return offset;
    }

    virtual const char * getType() override { return "uvg/speed"; };
    virtual const char * getMD5() override { return "383477903ff6a382d7c1d5e02fd2b94b"; };

  };

}
#endif
