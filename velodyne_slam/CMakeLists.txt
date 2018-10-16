cmake_minimum_required(VERSION 2.8.3)
project(velodyne_slam)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  sensor_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


 add_executable(velodyne_tf src/tf_broadcaster.cpp)
 target_link_libraries(velodyne_tf
   ${catkin_LIBRARIES}
 )

