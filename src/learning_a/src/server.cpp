#include "ros/ros.h"
#include "learning_a/AddTwoInts.h"


bool add(learning_a::AddTwoInts::Request &req,
	 learning_a::AddTwoInts::Response &res)
{
	res.sum = req.a + req.b;
	ROS_INFO("request: x=[%ld],y=[%ld]",(long int)req.a,(long int)req.b);
	ROS_INFO("sending back response:[%ld]",(long int)res.sum);
	return true;

}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"server");
	
	
	ros::NodeHandle n;
	
	
	
	ros::ServiceServer service = n.advertiseService("addtwoints",add);
	
	
	ROS_INFO("READY TO ADD");
	
	
	
	ros::spin();
	
	return 0;





}
