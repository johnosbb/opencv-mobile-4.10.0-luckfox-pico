cmake_minimum_required(VERSION 3.5)
project(opencv-mobile-test)
set(CMAKE_CXX_STANDARD 11)

# SET(CMAKE_C_COMPILER "/home/xt/Luckfox/sdk-0710/buildroot-max/luckfox-pico/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-gcc")
# SET(CMAKE_CXX_COMPILER "/home/xt/Luckfox/sdk-0710/buildroot-max/luckfox-pico/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-g++")

# Set the toolchain prefix
SET(TOOLCHAIN_PREFIX "/mnt/buildroot_volume/luckfox-pico/")

# Set the system name and architecture
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR arm)
SET(TOOL_CHAIN_LOCATION sysdrv/source/buildroot/buildroot-2023.02.6/output/host/bin)
# Specify the cross-compiler toolchain binaries using the TOOLCHAIN_PREFIX
SET(CMAKE_C_COMPILER "${TOOLCHAIN_PREFIX}/${TOOL_CHAIN_LOCATION}/arm-rockchip830-linux-uclibcgnueabihf-gcc")
SET(CMAKE_CXX_COMPILER "${TOOLCHAIN_PREFIX}/${TOOL_CHAIN_LOCATION}/arm-rockchip830-linux-uclibcgnueabihf-g++")
SET(CMAKE_AR "${TOOLCHAIN_PREFIX}/${TOOL_CHAIN_LOCATION}/arm-rockchip830-linux-uclibcgnueabihf-ar")
SET(CMAKE_ASM_COMPILER "${TOOLCHAIN_PREFIX}/${TOOL_CHAIN_LOCATION}/arm-rockchip830-linux-uclibcgnueabihf-as")

#set(OpenCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/opencv-mobile-4.8.1-luckfox-pico/lib/cmake/opencv4")
set(OpenCV_DIR "./lib/cmake/opencv4")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV_LIBS=${OpenCV_LIBS}")

add_executable(opencv-mobile-test main.cpp)

target_link_libraries(opencv-mobile-test ${OpenCV_LIBS})
