#! /usr/bin/python3

import rospy
from float_task.msg import floatMsg
from std_msgs.msg import UInt16

Readings =[]
def ReadingsHandler (msg):
    rospy.loginfo(msg.readings)

StationCommand=UInt16()
rospy.init_node("Station_Node")
StationSubscriber = rospy.Subscriber ("/float_to_station",floatMsg,ReadingsHandler)
Commandpub = rospy.Publisher("/station_to_float",UInt16,queue_size=10)

while not rospy.is_shutdown():
    rospy.loginfo("Enter Command .. if you want the Float to start swimming Enter [1] ,if you want it To Send first array of Readings Enter [2],if you want it To Send Second array of Readings Enter [3]")
    StationCommand = int(input())
    rospy.loginfo("You Entered:")
    rospy.loginfo(StationCommand)
    Commandpub.publish(StationCommand)

