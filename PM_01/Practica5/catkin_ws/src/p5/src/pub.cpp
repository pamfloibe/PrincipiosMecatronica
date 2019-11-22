
#include <ros/ros.h>

#include <geometry_msgs/Twist.h>


#define ros_buffer_size 10 // number of messages to buffer before starting to discard
#define ros_loop_rate .5 // 2Hz is the frequency of the ros loop


int main(int argc, char**argv) {
  ros::init(argc, argv, "publisher"); // Node is called open_loop_driver
  ros::NodeHandle nh; // Main access point to communications with ROS

  // publisher for steering
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", ros_buffer_size);

  
  ros::Rate loop_rate(ros_loop_rate);

  while (ros::ok()) {
   
    ros::spinOnce(); // handles callbacks
    geometry_msgs::Twist vel;
    vel.linear.x = 0;
    vel.angular.z = 1.555;
    pub.publish(vel);
    loop_rate.sleep(); // waits what necessary to keep loop_rate
    vel.linear.x = 2;
    vel.angular.z = 0;
    pub.publish(vel);
    loop_rate.sleep();
  }
  return 0;
}
