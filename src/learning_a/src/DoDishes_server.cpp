#include <actionlib/server/simple_action_server.h>
#include "learning_a/DoDishesAction.h"
#include "ros/ros.h"

typedef actionlib::SimpleActionServer<learning_a::DoDishesAction> Server;

void execute(const learning_a::DoDishesGoalConstPtr& goal,Server* as)
{
	ros::Rate r(1);
	learning_a::DoDishesFeedback feedback;
	ROS_INFO("Dishwasher %d is working.", goal->dishwasher_id);
	
	
	for(int i=1;i<=10;i++)
	{
		feedback.percent_complete = i*10;
		as->publishFeedback(feedback);
		r.sleep();
		
	}
	
	ROS_INFO("Dishwasher %d finish working.",goal->dishwasher_id);
	as->setSucceeded();
	



}





int main(int argc,char **argv)
{
	ros::init(argc,argv,"do dishes server");

	ros::NodeHandle n;

	Server server(n,"do dishes",boost::bind(&execute,_1,&server),false);
	
	
	server.start();
	
	ros::spin();
	
	return 0;



}
