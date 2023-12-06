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

#include "adamczak_moveit/adamczak_moveit.hpp"

#include <iostream>

namespace adamczak_moveit
{

AdamczakMoveit::AdamczakMoveit()
{
}

tf2::Quaternion AdamczakMoveit::quaterion_orientation(const geometry_msgs::msg::Vector3 &euler)
{
tf2::Quaternion myQuaternion;
myQuaternion.setRPY(euler.x,euler.y,euler.z);
myQuaternion=myQuaternion.normalize();

return  myQuaternion;
}

}  // namespace adamczak_moveit
