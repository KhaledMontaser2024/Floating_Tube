#ifndef _ROS_rov_system_raspberry_h
#define _ROS_rov_system_raspberry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rov_system
{

  class raspberry : public ros::Msg
  {
    public:
      uint32_t raspberrydata_length;
      typedef uint8_t _raspberrydata_type;
      _raspberrydata_type st_raspberrydata;
      _raspberrydata_type * raspberrydata;

    raspberry():
      raspberrydata_length(0), st_raspberrydata(), raspberrydata(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->raspberrydata_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->raspberrydata_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->raspberrydata_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->raspberrydata_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->raspberrydata_length);
      for( uint32_t i = 0; i < raspberrydata_length; i++){
      *(outbuffer + offset + 0) = (this->raspberrydata[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->raspberrydata[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t raspberrydata_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      raspberrydata_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      raspberrydata_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      raspberrydata_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->raspberrydata_length);
      if(raspberrydata_lengthT > raspberrydata_length)
        this->raspberrydata = (uint8_t*)realloc(this->raspberrydata, raspberrydata_lengthT * sizeof(uint8_t));
      raspberrydata_length = raspberrydata_lengthT;
      for( uint32_t i = 0; i < raspberrydata_length; i++){
      this->st_raspberrydata =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_raspberrydata);
        memcpy( &(this->raspberrydata[i]), &(this->st_raspberrydata), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "rov_system/raspberry"; };
    virtual const char * getMD5() override { return "3e22ddadd6f640d1408dd058389ec10b"; };

  };

}
#endif
