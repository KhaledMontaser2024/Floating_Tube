#ifndef _ROS_rov_project_gui_data_h
#define _ROS_rov_project_gui_data_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rov_project
{

  class gui_data : public ros::Msg
  {
    public:
      typedef uint8_t _Speed_type;
      _Speed_type Speed;
      typedef bool _gripper1_type;
      _gripper1_type gripper1;
      typedef bool _gripper2_type;
      _gripper2_type gripper2;
      typedef bool _gripper3_type;
      _gripper3_type gripper3;
      typedef bool _camera1_type;
      _camera1_type camera1;
      typedef bool _camera2_type;
      _camera2_type camera2;
      typedef bool _camera3_type;
      _camera3_type camera3;
      typedef bool _camera4_type;
      _camera4_type camera4;
      typedef bool _camera5_type;
      _camera5_type camera5;
      typedef bool _LED_type;
      _LED_type LED;

    gui_data():
      Speed(0),
      gripper1(0),
      gripper2(0),
      gripper3(0),
      camera1(0),
      camera2(0),
      camera3(0),
      camera4(0),
      camera5(0),
      LED(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->Speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Speed);
      union {
        bool real;
        uint8_t base;
      } u_gripper1;
      u_gripper1.real = this->gripper1;
      *(outbuffer + offset + 0) = (u_gripper1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gripper1);
      union {
        bool real;
        uint8_t base;
      } u_gripper2;
      u_gripper2.real = this->gripper2;
      *(outbuffer + offset + 0) = (u_gripper2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gripper2);
      union {
        bool real;
        uint8_t base;
      } u_gripper3;
      u_gripper3.real = this->gripper3;
      *(outbuffer + offset + 0) = (u_gripper3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gripper3);
      union {
        bool real;
        uint8_t base;
      } u_camera1;
      u_camera1.real = this->camera1;
      *(outbuffer + offset + 0) = (u_camera1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->camera1);
      union {
        bool real;
        uint8_t base;
      } u_camera2;
      u_camera2.real = this->camera2;
      *(outbuffer + offset + 0) = (u_camera2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->camera2);
      union {
        bool real;
        uint8_t base;
      } u_camera3;
      u_camera3.real = this->camera3;
      *(outbuffer + offset + 0) = (u_camera3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->camera3);
      union {
        bool real;
        uint8_t base;
      } u_camera4;
      u_camera4.real = this->camera4;
      *(outbuffer + offset + 0) = (u_camera4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->camera4);
      union {
        bool real;
        uint8_t base;
      } u_camera5;
      u_camera5.real = this->camera5;
      *(outbuffer + offset + 0) = (u_camera5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->camera5);
      union {
        bool real;
        uint8_t base;
      } u_LED;
      u_LED.real = this->LED;
      *(outbuffer + offset + 0) = (u_LED.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LED);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->Speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Speed);
      union {
        bool real;
        uint8_t base;
      } u_gripper1;
      u_gripper1.base = 0;
      u_gripper1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gripper1 = u_gripper1.real;
      offset += sizeof(this->gripper1);
      union {
        bool real;
        uint8_t base;
      } u_gripper2;
      u_gripper2.base = 0;
      u_gripper2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gripper2 = u_gripper2.real;
      offset += sizeof(this->gripper2);
      union {
        bool real;
        uint8_t base;
      } u_gripper3;
      u_gripper3.base = 0;
      u_gripper3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gripper3 = u_gripper3.real;
      offset += sizeof(this->gripper3);
      union {
        bool real;
        uint8_t base;
      } u_camera1;
      u_camera1.base = 0;
      u_camera1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->camera1 = u_camera1.real;
      offset += sizeof(this->camera1);
      union {
        bool real;
        uint8_t base;
      } u_camera2;
      u_camera2.base = 0;
      u_camera2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->camera2 = u_camera2.real;
      offset += sizeof(this->camera2);
      union {
        bool real;
        uint8_t base;
      } u_camera3;
      u_camera3.base = 0;
      u_camera3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->camera3 = u_camera3.real;
      offset += sizeof(this->camera3);
      union {
        bool real;
        uint8_t base;
      } u_camera4;
      u_camera4.base = 0;
      u_camera4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->camera4 = u_camera4.real;
      offset += sizeof(this->camera4);
      union {
        bool real;
        uint8_t base;
      } u_camera5;
      u_camera5.base = 0;
      u_camera5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->camera5 = u_camera5.real;
      offset += sizeof(this->camera5);
      union {
        bool real;
        uint8_t base;
      } u_LED;
      u_LED.base = 0;
      u_LED.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->LED = u_LED.real;
      offset += sizeof(this->LED);
     return offset;
    }

    virtual const char * getType() override { return "rov_project/gui_data"; };
    virtual const char * getMD5() override { return "45e91d04e923fad89afc7c06ec8c84a1"; };

  };

}
#endif
