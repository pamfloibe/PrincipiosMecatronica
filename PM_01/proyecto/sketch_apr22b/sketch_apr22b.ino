#include <ros.h>
#include <geometry_msgs/Pose2D.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;


void freqCallBack( const std_msgs::Int16& val){
  digitalWrite(13, val.data);
}

ros::Subscriber<std_msgs::Int16> blinker("freq1", freqCallBack );

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(blinker);
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  delay(1);
}
