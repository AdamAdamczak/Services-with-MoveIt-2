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

#ifndef ADAMCZAK_MOVEIT__VISIBILITY_CONTROL_HPP_
#define ADAMCZAK_MOVEIT__VISIBILITY_CONTROL_HPP_

////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32)
  #if defined(ADAMCZAK_MOVEIT_BUILDING_DLL) || defined(ADAMCZAK_MOVEIT_EXPORTS)
    #define ADAMCZAK_MOVEIT_PUBLIC __declspec(dllexport)
    #define ADAMCZAK_MOVEIT_LOCAL
  #else  // defined(ADAMCZAK_MOVEIT_BUILDING_DLL) || defined(ADAMCZAK_MOVEIT_EXPORTS)
    #define ADAMCZAK_MOVEIT_PUBLIC __declspec(dllimport)
    #define ADAMCZAK_MOVEIT_LOCAL
  #endif  // defined(ADAMCZAK_MOVEIT_BUILDING_DLL) || defined(ADAMCZAK_MOVEIT_EXPORTS)
#elif defined(__linux__)
  #define ADAMCZAK_MOVEIT_PUBLIC __attribute__((visibility("default")))
  #define ADAMCZAK_MOVEIT_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
  #define ADAMCZAK_MOVEIT_PUBLIC __attribute__((visibility("default")))
  #define ADAMCZAK_MOVEIT_LOCAL __attribute__((visibility("hidden")))
#else
  #error "Unsupported Build Configuration"
#endif

#endif  // ADAMCZAK_MOVEIT__VISIBILITY_CONTROL_HPP_
