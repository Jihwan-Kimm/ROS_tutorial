#include <ros_tutorial/class_sub.h>

ClassSub::ClassSub(){
    sub_=nh_.subscribe("class_msg", 10, &ClassSub::class_node_cb, this);
}

void ClassSub::class_node_cb(const std_msgs::Int32& msg){
    ROS_WARN("Subscribe class msg : %d", msg.data);
}

void ClassSub::run(){
    ros::Rate rate(10);
    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();
    }
}