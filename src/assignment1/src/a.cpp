#include <ros_tutorial/a.h>

A::A(){
    pub_=nh_.advertise<assignment1::as1>("as1", 10);
}

void A::Run(){
    ros::Rate rate(10);

    nh_.param("/a/int_param", int_data_, -1);

    while(ros::ok()){
        msg_.num=int_data_++;
        pub_.publish(msg_);
        ROS_INFO("A Publish Msg : %d", msg_.num);
        rate.sleep();
    }
}