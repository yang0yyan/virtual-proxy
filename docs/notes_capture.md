# 抓包建议

- 使用 USBPcap + Wireshark 捕获 USB 模式下的 interrupt transfers（过滤 vid/pid）。
- 记录输出 report 的时间序列（speaker packet 的连续块）。
- 蓝牙建议使用外部 HCI sniffer 或 Windows 的 BT tracing 工具。