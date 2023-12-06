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

#ifndef ADAMCZAK_MOVEIT__ADAMCZAK_MOVEIT_HPP_
#define ADAMCZAK_MOVEIT__ADAMCZAK_MOVEIT_HPP_

#include <cstdint>
#include <rclcpp/rclcpp.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include "adamczak_moveit/visibility_control.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "adamczak_moveit/visibility_control.hpp"


namespace adamczak_moveit
{

class ADAMCZAK_MOVEIT_PUBLIC AdamczakMoveit
{
public:
  AdamczakMoveit();
  tf2::Quaternion quaterion_orientation(const geometry_msgs::msg::Vector3  &euler);
private:
  std::string planner_;

};

}  // namespace adamczak_moveit

#endif  // ADAMCZAK_MOVEIT__ADAMCZAK_MOVEIT_HPP_
