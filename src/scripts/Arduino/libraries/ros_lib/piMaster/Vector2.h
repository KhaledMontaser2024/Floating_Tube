#ifndef _ROS_piMaster_Vector2_h
#define _ROS_piMaster_Vector2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace piMaster
{

  class Vector2 : public ros::Msg
  {
    public:
      typedef int8_t _x_type;
      _x_type x;
      typedef int8_t _y_type;
      _y_type y;

    Vector2():
      x(0),
      y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int8_t real;
        uint8_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int8_t real;
        uint8_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->y = u_y.real;
      offset += sizeof(this->y);
     return offset;
    }

    virtual const char * getType() override { return "piMaster/Vector2"; };
    virtual const char * getMD5() override { return "6a20b9d8cfb71fa36c504f7f2d8fb5dc"; };

  };

}
#endif
