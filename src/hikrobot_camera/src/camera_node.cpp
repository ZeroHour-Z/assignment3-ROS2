#include "hikrobot_camera/camera_node.hpp"

namespace hikrobot_camera
{

CameraNode::CameraNode(const rclcpp::NodeOptions & options)
: Node("hikrobot_camera", options)
{
  RCLCPP_WARN(
    get_logger(),
    "Training scaffold only: camera connection, image publishing, and camera "
    "parameter control are NOT implemented.");

  // TODO(student): Implement the requirements in docs/assignment.md.
  // - Device selection and connection.
  // - Image acquisition and sensor_msgs/msg/Image publishing.
  // - Camera parameter inspection and updates.
  // - Disconnection recovery and resource cleanup.
}

}  // namespace hikrobot_camera
