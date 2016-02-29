#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Num.h"

#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker1");

 
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<krssg::Num>("chatter", 1000);

  ros::Rate loop_rate(1);

//
ifstream file("/home/harshit/catkin_ws/src/krssg/src/talker1.txt");
   int id;int ctr=0;
   int a[100];
   for(int i =0;i<100;i++)
   {
   a[i]=99999;
   }
   while(file>>id)
   {
   cout<<id<<endl;
a[ctr]=id;
ctr++;
   }
   
//



 
  int count = 0;
  while (ros::ok())
  {
    
   krssg::Num number;

    
    for(int i =0;i<100;i++)
{
if(a[i]!=99999)
{
    ROS_INFO("%d", number.num);

    chatter_pub.publish(number.num);

    
    
}
ros::spinOnce();

    loop_rate.sleep();
}
  


  return 0;
}
}
