/*
 * ClockPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/callback/OdometryCallback.h"
#include "vrep_plugin/ros/pluglet/OdometryPluglet.h"
#include "vrep_plugin/VRepPlugletRegistry.h"

#include "ros/ros.h"

#include "v_repConst.h"
#include "rosgraph_msgs/Clock.h"

#include "v_repLib.h"

namespace vrep {

OdometryCallback* OdometryCallback::instance = 0;



OdometryCallback::~OdometryCallback() {

}



void OdometryCallback::luaCall(Argslist args) {

	if (args.size() < 4) {
		ROS_ERROR("Not enough arguments for v-rep odometry publisher");
		return;
	}

	OdometryPluglet* pluglet = new OdometryPluglet();
	pluglet->setTopicName(boost::any_cast<std::string>(args[0]));
	pluglet->setFrameID(boost::any_cast<std::string>(args[1]));
	pluglet->setChildID(boost::any_cast<std::string>(args[2]));
	pluglet->setHandle(boost::any_cast<int>(args[3]));
	
	vrep::VRepPlugletRegistry::getInstance()->getPluglets().push_back(pluglet);	
	pluglet->init();
}

GenericLuaCallback::LuaDescription OdometryCallback::getDescription() {
	GenericLuaCallback::LuaDescription d;

	d.name = "rosCreateOdometryPublisher";
	d.tooltip = "rosCreateOdometryPublisher(string topicName)";
	d.argTypes[0] = 4;
	d.argTypes[1] = sim_lua_arg_string;
	d.argTypes[2] = sim_lua_arg_string;
	d.argTypes[3] = sim_lua_arg_string;
	d.argTypes[4] = sim_lua_arg_int;

	return d;
}

}
