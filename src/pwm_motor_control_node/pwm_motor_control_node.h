#ifndef PWM_MOTOR_CONTROL_NODE_H
#define PWM_MOTOR_CONTROL_NODE_H

#include "ros/ros.h"

#include "std_msgs/Int8.h"

#include "motor_control.h"

#include "gpio_ros_stub.h"
#include "gpio_pwm_ros_stub.h"

class PwmMotorControlNode
{
public:
    PwmMotorControlNode() = delete;
    PwmMotorControlNode(ros::NodeHandle* node_handle);
    ~PwmMotorControlNode();

private:
    void MotorSpeedCallback(const std_msgs::Int8::ConstPtr& msg);
    void OutputTimerCallback(const ros::TimerEvent& event);

    std::unique_ptr<PwmMotorControl> motor_control_;
    std::int8_t current_motor_speed_;

    ros::NodeHandle nh_;
    ros::Subscriber motor_speed_sub_;
    ros::Timer output_timer_;
};

#endif