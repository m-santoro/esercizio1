#include "ros/ros.h"
#include "my_msgs/MyMsgs.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    
    ros::Publisher publisher_pub = n.advertise<my_msgs::MyMsgs>("publisher", 1000);

    ros::Rate loop_rate(10);

    double count = 0;
    while (ros::ok()) {
        my_msgs::MyMsgs msg;
        msg.axis1 = count;
        msg.axis2 = count;
        msg.axis3 = count;
        msg.axis4 = count;
        msg.axis5 = count;
        msg.axis6 = count;

        publisher_pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();

        ++count;
    }
    return 0;
}
