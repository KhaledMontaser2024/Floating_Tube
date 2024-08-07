#ifndef _ROS_draven_control_raspberry_msg_h
#define _ROS_draven_control_raspberry_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace draven_control
{

  class raspberry_msg : public ros::Msg
  {
    public:
      int16_t control_data[9];

    raspberry_msg():
      control_data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_control_datai;
      u_control_datai.real = this->control_data[i];
      *(outbuffer + offset + 0) = (u_control_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_control_datai.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->control_data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_control_datai;
      u_control_datai.base = 0;
      u_control_datai.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_control_datai.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->control_data[i] = u_control_datai.real;
      offset += sizeof(this->control_data[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "draven_control/raspberry_msg"; };
    virtual const char * getMD5() override { return "7c79e7397ab2d4e546820c1f196c68fe"; };

  };

}
#endif
