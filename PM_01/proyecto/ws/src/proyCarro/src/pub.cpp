
#include <ros/ros.h>

#include <std_msgs/Int16.h>


#define ros_buffer_size 10 // number of messages to buffer before starting to discard
#define ros_loop_rate .5 // 2Hz is the frequency of the ros loop


int main(int argc, char**argv) {
  ros::init(argc, argv, "publisher"); // Node is called open_loop_driver
  ros::NodeHandle nh; // Main access point to communications with ROS

  // publisher for steering
  ros::Publisher pub = nh.advertise<std_msgs::Int16>("freq1", ros_buffer_size);

  
  ros::Rate loop_rate(ros_loop_rate);

  while (ros::ok()) {
   
    ros::spinOnce(); // handles callbacks
    std_msgs::Int16 freq;
    freq.data = 1;
    pub.publish(freq);
    loop_rate.sleep(); // waits what necessary to keep loop_rate
    freq.data = 0;
    pub.publish(freq);
    loop_rate.sleep();
  }
  return 0;
}
