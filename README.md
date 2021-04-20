# eigen_ROS
This tutorial is how to use the eigen library to compute matrices, vectors, numerical solvers, and related algorithms

Before to install eigen library we need to learn how run C++ code in ROS

## **1. Run code C++ in ROS**

**Create a workspace**
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
```
**Create a package**
```
catkin_ws/src
catkin_create_pkg test std_msgs rospy roscpp tf
catkin_make
```
_Note:_ Inside the pkg **test** now have two folders **include** and **src**; and two files **CMakeLists.txt** and **package.xml** 

**Clone the helloworld.cpp inside src folder**

```
cd src
git clone 

```
