#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <ros_tutorial/param_msg.h>

class ParamSub{
    public:
        ParamSub();
        void param_node_cb(const ros_tutorial::param_msg& msg);
        void run();
    private:
        ros::NodeHandle nh_;
        ros::Subscriber sub_;
        ros_tutorial::param_msg msg_; 
};