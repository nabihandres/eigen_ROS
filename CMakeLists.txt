cmake_minimum_required(VERSION 3.0.2)
project(test)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
)

find_package(cmake_modules REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Eigen REQUIRED)
include_directories(${Eigen_INCLUDE_DIRS})


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES test
  DEPENDS roscpp rospy tf	 

)



add_executable(helloworld src/helloworld.cpp)
add_executable(eigen src/eigen.cpp)
add_executable(template src/template.cpp)




add_dependencies(helloworld ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(eigen ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(eigen
 ${catkin_LIBRARIES}
 ${Eigen_LIBRARIES}   
)

add_dependencies(template ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(eigen
 ${catkin_LIBRARIES}
 ${Eigen_LIBRARIES}   
)


target_link_libraries(helloworld 
 ${catkin_LIBRARIES})

target_link_libraries(template
 ${catkin_LIBRARIES})

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



