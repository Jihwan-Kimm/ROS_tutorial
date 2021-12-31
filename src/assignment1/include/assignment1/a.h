#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <assignment1/as1.h>

class A{
    public:
        A();
        void Run();
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_;
        assignment1::as1 msg_;
        int int_data_;
};
