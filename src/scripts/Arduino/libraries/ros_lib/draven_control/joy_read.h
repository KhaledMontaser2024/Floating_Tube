#ifndef _ROS_draven_control_joy_read_h
#define _ROS_draven_control_joy_read_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace draven_control
{

  class joy_read : public ros::Msg
  {
    public:
      float axis[5];
      typedef uint16_t _buttons_type;
      _buttons_type buttons;
      typedef int8_t _max_speed_type;
      _max_speed_type max_speed;

    joy_read():
      axis(),
      buttons(0),
      max_speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_axisi;
      u_axisi.real = this->axis[i];
      *(outbuffer + offset + 0) = (u_axisi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_axisi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_axisi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_axisi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->axis[i]);
      }
      *(outbuffer + offset + 0) = (this->buttons >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->buttons >> (8 * 1)) & 0xFF;
      offset += sizeof(this->buttons);
      union {
        int8_t real;
        uint8_t base;
      } u_max_speed;
      u_max_speed.real = this->max_speed;
      *(outbuffer + offset + 0) = (u_max_speed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->max_speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_axisi;
      u_axisi.base = 0;
      u_axisi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_axisi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_axisi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_axisi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->axis[i] = u_axisi.real;
      offset += sizeof(this->axis[i]);
      }
      this->buttons =  ((uint16_t) (*(inbuffer + offset)));
      this->buttons |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->buttons);
      union {
        int8_t real;
        uint8_t base;
      } u_max_speed;
      u_max_speed.base = 0;
      u_max_speed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->max_speed = u_max_speed.real;
      offset += sizeof(this->max_speed);
     return offset;
    }

    virtual const char * getType() override { return "draven_control/joy_read"; };
    virtual const char * getMD5() override { return "27bf700e7ed0abccbf42502680f085ad"; };

  };

}
#endif
