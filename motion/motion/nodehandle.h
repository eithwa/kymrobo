#include <cstdio>
#include <highgui.h>
#include <math.h>
#include <ros/ros.h>
#include <signal.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Empty.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CompressedImage.h>
#include <geometry_msgs/Twist.h>
#include <ros/package.h>

using namespace std;

class NodeHandle
{
  public:
    NodeHandle();
    ~NodeHandle();

  private:
    ros::NodeHandle nh;
    //==============subscriber====================
    ros::Subscriber shoot_sub;
    ros::Subscriber arm_sub;
    ros::Subscriber reset_sub;
    ros::Subscriber cmdvel_sub;

    void shootcall(const std_msgs::Empty msg);
    void armcall(const std_msgs::Int32 msg);
    void resetcall(const std_msgs::Empty msg);
    void cmdvelcall(const geometry_msgs::Twist msg);
    //===============publisher====================
    ros::Publisher shoot_pub;
    ros::Publisher arm_pub;
    ros::Publisher reset_pub;
    ros::Publisher cmdvel_pub;
};