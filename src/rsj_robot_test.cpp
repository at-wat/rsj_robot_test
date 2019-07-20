#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>

#include <tf/transform_datatypes.h>

class RSJRobotTestNode
{
private:
  ros::Subscriber sub_odom_;
  ros::Publisher pub_twist_;

  void cb_odom(const nav_msgs::Odometry::ConstPtr& msg)
  {
  }

public:
  RSJRobotTestNode()
  {
    ros::NodeHandle nh;
    pub_twist_ = nh.advertise<geometry_msgs::Twist>(
        "cmd_vel", 5);
    sub_odom_ = nh.subscribe(
        "odom", 5,
        &RSJRobotTestNode::cb_odom, this);
  }
  void mainloop()
  {
    ROS_INFO("Hello ROS World!");

    ros::Rate rate(10.0);
    while (ros::ok())
    {
      ros::spinOnce();
      // ここに速度指令の出力コード
      rate.sleep();
    }
    // ここに終了処理のコード
  }
};

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "rsj_robot_test_node");

  RSJRobotTestNode robot_test;

  robot_test.mainloop();
}

