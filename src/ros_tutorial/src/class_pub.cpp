#include <ros_tutorial/class_pub.h>

ClassPub::ClassPub(){
    pub_=nh_.advertise<std_msgs::Int32>("class_msg", 10);
}

void ClassPub::run(){
    ros::Rate rate(1);

    int data=0;

    while(ros::ok()){
        msg_.data=data++;
        pub_.publish(msg_);
        ROS_INFO("Class Publish Msg : %d", msg_.data);
        rate.sleep();
    }
}