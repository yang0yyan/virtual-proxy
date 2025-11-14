cmake_minimum_required(VERSION 3.15)
project(DualSenseEngine VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(dualsense_engine src/main.cpp src/VirtualHID.cpp src/RealDeviceIO.cpp src/AudioWorker.cpp src/BluetoothSender.cpp)

# include directories

target_include_directories(dualsense_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# link libraries placeholder