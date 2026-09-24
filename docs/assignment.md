# 作业要求：MVS 相机 SDK 的 ROS 2 封装

## 目标

在 Ubuntu 22.04 / ROS 2 Humble 上，你需要使用海康机器人 MVS SDK 开发可复用的 C++ 相机功能包。骨架只提供工程组织和启动入口，核心功能需要你完成。

## 必须完成

1. 能发现设备，并按指定 IP 或序列号选择目标相机；IP 选择适用于对应的网络相机。设备不存在、标识冲突或被占用时，应有明确反馈。
2. 采集并发布标准 `sensor_msgs/msg/Image`，话题可配置。图像尺寸、编码、步长、数据长度和时间信息应有明确含义，能够在 RViz2 正常显示。
3. 通过节点参数读取和设置曝光时间、增益、帧率及像素格式。应说明单位、支持范围、动态修改限制，以及设置失败时的行为。参数变化必须与实际设备状态对应。
4. 支持断线后的重连，恢复有效配置；退出时正确释放资源。
5. 在默认分辨率下保持稳定采集，并尽量提高实际帧率。调试时注意区分设置帧率和实际接收帧率。

## 工程要求

- 能通过 `colcon build`，没有错误或严重警告。
- ROS / 系统依赖通过 package.xml 和 rosdep 管理；厂商 SDK 单独记录安装要求。
- 提供可用的 Launch、参数文件和运行说明。
- 启动launch文件后，相机节点能成功连接相机并进行图片采集。
- 在 `rviz2` 中可以稳定地查看到相机发布的 `/image_raw` 话题，图像显示正常。
- 可以通过命令行或代码设置ROS 2参数，并能正确反映到相机的实际成像效果上。参数更新应校验范围和 SDK 返回值；手动曝光/增益需按需关闭自动模式，设置失败应返回明确原因。

## 交付

将源代码、Launch 和参数配置推送到你的 Fork，在 README 中写清楚安装、编译和运行方式，然后提交仓库链接即可。无需单独填写验收清单或提交记录。

## 官方资料入口

- [ROS 2 Humble 教程](https://docs.ros.org/en/humble/Tutorials.html)
- [ament_cmake 文档](https://docs.ros.org/en/humble/How-To-Guides/Ament-CMake-Documentation.html)
- [HIKROBOT 官网](https://www.hikrobotics.com/cn/machinevision/service/download/?module=0)：下载对应平台的 MVS SDK，阅读随附接口手册及示例。
