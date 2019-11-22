// Generated by gencpp from file dstar_nav/cliffResponse.msg
// DO NOT EDIT!


#ifndef DSTAR_NAV_MESSAGE_CLIFFRESPONSE_H
#define DSTAR_NAV_MESSAGE_CLIFFRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dstar_nav
{
template <class ContainerAllocator>
struct cliffResponse_
{
  typedef cliffResponse_<ContainerAllocator> Type;

  cliffResponse_()
    : vectors()  {
    }
  cliffResponse_(const ContainerAllocator& _alloc)
    : vectors(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _vectors_type;
  _vectors_type vectors;





  typedef boost::shared_ptr< ::dstar_nav::cliffResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dstar_nav::cliffResponse_<ContainerAllocator> const> ConstPtr;

}; // struct cliffResponse_

typedef ::dstar_nav::cliffResponse_<std::allocator<void> > cliffResponse;

typedef boost::shared_ptr< ::dstar_nav::cliffResponse > cliffResponsePtr;
typedef boost::shared_ptr< ::dstar_nav::cliffResponse const> cliffResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dstar_nav::cliffResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dstar_nav::cliffResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dstar_nav

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'dstar_nav': ['/home/austinnguyen517/Documents/Research/BML/MultiRobot/AN_PathPlanning/dstar_ws/src/dstar_nav/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dstar_nav::cliffResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dstar_nav::cliffResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dstar_nav::cliffResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dstar_nav::cliffResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dstar_nav::cliffResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dstar_nav::cliffResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dstar_nav::cliffResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d4566730a8e1f6231837d96dc42fdfac";
  }

  static const char* value(const ::dstar_nav::cliffResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd4566730a8e1f623ULL;
  static const uint64_t static_value2 = 0x1837d96dc42fdfacULL;
};

template<class ContainerAllocator>
struct DataType< ::dstar_nav::cliffResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dstar_nav/cliffResponse";
  }

  static const char* value(const ::dstar_nav::cliffResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dstar_nav::cliffResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[] vectors\n"
;
  }

  static const char* value(const ::dstar_nav::cliffResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dstar_nav::cliffResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.vectors);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct cliffResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dstar_nav::cliffResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dstar_nav::cliffResponse_<ContainerAllocator>& v)
  {
    s << indent << "vectors[]" << std::endl;
    for (size_t i = 0; i < v.vectors.size(); ++i)
    {
      s << indent << "  vectors[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.vectors[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSTAR_NAV_MESSAGE_CLIFFRESPONSE_H