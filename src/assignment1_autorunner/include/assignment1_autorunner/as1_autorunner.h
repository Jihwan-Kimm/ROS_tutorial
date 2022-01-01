
#include <ros/ros.h>
#include <ros_autorunner/ros_autorunner.h>
#include <std_msgs/Int32.h>

#define TOTAL_STEP_NUM 4

class AS1_Autorunner : public AutorunnerBase{
private:    
    ros::NodeHandle     nh_;
    ROSAutorunner        ros_autorunner_;
    virtual void register_subscribers();
    void a_to_b_cb(const std_msgs::Int32& msg);
    void b_to_c_cb(const std_msgs::Int32& msg);
    void c_to_d_cb(const std_msgs::Int32& msg);
public:
    Sub_v               sub_v_;
    AS1_Autorunner() {}
    AS1_Autorunner(ros::NodeHandle nh) : nh_(nh){}
    virtual void Run();
};