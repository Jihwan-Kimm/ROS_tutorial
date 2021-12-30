#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <ros_tutorial/param_msg.h>

class ParamPub{
    public:
        ParamPub();
        void run();
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_;
        ros_tutorial::param_msg msg_;
        int int_data_;
        std::string str_data_;
};
