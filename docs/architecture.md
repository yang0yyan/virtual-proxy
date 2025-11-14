# 架构文档

## 概览

代理由两大部分构成： 驱动层（虚拟 HID 设备）与用户态 Engine（协议解析、转发、音频处理、蓝牙发送）。

数据流：

(真实 DualSense) <--- USB/Bluetooth ---> (Engine: RealDeviceIO) <--> (Engine: VirtualHID) <--- 游戏/系统

关键点：

- Driver（虚拟 HID）在系统注册为 DualSense，接收游戏发送的 output reports。
- Engine 读取虚拟设备 output（DeviceIoControl），将其解析成触觉/音频/扳机命令并下发给真实设备。
- Engine 也读取真实设备的 input 报文并写入虚拟设备 input，令游戏只看到虚拟设备。