#include <assignment1_autorunner/as1_autorunner.h>

void AS1_Autorunner::Run(){
    register_subscribers();             // Register subscribers that shoud check can go next or not
    ros_autorunner_.init(nh_, sub_v_);   // Initialize the ROS-Autorunner
    ros::Rate rate(10);                  // Rate can be changed
    while(ros::ok()){               
        ros_autorunner_.Run();           // Run Autorunner
        ros::spinOnce();
        rate.sleep();
    }    
}

void AS1_Autorunner::register_subscribers(){
    sub_v_.resize(TOTAL_STEP_NUM);          // Resizing the subscriber vectors. Its size must be same with number of steps

    // Set the check function(subscriber)
    sub_v_[STEP(1)] = nh_.subscribe("topic_a", 3, &AS1_Autorunner::a_to_b_cb, this);
    sub_v_[STEP(2)] = nh_.subscribe("topic_b", 3, &AS1_Autorunner::b_to_c_cb, this);
    sub_v_[STEP(3)] = nh_.subscribe("topic_c", 3, &AS1_Autorunner::c_to_d_cb, this);
}

void AS1_Autorunner::a_to_b_cb(const std_msgs::Int32& msg){
    if(msg.data > 20){
        ros_autorunner_.step_info_list_[STEP(2)].is_prepared = true;
    }
}

void AS1_Autorunner::b_to_c_cb(const std_msgs::Int32& msg){
    if(msg.data > 100){
        ros_autorunner_.step_info_list_[STEP(3)].is_prepared = true;
    }
}

void AS1_Autorunner::c_to_d_cb(const std_msgs::Int32& msg){
    if(msg.data > 200){
        ros_autorunner_.step_info_list_[STEP(4)].is_prepared = true;
    }
}
