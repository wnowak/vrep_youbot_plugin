vrep_youbot_plugin
==================

Installation
--

1) Install ROS. Currently tested only with ROS Fuerte.

2) Download the BRICS actuator messages, that come e.g. with cob-common 

$ sudo apt-get install ros-fuerte-cob-common

3) Install v-rep (http://www.coppeliarobotics.com/) 

4) Set the environment variable VREP_DIR to the folder where you installed VREP, e.g.

$ export VREP_DIR=~/vrep

It may be convenient to copy that line in the .bashrc file so it is set automatically in each new shell:

5) Clone the repository into a folder under your ROS_PACKAGE_PATH

$ git clone https://github.com/wnowak/vrep_youbot_plugin.git

6) compile

$ rosmake vrep_youbot_plugin



Usage
--

1) Start ros

$ roscore

2) load v-rep bringup launchfile

$ roslaunch vrep_youbot_plugin vrep_youbot.launch 

3) start v-rep from within the folder where you installed v-rep:

$ ./vrep.sh

or alternatively from within the vrep_youbot_plugin dir:

$ ./vrep-start.sh

4) Load the scene file in v-rep (.../vrep_youbot_plugin/scenes/...) 

5) Start the simulation

Note: the simulation must be running before you can control the youBot!


Test ROS plugin
--
1) You can run the test script (test//test_joint_position.sh) in order to check if you are able to control the v-rep youBot using ROS


Have fun!






