/*
 * LaserScanPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: walter
 */

#ifndef ODOMETRYPLUGLET_H_
#define ODOMETRYPLUGLET_H_

#include "vrep_plugin/ros/VRepRosPluglet.h"
#include "nav_msgs/Odometry.h"

namespace vrep {

class OdometryPluglet : public VRepRosPluglet {
protected:
	ros::Publisher publisher;
	std::string topicName;
	std::string frameID;
	std::string childID;
	int handle;

public:
	OdometryPluglet();
	virtual ~OdometryPluglet();
	void init();
	void v_repStart_callback();
	void v_repMessage_callback();
	void v_repEnd_callback();
	void v_repSimStarts_callback();
	void v_repSimEnds_callback();


	const std::string& getTopicName() const {
		return topicName;
	}

	void setTopicName(const std::string& topicName) {
		this->topicName = topicName;
	}

	void setFrameID(std::string id);
	void setChildID(std::string id);
	void setHandle(int handle);
};

}
#endif /* ODOMETRYPLUGLET_H_ */
