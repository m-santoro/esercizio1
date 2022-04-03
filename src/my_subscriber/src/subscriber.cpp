#include "ros/ros.h"
#include "my_msgs/MyMsgs.h"

void subscriberCallback(const my_msgs::MyMsgs::ConstPtr& msg) {
  ROS_INFO("Received: [%f, %f, %f, %f, %f, %f]", msg->axis1, msg->axis2, msg->axis3, msg->axis4, msg->axis5, msg->axis6);
}

int main(int argc, char **argv) {
 
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("publisher", 1000, subscriberCallback);

  ros::spin();

  return 0;
}