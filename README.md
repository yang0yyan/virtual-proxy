# DualSense-VirtualProxy

**目标**：在 Windows 上实现一个中间层代理，将系统识别为虚拟 DualSense 控制器，并能在虚拟设备与真实 DualSense（USB/蓝牙）间转发 HID 报文（包含震动、自适应扳机与扬声器音频）。最终目标支持蓝牙封包转发 + 动态带宽分配 + 实时重采样。

## 项目结构（初始化）

DualSense-VirtualProxy/

├─ README.md

├─ LICENSE

├─ .gitignore

├─ CHANGELOG.md

├─ docs/

│  ├─ architecture.md

│  └─ todo.md

├─ engine/

│  ├─ CMakeLists.txt

│  ├─ src/

│  │  ├─ main.cpp

│  │  ├─ RingBuffer.h

│  │  ├─ VirtualHID.h

│  │  ├─ VirtualHID.cpp

│  │  ├─ RealDeviceIO.h

│  │  ├─ RealDeviceIO.cpp

│  │  ├─ AudioWorker.h

│  │  ├─ AudioWorker.cpp

│  │  ├─ BluetoothSender.h

│  │  └─ BluetoothSender.cpp

│  └─ third_party/ (samplerate, iMA-adpcm 插件占位)

└─ driver/

   ├─ DualSense_HID_ReportDescriptor.h

   └─ driver_stub/ (UMDF/KMDF 样例骨架占位)

## 快速开始（开发环境）

1. Windows 10/11
2. Visual Studio 2019/2022 with **Desktop development with C++**
3. Windows Driver Kit (WDK)
4. libusbK / WinUSB（可选）
5. USBPcap + Wireshark 用于抓包

克隆后在 `engine/` 使用 CMake 打开并编译（示例 CMakeLists 已包含）。驱动部分需要 WDK/UMDF 环境单独构建并安装测试签名。

## 开发优先级（建议）

1. 阶段 0：抓包（USB 与 BLE）并确认报文样例
2. 阶段 1：实现用户态虚拟 HID 原型（UMDF 用户态或 driver stub）
3. 阶段 2：实现真实设备输入拦截与转发（USB 优先）
4. 阶段 3：实现震动/扳机输出转发
5. 阶段 4：实现扬声器 USB 音频转发
6. 阶段 5：蓝牙分片封包发送 + 动态带宽 + 实时重采样

## 许可证

本仓库使用 Apache License 2.0（详见 `LICENSE` 文件）。

## 联系

在仓库 Issues 中报告问题或功能请求。