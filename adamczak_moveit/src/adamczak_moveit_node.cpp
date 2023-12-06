// Copyright 2023 AAdamzcak
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "adamczak_moveit/adamczak_moveit_node.hpp"

namespace adamczak_moveit
{

AdamczakMoveitNode::AdamczakMoveitNode(const rclcpp::NodeOptions & options)
:  Node("adamczak_moveit", options), move_group_(std::shared_ptr<rclcpp::Node>(std::move(this)), "panda_arm")
{

  service=create_service<adamczak_service::srv::AdamczakService>("adamczak/target_pose", std::bind(&AdamczakMoveitNode::moveArm, this,
                                                                  std::placeholders::_1, std::placeholders::_2));
  adamczak_moveit_ = std::make_unique<adamczak_moveit::AdamczakMoveit>();
  declare_parameter("planner", "RRTConnectkConfigDefault");
  if (get_parameter("planner", planner_)) {
      RCLCPP_INFO(get_logger(), "Loaded planner parameter: %s", planner_.c_str());
} else {
      RCLCPP_ERROR(get_logger(), "Could not load planner parameter");
}
  
  RCLCPP_INFO(get_logger(),planner_.c_str());
  move_group_.setPlannerId(planner_);
}

void AdamczakMoveitNode::moveArm(const std::shared_ptr<adamczak_service::srv::AdamczakService::Request> request,
          std::shared_ptr<adamczak_service::srv::AdamczakService::Response> response){
      
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received request");
  tf2::Quaternion quaternion = adamczak_moveit_->quaterion_orientation(request->orientation);  
  geometry_msgs::msg::Pose target_pose;
  target_pose.position = request->position;
  target_pose.orientation.x = quaternion.x();
  target_pose.orientation.y = quaternion.y();
  target_pose.orientation.z = quaternion.z();

  move_group_.setPoseTarget(target_pose);
  moveit::planning_interface::MoveGroupInterface::Plan plan;
  bool success = static_cast<bool>(move_group_.plan(plan));
  if (success) {
        move_group_.execute(plan);
        response->success = true;
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Execution successful");
    } else {
        response->success = false;
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Planning failed!");
    }

}

}  // namespace adamczak_moveit

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(adamczak_moveit::AdamczakMoveitNode)
