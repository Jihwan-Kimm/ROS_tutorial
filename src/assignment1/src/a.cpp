#include <assignment1/a.h>

A::A(){
    pub_=nh_.advertise<assignment1::as1>("topic_a", 10);
}

void A::Run(){
    ros::Rate rate(10);

    nh_.param("/a/int_param", param_a, -1);

    while(ros::ok()){
        msg_.num=param_a++;
        pub_.publish(msg_);
        ROS_INFO("A publish msg to B: %d", msg_.num);
        rate.sleep();
    }
}