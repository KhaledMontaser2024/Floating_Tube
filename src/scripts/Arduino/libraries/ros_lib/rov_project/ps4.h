#ifndef _ROS_rov_project_ps4_h
#define _ROS_rov_project_ps4_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rov_project
{

  class ps4 : public ros::Msg
  {
    public:
      typedef bool _UpArrow_type;
      _UpArrow_type UpArrow;
      typedef bool _DownArrow_type;
      _DownArrow_type DownArrow;
      typedef bool _LeftArrow_type;
      _LeftArrow_type LeftArrow;
      typedef bool _RightArrow_type;
      _RightArrow_type RightArrow;
      typedef bool _x_type;
      _x_type x;
      typedef bool _circle_type;
      _circle_type circle;
      typedef bool _triangle_type;
      _triangle_type triangle;
      typedef bool _square_type;
      _square_type square;
      typedef bool _L1_type;
      _L1_type L1;
      typedef bool _L2_type;
      _L2_type L2;
      typedef bool _R1_type;
      _R1_type R1;
      typedef bool _R2_type;
      _R2_type R2;
      typedef bool _PS_type;
      _PS_type PS;
      typedef bool _share_type;
      _share_type share;
      typedef bool _options_type;
      _options_type options;
      typedef bool _Analog1Up_type;
      _Analog1Up_type Analog1Up;
      typedef bool _Analog1Down_type;
      _Analog1Down_type Analog1Down;
      typedef bool _Analog1Left_type;
      _Analog1Left_type Analog1Left;
      typedef bool _Analog1Right_type;
      _Analog1Right_type Analog1Right;
      typedef bool _Analog2Up_type;
      _Analog2Up_type Analog2Up;
      typedef bool _Analog2Down_type;
      _Analog2Down_type Analog2Down;
      typedef bool _Analog2Left_type;
      _Analog2Left_type Analog2Left;
      typedef bool _Analog2Right_type;
      _Analog2Right_type Analog2Right;

    ps4():
      UpArrow(0),
      DownArrow(0),
      LeftArrow(0),
      RightArrow(0),
      x(0),
      circle(0),
      triangle(0),
      square(0),
      L1(0),
      L2(0),
      R1(0),
      R2(0),
      PS(0),
      share(0),
      options(0),
      Analog1Up(0),
      Analog1Down(0),
      Analog1Left(0),
      Analog1Right(0),
      Analog2Up(0),
      Analog2Down(0),
      Analog2Left(0),
      Analog2Right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_UpArrow;
      u_UpArrow.real = this->UpArrow;
      *(outbuffer + offset + 0) = (u_UpArrow.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->UpArrow);
      union {
        bool real;
        uint8_t base;
      } u_DownArrow;
      u_DownArrow.real = this->DownArrow;
      *(outbuffer + offset + 0) = (u_DownArrow.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->DownArrow);
      union {
        bool real;
        uint8_t base;
      } u_LeftArrow;
      u_LeftArrow.real = this->LeftArrow;
      *(outbuffer + offset + 0) = (u_LeftArrow.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LeftArrow);
      union {
        bool real;
        uint8_t base;
      } u_RightArrow;
      u_RightArrow.real = this->RightArrow;
      *(outbuffer + offset + 0) = (u_RightArrow.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->RightArrow);
      union {
        bool real;
        uint8_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->x);
      union {
        bool real;
        uint8_t base;
      } u_circle;
      u_circle.real = this->circle;
      *(outbuffer + offset + 0) = (u_circle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->circle);
      union {
        bool real;
        uint8_t base;
      } u_triangle;
      u_triangle.real = this->triangle;
      *(outbuffer + offset + 0) = (u_triangle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->triangle);
      union {
        bool real;
        uint8_t base;
      } u_square;
      u_square.real = this->square;
      *(outbuffer + offset + 0) = (u_square.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->square);
      union {
        bool real;
        uint8_t base;
      } u_L1;
      u_L1.real = this->L1;
      *(outbuffer + offset + 0) = (u_L1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L1);
      union {
        bool real;
        uint8_t base;
      } u_L2;
      u_L2.real = this->L2;
      *(outbuffer + offset + 0) = (u_L2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L2);
      union {
        bool real;
        uint8_t base;
      } u_R1;
      u_R1.real = this->R1;
      *(outbuffer + offset + 0) = (u_R1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->R1);
      union {
        bool real;
        uint8_t base;
      } u_R2;
      u_R2.real = this->R2;
      *(outbuffer + offset + 0) = (u_R2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->R2);
      union {
        bool real;
        uint8_t base;
      } u_PS;
      u_PS.real = this->PS;
      *(outbuffer + offset + 0) = (u_PS.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->PS);
      union {
        bool real;
        uint8_t base;
      } u_share;
      u_share.real = this->share;
      *(outbuffer + offset + 0) = (u_share.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->share);
      union {
        bool real;
        uint8_t base;
      } u_options;
      u_options.real = this->options;
      *(outbuffer + offset + 0) = (u_options.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->options);
      union {
        bool real;
        uint8_t base;
      } u_Analog1Up;
      u_Analog1Up.real = this->Analog1Up;
      *(outbuffer + offset + 0) = (u_Analog1Up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Analog1Up);
      union {
        bool real;
        uint8_t base;
      } u_Analog1Down;
      u_Analog1Down.real = this->Analog1Down;
      *(outbuffer + offset + 0) = (u_Analog1Down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Analog1Down);
      union {
        bool real;
        uint8_t base;
      } u_Analog1Left;
      u_Analog1Left.real = this->Analog1Left;
      *(outbuffer + offset + 0) = (u_Analog1Left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Analog1Left);
      union {
        bool real;
        uint8_t base;
      } u_Analog1Right;
      u_Analog1Right.real = this->Analog1Right;
      *(outbuffer + offset + 0) = (u_Analog1Right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Analog1Right);
      union {
        bool real;
        uint8_t base;
      } u_Analog2Up;
      u_Analog2Up.real = this->Analog2Up;
      *(outbuffer + offset + 0) = (u_Analog2Up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Analog2Up);
      union {
        bool real;
        uint8_t base;
      } u_Analog2Down;
      u_Analog2Down.real = this->Analog2Down;
      *(outbuffer + offset + 0) = (u_Analog2Down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Analog2Down);
      union {
        bool real;
        uint8_t base;
      } u_Analog2Left;
      u_Analog2Left.real = this->Analog2Left;
      *(outbuffer + offset + 0) = (u_Analog2Left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Analog2Left);
      union {
        bool real;
        uint8_t base;
      } u_Analog2Right;
      u_Analog2Right.real = this->Analog2Right;
      *(outbuffer + offset + 0) = (u_Analog2Right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Analog2Right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_UpArrow;
      u_UpArrow.base = 0;
      u_UpArrow.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->UpArrow = u_UpArrow.real;
      offset += sizeof(this->UpArrow);
      union {
        bool real;
        uint8_t base;
      } u_DownArrow;
      u_DownArrow.base = 0;
      u_DownArrow.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->DownArrow = u_DownArrow.real;
      offset += sizeof(this->DownArrow);
      union {
        bool real;
        uint8_t base;
      } u_LeftArrow;
      u_LeftArrow.base = 0;
      u_LeftArrow.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->LeftArrow = u_LeftArrow.real;
      offset += sizeof(this->LeftArrow);
      union {
        bool real;
        uint8_t base;
      } u_RightArrow;
      u_RightArrow.base = 0;
      u_RightArrow.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->RightArrow = u_RightArrow.real;
      offset += sizeof(this->RightArrow);
      union {
        bool real;
        uint8_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        bool real;
        uint8_t base;
      } u_circle;
      u_circle.base = 0;
      u_circle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->circle = u_circle.real;
      offset += sizeof(this->circle);
      union {
        bool real;
        uint8_t base;
      } u_triangle;
      u_triangle.base = 0;
      u_triangle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->triangle = u_triangle.real;
      offset += sizeof(this->triangle);
      union {
        bool real;
        uint8_t base;
      } u_square;
      u_square.base = 0;
      u_square.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->square = u_square.real;
      offset += sizeof(this->square);
      union {
        bool real;
        uint8_t base;
      } u_L1;
      u_L1.base = 0;
      u_L1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->L1 = u_L1.real;
      offset += sizeof(this->L1);
      union {
        bool real;
        uint8_t base;
      } u_L2;
      u_L2.base = 0;
      u_L2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->L2 = u_L2.real;
      offset += sizeof(this->L2);
      union {
        bool real;
        uint8_t base;
      } u_R1;
      u_R1.base = 0;
      u_R1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->R1 = u_R1.real;
      offset += sizeof(this->R1);
      union {
        bool real;
        uint8_t base;
      } u_R2;
      u_R2.base = 0;
      u_R2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->R2 = u_R2.real;
      offset += sizeof(this->R2);
      union {
        bool real;
        uint8_t base;
      } u_PS;
      u_PS.base = 0;
      u_PS.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->PS = u_PS.real;
      offset += sizeof(this->PS);
      union {
        bool real;
        uint8_t base;
      } u_share;
      u_share.base = 0;
      u_share.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->share = u_share.real;
      offset += sizeof(this->share);
      union {
        bool real;
        uint8_t base;
      } u_options;
      u_options.base = 0;
      u_options.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->options = u_options.real;
      offset += sizeof(this->options);
      union {
        bool real;
        uint8_t base;
      } u_Analog1Up;
      u_Analog1Up.base = 0;
      u_Analog1Up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Analog1Up = u_Analog1Up.real;
      offset += sizeof(this->Analog1Up);
      union {
        bool real;
        uint8_t base;
      } u_Analog1Down;
      u_Analog1Down.base = 0;
      u_Analog1Down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Analog1Down = u_Analog1Down.real;
      offset += sizeof(this->Analog1Down);
      union {
        bool real;
        uint8_t base;
      } u_Analog1Left;
      u_Analog1Left.base = 0;
      u_Analog1Left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Analog1Left = u_Analog1Left.real;
      offset += sizeof(this->Analog1Left);
      union {
        bool real;
        uint8_t base;
      } u_Analog1Right;
      u_Analog1Right.base = 0;
      u_Analog1Right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Analog1Right = u_Analog1Right.real;
      offset += sizeof(this->Analog1Right);
      union {
        bool real;
        uint8_t base;
      } u_Analog2Up;
      u_Analog2Up.base = 0;
      u_Analog2Up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Analog2Up = u_Analog2Up.real;
      offset += sizeof(this->Analog2Up);
      union {
        bool real;
        uint8_t base;
      } u_Analog2Down;
      u_Analog2Down.base = 0;
      u_Analog2Down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Analog2Down = u_Analog2Down.real;
      offset += sizeof(this->Analog2Down);
      union {
        bool real;
        uint8_t base;
      } u_Analog2Left;
      u_Analog2Left.base = 0;
      u_Analog2Left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Analog2Left = u_Analog2Left.real;
      offset += sizeof(this->Analog2Left);
      union {
        bool real;
        uint8_t base;
      } u_Analog2Right;
      u_Analog2Right.base = 0;
      u_Analog2Right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Analog2Right = u_Analog2Right.real;
      offset += sizeof(this->Analog2Right);
     return offset;
    }

    virtual const char * getType() override { return "rov_project/ps4"; };
    virtual const char * getMD5() override { return "745404af89d14b7109da68c394855bb7"; };

  };

}
#endif
