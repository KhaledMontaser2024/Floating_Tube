#ifndef _ROS_rov_system_MotionMessage_h
#define _ROS_rov_system_MotionMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rov_system
{

  class MotionMessage : public ros::Msg
  {
    public:
      typedef bool _Reverse_Control_type;
      _Reverse_Control_type Reverse_Control;
      typedef uint8_t _Speed_type;
      _Speed_type Speed;
      typedef float _Forward_Backward_Axis_type;
      _Forward_Backward_Axis_type Forward_Backward_Axis;
      typedef float _Pitch_Axis_type;
      _Pitch_Axis_type Pitch_Axis;
      typedef float _Yaw_Axis_type;
      _Yaw_Axis_type Yaw_Axis;
      typedef float _Up_Down_Axis_type;
      _Up_Down_Axis_type Up_Down_Axis;
      typedef float _Left_Right_Axis_type;
      _Left_Right_Axis_type Left_Right_Axis;

    MotionMessage():
      Reverse_Control(0),
      Speed(0),
      Forward_Backward_Axis(0),
      Pitch_Axis(0),
      Yaw_Axis(0),
      Up_Down_Axis(0),
      Left_Right_Axis(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_Reverse_Control;
      u_Reverse_Control.real = this->Reverse_Control;
      *(outbuffer + offset + 0) = (u_Reverse_Control.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Reverse_Control);
      *(outbuffer + offset + 0) = (this->Speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Speed);
      union {
        float real;
        uint32_t base;
      } u_Forward_Backward_Axis;
      u_Forward_Backward_Axis.real = this->Forward_Backward_Axis;
      *(outbuffer + offset + 0) = (u_Forward_Backward_Axis.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Forward_Backward_Axis.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Forward_Backward_Axis.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Forward_Backward_Axis.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Forward_Backward_Axis);
      union {
        float real;
        uint32_t base;
      } u_Pitch_Axis;
      u_Pitch_Axis.real = this->Pitch_Axis;
      *(outbuffer + offset + 0) = (u_Pitch_Axis.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Pitch_Axis.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Pitch_Axis.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Pitch_Axis.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Pitch_Axis);
      union {
        float real;
        uint32_t base;
      } u_Yaw_Axis;
      u_Yaw_Axis.real = this->Yaw_Axis;
      *(outbuffer + offset + 0) = (u_Yaw_Axis.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Yaw_Axis.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Yaw_Axis.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Yaw_Axis.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Yaw_Axis);
      union {
        float real;
        uint32_t base;
      } u_Up_Down_Axis;
      u_Up_Down_Axis.real = this->Up_Down_Axis;
      *(outbuffer + offset + 0) = (u_Up_Down_Axis.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Up_Down_Axis.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Up_Down_Axis.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Up_Down_Axis.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Up_Down_Axis);
      union {
        float real;
        uint32_t base;
      } u_Left_Right_Axis;
      u_Left_Right_Axis.real = this->Left_Right_Axis;
      *(outbuffer + offset + 0) = (u_Left_Right_Axis.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Left_Right_Axis.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Left_Right_Axis.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Left_Right_Axis.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Left_Right_Axis);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_Reverse_Control;
      u_Reverse_Control.base = 0;
      u_Reverse_Control.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Reverse_Control = u_Reverse_Control.real;
      offset += sizeof(this->Reverse_Control);
      this->Speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Speed);
      union {
        float real;
        uint32_t base;
      } u_Forward_Backward_Axis;
      u_Forward_Backward_Axis.base = 0;
      u_Forward_Backward_Axis.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Forward_Backward_Axis.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Forward_Backward_Axis.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Forward_Backward_Axis.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Forward_Backward_Axis = u_Forward_Backward_Axis.real;
      offset += sizeof(this->Forward_Backward_Axis);
      union {
        float real;
        uint32_t base;
      } u_Pitch_Axis;
      u_Pitch_Axis.base = 0;
      u_Pitch_Axis.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Pitch_Axis.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Pitch_Axis.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Pitch_Axis.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Pitch_Axis = u_Pitch_Axis.real;
      offset += sizeof(this->Pitch_Axis);
      union {
        float real;
        uint32_t base;
      } u_Yaw_Axis;
      u_Yaw_Axis.base = 0;
      u_Yaw_Axis.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Yaw_Axis.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Yaw_Axis.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Yaw_Axis.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Yaw_Axis = u_Yaw_Axis.real;
      offset += sizeof(this->Yaw_Axis);
      union {
        float real;
        uint32_t base;
      } u_Up_Down_Axis;
      u_Up_Down_Axis.base = 0;
      u_Up_Down_Axis.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Up_Down_Axis.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Up_Down_Axis.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Up_Down_Axis.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Up_Down_Axis = u_Up_Down_Axis.real;
      offset += sizeof(this->Up_Down_Axis);
      union {
        float real;
        uint32_t base;
      } u_Left_Right_Axis;
      u_Left_Right_Axis.base = 0;
      u_Left_Right_Axis.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Left_Right_Axis.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Left_Right_Axis.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Left_Right_Axis.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Left_Right_Axis = u_Left_Right_Axis.real;
      offset += sizeof(this->Left_Right_Axis);
     return offset;
    }

    virtual const char * getType() override { return "rov_system/MotionMessage"; };
    virtual const char * getMD5() override { return "7eb98eb82c57df30ddb0b5aae1644949"; };

  };

}
#endif
