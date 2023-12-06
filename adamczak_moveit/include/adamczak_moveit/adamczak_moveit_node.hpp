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

#ifndef ADAMCZAK_MOVEIT__ADAMCZAK_MOVEIT_NODE_HPP_
#define ADAMCZAK_MOVEIT__ADAMCZAK_MOVEIT_NODE_HPP_

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include "adamczak_service/srv/adamczak_service.hpp"
#include "adamczak_moveit/adamczak_moveit.hpp"
#include <moveit/move_group_interface/move_group_interface.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/vector3.hpp>

#include "adamczak_moveit/adamczak_moveit.hpp"

namespace adamczak_moveit
{
using AdamczakMoveitPtr = std::unique_ptr<adamczak_moveit::AdamczakMoveit>;

class ADAMCZAK_MOVEIT_PUBLIC AdamczakMoveitNode : public rclcpp::Node
{
public:
  explicit AdamczakMoveitNode(const rclcpp::NodeOptions & options);

private:
  AdamczakMoveitPtr adamczak_moveit_{nullptr};
  moveit::planning_interface::MoveGroupInterface move_group_;
  std::string planner_;
  rclcpp::Service<adamczak_service::srv::AdamczakService>::SharedPtr service;
  void moveArm(const std::shared_ptr<adamczak_service::srv::AdamczakService::Request> request,
          std::shared_ptr<adamczak_service::srv::AdamczakService::Response> response);
};
}  // namespace adamczak_moveit

#endif  // ADAMCZAK_MOVEIT__ADAMCZAK_MOVEIT_NODE_HPP_
