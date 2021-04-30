#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <eigen3/Eigen/Dense>
#include <Eigen/Geometry>  
#include <cmath>
#include <vector>
//#include <tf.h>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  int i,j;
  double d = 0.5;
  double theta20= 0.8;
  double theta1= 0.2;
  double theta2= 0.3;
  double PI=3.14;
  double l1 = 0.164544, l2= 0.164544, l3=0.435295, l4=0.285, r1=0.125,r2=0.125,r3=0.125; 
  double gamma1 = 1.57 , gamma2 = 1.57, gamma3 = 0.75;


  double thetaR_P;
  double Beta;
  double d_P_A1x, d_P_A1z, dPA1;
  double d_P_A2x, d_P_A2z, dPA2;


  thetaR_P = PI/2+theta2-theta1+Beta;
  Beta = asin(l2*l2+l4*l4-l1*l1)/(2*l2*l4);
  dPA1 = (l4*l4+l1*l1-l2*l2)/(2*l4);
  d_P_A1x = dPA1;
  d_P_A1z = -sqrt (l1*l1-(dPA1*dPA1));
  dPA2 = (l2*l2+l4*l4-l1*l1)/(2*l4);
  d_P_A2x = -dPA2;
  d_P_A2z = -sqrt (l2*l2-(dPA2*dPA2));

  Eigen::Matrix4d O_A1 ;


    Eigen::Matrix4d O_R;

  	O_R <<     1,   0,   0,  -d*sin(theta20),
        	     0,   1,   0,       0,
        	     0,   0,   1,  -d*cos(theta20),
               0,   0,   0,       1; 

    Eigen::Matrix4d R_P;

  	R_P <<     cos(thetaR_P),   0,   sin(thetaR_P),  0,
        	            0,   	    1, 		0, 	           0,
        	    -sin(thetaR_P),   0,   cos(thetaR_P),  0,
                   0,           0,   	0,     	       1; 

    Eigen::Matrix4d P_A1;

  	P_A1 <<    1,   0,   0,  d_P_A1x,
        	     0,   1,   0,     0,
        	     0,   0,   1,  d_P_A1z,
               0,   0,   0,     1; 


    Eigen::Matrix4d A_W;

  	A_W <<   cos(PI/2-theta1-Beta),   0,   sin(PI/2-theta1-Beta),  0,
        	            0,   		          1, 		      0, 		           0, 		                
              -sin(PI/2-theta1-Beta),   0,   cos(PI/2-theta1-Beta),  0,
                     0,               	0,         	0,     		       1; 

    O_A1 = O_R * R_P * P_A1 * A_W;
    
    double dO_A1x=O_A1(0,3);
    double dO_A1z=O_A1(2,3);
  

    Eigen::MatrixXd O_R_T(4, 4);
    O_R_T=O_R.transpose();
    Eigen::Matrix4d J_I;
    J_I=O_R.inverse();


	 
   
    // std::cout << O_R << std::endl;
    // std::cout << R_P << std::endl;
    // std::cout << P_A1 << std::endl;
    // std::cout << A_W << std::endl;
    // std::cout << O_A1 << std::endl;
   
    // std::cout << dO_A1x << std::endl;
    // std::cout << dO_A1z << std::endl;
 
    // std::cout << O_R <<  std::endl;
    // std::cout << O_R_T << std::endl;
  
    std::cout <<  J_I << std::endl;
 
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {

    ros::spinOnce();
    loop_rate.sleep();
   
  }

  return 0;
}
