#ifndef _ROS_SERVICE_Order_h
#define _ROS_SERVICE_Order_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace uvg
{

static const char ORDER[] = "uvg/Order";

  class OrderRequest : public ros::Msg
  {
    public:
      typedef uint8_t _order_type;
      _order_type order;

    OrderRequest():
      order(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->order >> (8 * 0)) & 0xFF;
      offset += sizeof(this->order);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->order =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->order);
     return offset;
    }

    virtual const char * getType() override { return ORDER; };
    virtual const char * getMD5() override { return "a0be3ddc8ca24fcfec901321eb13226e"; };

  };

  class OrderResponse : public ros::Msg
  {
    public:
      typedef const char* _feedback_type;
      _feedback_type feedback;

    OrderResponse():
      feedback("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_feedback = strlen(this->feedback);
      varToArr(outbuffer + offset, length_feedback);
      offset += 4;
      memcpy(outbuffer + offset, this->feedback, length_feedback);
      offset += length_feedback;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_feedback;
      arrToVar(length_feedback, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_feedback; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_feedback-1]=0;
      this->feedback = (char *)(inbuffer + offset-1);
      offset += length_feedback;
     return offset;
    }

    virtual const char * getType() override { return ORDER; };
    virtual const char * getMD5() override { return "c14cdf907e5c7c7fd47292add15660f0"; };

  };

  class Order {
    public:
    typedef OrderRequest Request;
    typedef OrderResponse Response;
  };

}
#endif
