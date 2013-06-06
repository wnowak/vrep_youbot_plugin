/*
 * ClockPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: walter
 */

#ifndef ODOMETRYCALLBACK_H_
#define ODOMETRYCALLBACK_H_

#include "vrep_plugin/ros/RosLuaCallback.h"

namespace vrep {

class OdometryCallback : public GenericLuaCallback {
protected:

public:
	OdometryCallback() : GenericLuaCallback(){
		OdometryCallback::instance = this;
	}

	virtual ~OdometryCallback();

	void luaCall(Argslist args);

	GenericLuaCallback::LuaDescription getDescription();

	void cleanUp();

	LUA_CALLBACK(OdometryCallback);

};

}
#endif /* ODOMETRYPUBLISHER_H_ */
