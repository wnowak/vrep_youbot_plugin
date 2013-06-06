/*
 * LaserScanPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/pluglet/OdometryPluglet.h"
#include "v_repLib.h"

namespace vrep {

OdometryPluglet::OdometryPluglet() : VRepRosPluglet() {

}

OdometryPluglet::~OdometryPluglet() {

}

void OdometryPluglet::init() {
	ros::NodeHandle nodeHandle;
	publisher =  nodeHandle.advertise<nav_msgs::Odometry>(this->topicName, 1);
}

void OdometryPluglet::setFrameID(std::string id) {
	frameID = id;
}

void OdometryPluglet::setChildID(std::string id) {
	childID = id;
}

void OdometryPluglet::setHandle(int handle) {
	this->handle = handle;
}


void OdometryPluglet::v_repStart_callback() {

}

void OdometryPluglet::v_repMessage_callback() {
	// calculate x and y position and orientation a
	double x, y, a;
	
	simFloat position[3];
	if (simGetObjectPosition(handle, -1, position) == -1)
		return;

	x = position[0];
	y = position[1];

	// orientation needs to account for different coordinate system	
	simFloat orientation[3];
	if (simGetObjectOrientation(handle, -1, orientation) == -1)
		return;

	if (orientation[0] > 0)
		a = -M_PI/2 + orientation[1];
	else
		a = M_PI/2 - orientation[1];

	// setup message
	nav_msgs::Odometry msg;
	msg.header.frame_id = frameID;
	msg.child_frame_id = childID;
	msg.pose.pose.position.x = x;
	msg.pose.pose.position.y = y;
	msg.pose.pose.orientation.w = cos(a/2);
	msg.pose.pose.orientation.z = sin(a/2);

	publisher.publish(msg);
}

void OdometryPluglet::v_repEnd_callback() {

}

void OdometryPluglet::v_repSimStarts_callback() {
}

void OdometryPluglet::v_repSimEnds_callback() {
}

}
