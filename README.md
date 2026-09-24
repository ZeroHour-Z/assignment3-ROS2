# RoboMaster assignment3 ROS2
这份仓库提供一个基础工程，供你在 Ubuntu 22.04 / ROS 2 Humble 上，基于海康机器人 MVS SDK 完成相机功能包。

目前只有最小节点和启动配置，连接相机、发布图像、参数设置及断线重连需要你完成。目录划分仅供参考，你可以根据需要调整。

## 开始

1. 点击 GitHub 页面右上角的 **Fork**，将仓库复制到你的账号下。
2. 在你的 Fork 页面点击 **Code**，复制地址并克隆到本地：

   ```bash
   # 将下面的地址替换为你的 Fork 地址
   git clone <你的 Fork 地址>
   cd robomaster-camera-assignment
   ```

3. 阅读 [ROS 2 教程](docs/ROS2Tutorial.md) 和 [作业要求](docs/assignment.md)，按下面的步骤构建并启动工程。
4. 在自己的仓库中完成开发，提交并推送改动，最后提交你的 GitHub 仓库链接。

[AGENTS.md](AGENTS.md) 用于约束 AI 助手的帮助范围：你可以用 AI 理解概念和分析问题，核心实现需要自己完成。

## 仓库结构

```text
robomaster-camera-assignment/          # 同时作为 colcon 工作空间
├── AGENTS.md                         # AI 助教规范
├── README.md
├── docs/ROS2Tutorial.md              # ROS 2 教程
├── docs/assignment.md                # 作业要求
└── src/hikrobot_camera/              # ROS 2 功能包
    ├── package.xml                   # 包信息与依赖
    ├── CMakeLists.txt                # 构建与安装配置
    ├── include/hikrobot_camera/
    │   └── camera_node.hpp          # 节点声明
    ├── src/
    │   ├── main.cpp                 # 程序入口
    │   └── camera_node.cpp          # 在这里开始实现
    ├── launch/camera.launch.py       # 启动文件
    ├── config/camera.yaml           # 参数配置
    ├── cmake/                       # 可按需添加 SDK 查找模块
    └── test/                        # 可按需添加测试
```

## 环境与依赖

先安装 ROS 2 Humble 与开发工具，确保 `ros2`、`colcon` 和 `rosdep` 可用。

工程目前没有接入 MVS SDK。你需要从 [海康机器人下载中心](https://www.hikrobotics.com/cn/machinevision/service/download/?module=0) 下载适合系统架构的 SDK，阅读随附文档，并完成构建集成。ROS 和系统依赖可以通过 rosdep 安装，厂商 SDK 需要单独配置。

## 编译

在新终端中进入仓库根目录，运行：

```bash
source /opt/ros/humble/setup.bash
# 仅当系统尚未初始化 rosdep 时执行一次：sudo rosdep init
rosdep update
rosdep install --from-paths src --ignore-src -r -y --rosdistro humble
colcon build --symlink-install --packages-select hikrobot_camera
```

本仓库本身就是工作空间，不需要再放到另一个工作空间的 `src` 中。如果你想使用已有工作空间，也可以只把 `src/hikrobot_camera` 放进去。

## 运行

另开终端，在仓库根目录运行：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch hikrobot_camera camera.launch.py
```

如果你使用 Zsh，将环境脚本的 `.bash` 换为 `.zsh`。

初始工程会输出 `Training scaffold only` 并保持运行，按 Ctrl+C 退出。此时尚未实现相机功能，没有图像话题是正常的。

你也可以指定自己的参数文件：

```bash
ros2 launch hikrobot_camera camera.launch.py params_file:=/absolute/path/to/camera.yaml
```

当前 YAML 只配置了 `use_sim_time`。相机相关参数需要你在代码中声明并实现后，再加入配置文件。

## 完成与提交

从 `camera_node.cpp` 的 TODO 开始，按 [作业要求](docs/assignment.md) 完成相机功能。你可以增加源文件或 SDK 封装类，并相应更新构建配置。

完成后：

- 更新 README，说明 SDK 及依赖的安装方式、如何编译启动、有哪些可配置参数。如果有未完成的功能或已知问题，简单注明即可。
- 将源代码、Launch 和参数配置推送到你的 Fork, 然后提交仓库链接到 2719850558@qq.com，格式为：第三次作业-班级-姓名（第三次作业-自动化2305-周湛昊）


---

## 在这里解释你的项目

例如：

1. 如何编译：
2. 运行方式：