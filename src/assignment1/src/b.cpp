#include <assignment1/a.h>

B::B(){
    pub_=nh_.advertise<assignment1::as1>("as1", 10);
    sub_=nh_.subscribe("as1", 10, &ParamSub::b_node_cb, this);
}

void ParamSub::b_node_cb(const assignment1::as1& msg){
    ROS_WARN("Subscribe param msg : %d", msg.num);
}

void B::Run(){
    ros::Rate rate(10);

    nh_.param("/b/int_param", int_data_, -1);

    while(ros::ok()){
        ros::spinOnce();
        msg_.num=int_data_++;
        pub_.publish(msg_);
        ROS_INFO("B Publish Msg : %d", msg_.num);
        rate.sleep();
    }
}