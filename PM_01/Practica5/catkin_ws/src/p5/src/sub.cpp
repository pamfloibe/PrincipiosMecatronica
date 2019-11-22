#include <ros/ros.h>

#include <std_msgs/String.h>


#define ros_buffer_size 10 // number of messages to buffer before starting to discard
#define ros_loop_rate 2 // 2Hz is the frequency of the ros loop

void strCallBack(const std_msgs::String& msgIn){
	ROS_INFO_STREAM( msgIn.data);
}


int main(int argc, char**argv) {
  ros::init(argc, argv, "subscriber"); // Node is called open_loop_driver
  ros::NodeHandle nh; // Main access point to communications with ROS

  // publisher for steering
  ros::Subscriber sub = nh.subscribe("chatter", ros_buffer_size, strCallBack);

  
  ros::Rate loop_rate(ros_loop_rate);

  while (ros::ok()) {
   
    ros::spinOnce(); // handles callbacks
    loop_rate.sleep(); // waits what necessary to keep loop_rate
  }
  return 0;
}
