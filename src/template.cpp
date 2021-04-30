#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <eigen3/Eigen/Dense>
#include <Eigen/Geometry>  
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
// One function works for all data types.

template <typename T>
T myMax(T x, T y)
{
   return (x > y)? x: y;
}


template <typename T>
void bubbleSort(T a[], int n) 
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "template");

  ros::NodeHandle o;


  int a[5] = {10, 50, 30, 40, 20};
  int n = sizeof(a) / sizeof(a[0]);
  // calls template function
  bubbleSort<int>(a, n);
 
  std::cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    	std::cout << std::endl;
  
 
  std::cout << myMax<int>(3, 7) << std::endl;  // Call myMax for int
  std::cout << myMax<double>(8.0, 3.0) << std::endl; // call myMax for double
  std::cout << myMax<char>('a', 'z') << std::endl;   // call myMax for char
  
  while (ros::ok())
  {

    ros::Rate loop_rate(10);
    ros::spinOnce();
    loop_rate.sleep();
   
  }

  return 0;
}


