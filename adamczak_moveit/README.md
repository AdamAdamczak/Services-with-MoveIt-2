# adamczak_moveit
<!-- Required -->
<!-- Package description -->

## Installation
<!-- Required -->
<!-- Things to consider:
    - How to build package? 
    - Are there any other 3rd party dependencies required? -->

```bash
rosdep install --from-paths src --ignore-src -y
colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=On --packages-up-to adamczak_service adamczak_moveit
```

## Usage
<!-- Required -->
<!-- Things to consider:
    - Launching package. 
    - Exposed API (example service/action call. -->

```bash
ros2 launch moveit_demo moveit_demo.launch.py
ros2 launch adamczak_moveit adamczak_moveit.launch.py
```

## API
    example:
        ros2 service call /adamczak/target_pose  adamczak_service/srv/AdamczakService "{position: {x: pos.x, y: pos.y,z: pos.y}, orientation:
        {x: roll, y: pitch,z: yaw }}"

    response:
        success: "Execution successful"
        failed: "Planning failed!"



### Services and Actions

| Name           | Type                   | Description  |
| -------------- | ---------------------- | ------------ |
| `/adamczak/target_pose` | adamczak_service/srv/AdamczakService | Plan and execute robot's move |

### Parameters

| Name         | Type | Description  |
| ------------ | ---- | ------------ |
| `planner` | string  | planner name  |


## References / External links
<!-- Optional -->
Package create tool - https://github.com/amadeuszsz/create_pkg/