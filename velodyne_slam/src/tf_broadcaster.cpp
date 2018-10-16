#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "velodyne_tf");
	ros::NodeHandle n;
	ros::Rate r(100);
	tf::TransformBroadcaster broadcaster;

	while(n.ok()){
		broadcaster.sendTransform(
			tf::StampedTransform(
				tf::Transform(
					tf::Quaternion(0, 0, 0, 1),
					tf::Vector3(0.0, 0.0, 0.24)),
					ros::Time::now(), "base_link", "base_scan"));
		broadcaster.sendTransform(
			tf::StampedTransform(
				tf::Transform(
					tf::Quaternion(0, 0, 0, 1),
					tf::Vector3(0.0, 0.0, 0.01)),
					ros::Time::now(), "odom", "base_link"));

		r.sleep();
	}
}
