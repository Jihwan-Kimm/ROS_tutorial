#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <boost/thread/thread.hpp>
#include <sstream>
#include <ros/spinner.h>
#include <ros/callback_queue.h>

ros::Publisher pub;
ros::Subscriber sub;

void num_cb(const std_msgs::Int32& msg){
    static int p_data = 0;
    int data = msg.data;
    ROS_INFO("[node D] Receive : %d", data);
    
    return;
}

int main
(int argc, char* argv[])
{
    ros::init(argc, argv, "node_d");
    ros::NodeHandle nh;
    pub = nh.advertise<std_msgs::Int32>("/node_d", 10);
    sub = nh.subscribe("/node_c", 10, num_cb);
    ros::Rate rate(10);

    int i =0;
    while(nh.ok()){
        std_msgs::Int32 p_msg;
        p_msg.data = i++;
        pub.publish(p_msg);
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}