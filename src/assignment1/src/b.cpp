#include <assignment1/b.h>

B::B(){
    pub_=nh_.advertise<assignment1::as1>("as1", 10);
    sub_=nh_.subscribe("as1", 10, &B::b_node_cb, this);
}

void B::b_node_cb(const assignment1::as1& msg){
    topic_a=msg.num;
    ROS_WARN("B subscribe msg from A : %d", msg.num);
}

void B::Run(){
    ros::Rate rate(10);

    nh_.param("/b/int_param", param_b, -1);

    while(ros::ok()){
        ros::spinOnce();
        msg_.num=param_b+topic_a;
        pub_.publish(msg_);
        ROS_INFO("B publish msg to C : %d", msg_.num);
        rate.sleep();
    }
}