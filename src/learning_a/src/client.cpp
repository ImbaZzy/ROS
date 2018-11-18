#include <cstdlib>
#include "ros/ros.h"
#include "learning_a/AddTwoInts.h"



int main(int argc,char **argv)
{
	ros::init(argc,argv,"client");
	
	if(argc != 3){
		ROS_INFO("usage: add two ints client X Y");
		return 1;
		
		
		
		}

	
	ros::NodeHandle n;
	
	
	
	ros::ServiceClient client = n.serviceClient<learning_a::AddTwoInts>("addtwoints");
	
	
	learning_a::AddTwoInts srv;
	srv.request.a=atoll(argv[1]);
	srv.request.b=atoll(argv[2]);
	
	
	if(client.call(srv))
	{
		ROS_INFO("Sum:[%ld]",(long int)srv.response.sum);
	}
	else
	{
		ROS_ERROR("Fail to call servive addtwoints.");
		return 1;
	}

	return 0;


}
