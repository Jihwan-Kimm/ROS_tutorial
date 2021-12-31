#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <boost/thread/thread.hpp>
#include <sstream>
#include <ros/spinner.h>
#include <ros/callback_queue.h>

ros::Publisher pub;

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "node_a");
    ros::NodeHandle nh;
    pub = nh.advertise<std_msgs::Int32>("/node_a", 10);
    ros::Rate rate(10);

    int i =0;
    while(nh.ok()){
        std_msgs::Int32 p_msg;
        p_msg.data = i++;
        pub.publish(p_msg);
        ros::spinOnce();
        rate.sleep();

        pub_.publish(msg_);
        ROS_INFO("Param Publish Msg : %d / %s", int_data_, str_data_.c_str());
        rate.sleep();
    }

    return 0;
}