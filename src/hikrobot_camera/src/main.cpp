#include <memory>

#include "hikrobot_camera/camera_node.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<hikrobot_camera::CameraNode>());
  rclcpp::shutdown();
  return 0;
}
