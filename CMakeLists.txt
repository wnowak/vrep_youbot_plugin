cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

rosbuild_init()

set(VREP_DIR $ENV{VREP_DIR})
if (NOT DEFINED VREP_DIR)
	message(FATAL_ERROR "Environment variable not set: VREP_DIR")
endif (NOT DEFINED VREP_DIR)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${VREP_DIR})

include_directories(${VREP_DIR}/programming/include)


rosbuild_add_library(v_repExtyouBot
	src/v_repExtyouBot.cpp 
	${VREP_DIR}/programming/common/v_repLib.cpp

	src/lua/GenericLuaFunctionRegistry.cpp
	src/lua/GenericLuaCallback.cpp

	src/VRepPluglet.cpp
	src/VRepPlugletRegistry.cpp

	src/ros/RosLuaCallback.cpp
	src/ros/VRepRosPluglet.cpp

	src/ros/callback/ClockCallback.cpp
	src/ros/pluglet/ClockPluglet.cpp

	src/ros/callback/LaserScanCallback.cpp
	src/ros/pluglet/LaserScanPluglet.cpp

	src/ros/callback/PointCloudCallback.cpp
	src/ros/pluglet/PointCloudPluglet.cpp

	src/ros/callback/JointControlCallback.cpp
	src/ros/pluglet/JointControlPluglet.cpp

	src/ros/callback/SwedishBaseControllerCallback.cpp
	src/ros/pluglet/SwedishBaseControllerPluglet.cpp
) 

target_link_libraries(v_repExtyouBot pthread dl)

