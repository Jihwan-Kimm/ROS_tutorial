#include <assignment1/c.h>

C::C(){
    pub_=nh_.advertise<assignment1::as1>("topic_c", 10);
    sub_=nh_.subscribe("topic_b", 10, &C::c_node_cb, this);
}

void C::c_node_cb(const assignment1::as1& msg){
    topic_b=msg.num;
}

void C::Run(){
    ros::Rate rate(10);

    nh_.param("/c/int_param", param_c, -1);

    while(ros::ok()){
        ros::spinOnce();
        msg_.num=param_c+topic_b;
        pub_.publish(msg_);
        ROS_INFO("C publish msg to D : %d", msg_.num);
        rate.sleep();
    }
}