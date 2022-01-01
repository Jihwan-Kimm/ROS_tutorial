#include <assignment1_autorunner/as1_autorunner.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "as1_autorunner");
    ros::NodeHandle nh;

    AS1_Autorunner as1_autorunner(nh);
    as1_autorunner.Run();

    return 0;
}