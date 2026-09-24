"""Launch the training scaffold; this does not implement a camera driver."""

from pathlib import Path

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    default_params = str(
        Path(get_package_share_directory('hikrobot_camera')) / 'config' / 'camera.yaml'
    )
    return LaunchDescription([
        DeclareLaunchArgument(
            'params_file',
            default_value=default_params,
            description='Absolute path to the ROS parameter YAML file.',
        ),
        Node(
            package='hikrobot_camera',
            executable='camera_node',
            name='hikrobot_camera',
            output='screen',
            parameters=[LaunchConfiguration('params_file')],
        ),
    ])
