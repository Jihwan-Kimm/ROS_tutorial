#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <assignment1/as1.h>

class D{
    public:
        D();
        void d_node_cb(const assignment1::as1& msg);
        void Run();
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_;
        ros::Subscriber sub_;
        int topic_c;
};