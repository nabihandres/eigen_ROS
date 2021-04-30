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
**Open second terminal and run helloworld.cpp**

```
cd eigen_ws
catkin_make
source devel/setup.bash
rosrun test helloworld

```
Now the code is working and we can see **hello world** and the **number** that show the msg 

## **2. How make Eigen Library available on ROS**

**Download FindEigen.cmake in downloads folder**

the file is on 

eigen_ws/src/test/use_eigen

**FindEigen.cmake file should now be added to the cmak Module**

Open a terminal

```
cd /opt/ros/melodic/share/cmake_modules/cmake/Modules/
sudo cp ~/Download/FindEigen.cmake .
password
```
check if FindEigen.cmake copy with ls command
```
ls
```


**Copy and paste eigen.cpp in src**

eigen_ws/src/test/src


**Modify the package.xml in test pkg**

add 

```
<build_depend>cmake_modules</build_depend>
<exec_depend>cmake_modules</exec_depend>
```
modify
```
 <export>
    <cpp cflags="`pkg-config --cflags eigen3` -I${prefix}/include `rosboost-cfg --cflags`" 

         lflags="-Wl,-rpath,${prefix}/lib -L${prefix}/lib -lplanning_models"/>
  </export>
```
**Modify the Cmakelist.txt in test pkg**

add

```
find_package(cmake_modules REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Eigen REQUIRED)
include_directories(${Eigen_INCLUDE_DIRS})

```

modify

```
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES test
  DEPENDS Eigen roscpp rospy tf	   
)
```
add c++ code using eigen library
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
**Open new terminal and run roscore**
```
roscore
```
**Open second terminal and run eigen.cpp**

```
cd eigen_ws
catkin_make
source devel/setup.bash
rosrun test eigen

```

## **3. compute matrices, vectors, with Eigen library**

show many importants links

(http://ros-developer.com/2019/03/27/eigen-arrays-matrices-and-vectors-definition-initialization-and-coefficient-wise-operations/#respond)
(http://ros-developer.com/tag/eigen/)
(https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html)

## **4. namespace in C++**

(https://www.geeksforgeeks.org/namespace-in-c/#:~:text=Namespace%20is%20a%20feature%20added,the%20same%20name%20are%20allowed)
(https://www.tutorialspoint.com/cplusplus/cpp_namespaces.htm)


