#ifndef _ROS_rov_system_IMU_h
#define _ROS_rov_system_IMU_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rov_system
{

  class IMU : public ros::Msg
  {
    public:
      typedef float _yaw_angle_type;
      _yaw_angle_type yaw_angle;
      typedef float _pitch_angle_type;
      _pitch_angle_type pitch_angle;

    IMU():
      yaw_angle(0),
      pitch_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_yaw_angle;
      u_yaw_angle.real = this->yaw_angle;
      *(outbuffer + offset + 0) = (u_yaw_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_angle);
      union {
        float real;
        uint32_t base;
      } u_pitch_angle;
      u_pitch_angle.real = this->pitch_angle;
      *(outbuffer + offset + 0) = (u_pitch_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_yaw_angle;
      u_yaw_angle.base = 0;
      u_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_angle = u_yaw_angle.real;
      offset += sizeof(this->yaw_angle);
      union {
        float real;
        uint32_t base;
      } u_pitch_angle;
      u_pitch_angle.base = 0;
      u_pitch_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch_angle = u_pitch_angle.real;
      offset += sizeof(this->pitch_angle);
     return offset;
    }

    virtual const char * getType() override { return "rov_system/IMU"; };
    virtual const char * getMD5() override { return "2250930edcf74ca890c84af102d1ccc5"; };

  };

}
#endif
