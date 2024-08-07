#ifndef _ROS_piMaster_image_motion_data_h
#define _ROS_piMaster_image_motion_data_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "piMaster/Vector2.h"

namespace piMaster
{

  class image_motion_data : public ros::Msg
  {
    public:
      int8_t center_matrix[9];
      typedef piMaster::Vector2 _direction_vector_type;
      _direction_vector_type direction_vector;

    image_motion_data():
      center_matrix(),
      direction_vector()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_center_matrixi;
      u_center_matrixi.real = this->center_matrix[i];
      *(outbuffer + offset + 0) = (u_center_matrixi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->center_matrix[i]);
      }
      offset += this->direction_vector.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_center_matrixi;
      u_center_matrixi.base = 0;
      u_center_matrixi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->center_matrix[i] = u_center_matrixi.real;
      offset += sizeof(this->center_matrix[i]);
      }
      offset += this->direction_vector.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "piMaster/image_motion_data"; };
    virtual const char * getMD5() override { return "d59639cc4e5456758dc90ac9990388ba"; };

  };

}
#endif
