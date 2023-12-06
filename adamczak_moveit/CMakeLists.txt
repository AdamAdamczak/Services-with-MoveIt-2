cmake_minimum_required(VERSION 3.14)
project(adamczak_moveit)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies(REQUIRED
  ${${PROJECT_NAME}_BUILD_DEPENDS}
  ${${PROJECT_NAME}_BUILDTOOL_DEPENDS}
)
find_package(adamczak_service REQUIRED)

find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
add_compile_options(-Wall -Wextra -pedantic )

set(ADAMCZAK_MOVEIT_LIB_SRC
  src/adamczak_moveit.cpp
)

set(ADAMCZAK_MOVEIT_LIB_HEADERS
  include/adamczak_moveit/adamczak_moveit.hpp
  include/adamczak_moveit/visibility_control.hpp
)

ament_auto_add_library(${PROJECT_NAME} SHARED
  ${ADAMCZAK_MOVEIT_LIB_SRC}
  ${ADAMCZAK_MOVEIT_LIB_HEADERS}
)

set(ADAMCZAK_MOVEIT_NODE_SRC
  src/adamczak_moveit_node.cpp
)

set(ADAMCZAK_MOVEIT_NODE_HEADERS
  include/adamczak_moveit/adamczak_moveit_node.hpp
)

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  ${ADAMCZAK_MOVEIT_NODE_SRC}
  ${ADAMCZAK_MOVEIT_NODE_HEADERS}
)
rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "adamczak_moveit::AdamczakMoveitNode"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_add_ros_isolated_gtest(test_adamczak_moveit
    test/test_adamczak_moveit.cpp
  )
  ament_target_dependencies(test_adamczak_moveit ${TEST_SOURCES})
  target_link_libraries(test_adamczak_moveit ${PROJECT_NAME})
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
  config
)
