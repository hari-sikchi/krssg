cmake_minimum_required(VERSION 2.8.3)
project(krssg)
## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg message_generation)

## Declare ROS messages and services
add_message_files(FILES Num.msg)


## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(screamer1 src/screamer1.cpp)
target_link_libraries(screamer1 ${catkin_LIBRARIES})
add_dependencies(screamer1 krssg_generate_messages_cpp)

add_executable(screamer2 src/screamer2.cpp)
target_link_libraries(screamer2 ${catkin_LIBRARIES})
add_dependencies(screamer2 krssg_generate_messages_cpp)

add_executable(hearer src/hearer.cpp)
target_link_libraries(hearer ${catkin_LIBRARIES})
add_dependencies(hearer krssg_tutorials_generate_messages_cpp)


