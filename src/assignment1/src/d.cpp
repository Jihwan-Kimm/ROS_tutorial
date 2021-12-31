#include <assignment1/d.h>

D::D(){
    sub_=nh_.subscribe("as1", 10, &D::d_node_cb, this);
}

void D::d_node_cb(const assignment1::as1& msg){
    topic_c=msg.num;
    ROS_WARN("D subscribe msg from C : %d", msg.num);
}

void D::Run(){
    ros::Rate rate(10);
    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();
    }
}