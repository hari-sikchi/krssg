#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Num.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;



void chatter1Callback(const krssg::Num& msg)
{
//ofstream output;
//.open("/home/harshit/catkin_ws/src/krssg/src/result.txt");
ofstream fout;
fout.open("/home/harshit/catkin_ws/src/krssg/src/result.txt",ios::app); 

  ROS_INFO("I heard: [%d]", msg.num);

fout<<msg.num<<" ";
}

void chatter2Callback(const krssg::Num& msg)
{
  ROS_INFO("I heard: [%d]", msg.num);
ofstream fout;
fout.open("/home/harshit/catkin_ws/src/krssg/src/result.txt",ios::app); 
fout<<msg.num<<" ";

fout.close();
//
 ifstream file("/home/harshit/catkin_ws/src/krssg/src/result.txt");
   int id;int ctr=0;
   int a[100];
   for(int i =0;i<100;i++)
   {
   a[i]=99999;
   }
   while(file>>id)
   {
   //cout<<id<<endl;
a[ctr]=id;
ctr++;
//cout<<a[ctr]<<endl;
   }
int b[ctr];
int c[ctr];
 for(int i =0;i<ctr;i++)
   {
   b[i]=a[i];

}
for(int i =0;i<ctr-1;i++)
{
for(int j =0;j<ctr-1;j++)
{
int temp;
if(b[j+1]<b[j])
    {
    temp=b[j+1];
    b[j+1]=b[j];
    b[j]=temp;
    }
}
}
file.close();
ofstream file2("/home/harshit/catkin_ws/src/krssg/src/result2.txt");
for(int i =0;i<ctr;i++)
{
file2<<b[i]<<" ";

}
file2.close();


}
int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

 
  ros::NodeHandle n;


  ros::Subscriber sub1 = n.subscribe("chatter1", 1000, chatter1Callback);
  ros::Subscriber sub2 = n.subscribe("chatter2", 1000, chatter2Callback);


 
ros::spin();

//
/*
 ifstream file("/home/harshit/catkin_ws/src/krssg/src/result.txt");
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
int b[ctr];
int c[ctr];
 for(int i =0;i<ctr;i++)
   {
   b[i]=a[i];

}
for(int i =0;i<ctr-1;i++)
{
for(int j =0;j<ctr-1;j++)
{
int temp;
if(b[j+1]<b[j])
    {
    temp=b[j+1];
    b[j+1]=b[j];
    b[j]=temp;
    }
}
}

ofstream file2("/home/harshit/catkin_ws/src/krssg/src/result2.txt");
for(int i =0;i<ctr;i++)
{
file2<<b[i]<<" ";

}
file2.close();
*/
//
  return 0;
}
