#include <actionlib/client/simple_action_client.h>
#include "learning_a/DoDishesAction.h"
#include "ros/ros.h"

typedef actionlib::SimpleActionClient<learning_a::DoDishesAction> Client;

void donecb(const actionlib::SimpleClientGoalState& state,
	const learning_a::DoDishesResultConstPtr& result)
	{
	ROS_INFO("Finish yeah!");
	ros::shutdown();
	
	}
void activecb()
{

	ROS_INFO("Goal just went active");

}

void feedbackcb(const learning_a::DoDishesFeedbackConstPtr& feedback)
{

	ROS_INFO("percent_complete : %f", feedback->percent_complete);

}






int main(int argc,char **argv)
{

	ros::init(argc,argv,"do dishes client");

	Client client("do_dishes",true);
	
	
	ROS_INFO("Waiting for Action server to start.");
	client.waitForServer();
	ROS_INFO("Action Started,sending goal.");
	learning_a::DoDishesGoal goal;
	goal.dishwasher_id = 1;
	
	
	
	client.sendGoal(goal, &donecb, &activecb ,&feedbackcb);
	
	ros::spin();
	
	return 0;
	
		
		

}


