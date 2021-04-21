# eigen_ROS
This tutorial is how to use the eigen library to compute matrices, vectors, numerical solvers, and related algorithms

Before to install eigen library we need to learn how can run C++ code in ROS

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

**Copy helloworld.cpp inside the test pkg in src folder**

```
eigen_ws/src/test/src
```
**Modify the Cmakelist of test pkg**
```
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES test
  DEPENDS roscpp rospy tf	 
)
```

```
add_executable(helloworld src/helloworld.cpp)
```

```
add_dependencies(helloworld ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
```

```
target_link_libraries(helloworld 
 ${catkin_LIBRARIES})
```
**Open new terminal and run roscore**
```
roscore
```
**Open second terminal and run talke.cpp**

```
cd eigen_ws
catkin_make
source devel/setup.bash
rosrun test helloworld

```

## **2. How make Eigen Library available on ROS**
**Download FindEigen.cmake in downloads folder**

**FindEigen.cmake file should now be added to the cmak Module**
Open a terminal

```
cd /opt/ros/melodic/share/cmake_modules/cmake/Modules/
sudo cp ~/Download/FindEigen.cmake .
password
```
check if copy is working we find now FindEigen.cmake with ls command

```
ls
```

**Modify the Cmakelist and add Eigen Library to the ROS package **

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
