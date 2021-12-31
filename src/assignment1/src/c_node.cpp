#include <assignment1/c.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "c");
    C c;
    c.Run();

    return 0;
}