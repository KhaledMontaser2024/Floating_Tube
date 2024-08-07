#ifndef _ROS_draven_control_bno_msg_h
#define _ROS_draven_control_bno_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace draven_control
{

  class bno_msg : public ros::Msg
  {
    public:
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef float _pitch_type;
      _pitch_type pitch;
      typedef float _roll_type;
      _roll_type roll;
      typedef uint8_t _magneto_type;
      _magneto_type magneto;
      typedef uint8_t _gyro_type;
      _gyro_type gyro;
      typedef uint8_t _accelo_type;
      _accelo_type accelo;
      typedef uint8_t _sys_type;
      _sys_type sys;

    bno_msg():
      yaw(0),
      pitch(0),
      roll(0),
      magneto(0),
      gyro(0),
      accelo(0),
      sys(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll);
      *(outbuffer + offset + 0) = (this->magneto >> (8 * 0)) & 0xFF;
      offset += sizeof(this->magneto);
      *(outbuffer + offset + 0) = (this->gyro >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gyro);
      *(outbuffer + offset + 0) = (this->accelo >> (8 * 0)) & 0xFF;
      offset += sizeof(this->accelo);
      *(outbuffer + offset + 0) = (this->sys >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sys);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      this->magneto =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->magneto);
      this->gyro =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gyro);
      this->accelo =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->accelo);
      this->sys =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sys);
     return offset;
    }

    virtual const char * getType() override { return "draven_control/bno_msg"; };
    virtual const char * getMD5() override { return "1266aab9be49b7941a72612838390ce8"; };

  };

}
#endif
