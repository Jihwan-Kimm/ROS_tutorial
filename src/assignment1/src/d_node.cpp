#include <assignment1/d.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "d");
    D d;
    d.Run();

    return 0;
}