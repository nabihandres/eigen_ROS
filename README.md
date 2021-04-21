# eigen_ROS
This tutorial is how to use the eigen library to compute matrices, vectors, numerical solvers, and related algorithms

Before to install eigen library we need to learn how run C++ code in ROS

## **1. Run code C++ in ROS**

**Create a workspace**
```
mkdir -p ~/eigen_ws/src
cd ~/eigen_ws/
catkin_make
```
**Create a package with name test**
```
cd eigen_ws/src
catkin_create_pkg test std_msgs rospy roscpp tf
cd ..
catkin_make
```
_Note:_ Inside the pkg **test** now have two folders **include** and **src**; and two files **CMakeLists.txt** and **package.xml** 

**Clone the talker.cpp inside src folder**

```
cd src
git clone https://github.com/emontero1991/tutorial-c-.git

```
**Modify the Cmakelist of the folder where is the code in cpp**
```
 catkin_package(
 INCLUDE_DIRS include
 LIBRARIES test)
```

```
add_executable(talker src/ talker.cpp)
```

```
add_dependencies(talker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
```

```
target_link_libraries(talker 
 ${catkin_LIBRARIES})
```
**Open new terminal and run roscore**
```
roscore
```
**Open second terminal and run talke.cpp**


```
catkin_make
source devel/setup.bash
rosrun test talker

```

## **2. Install Eigen Library in ROS**

**Modify the Cmakelist of the folder where is the code in cpp**

```
find_package(cmake_modules REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Eigen REQUIRED)
include_directories(${Eigen_INCLUDE_DIRS})

```

```
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES test
  DEPENDS Eigen roscpp rospy tf	   
)
```

```
add_executable(eigen src/eigen.cpp)
```

```
add_dependencies(eigen ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
```

```
target_link_libraries(eigen
 ${catkin_LIBRARIES}
 ${Eigen_LIBRARIES}   
)

```
