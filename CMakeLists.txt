cmake_minimum_required(VERSION 3.10)
project(NeuralHW)

find_package(SystemCLanguage CONFIG REQUIRED)
set (CMAKE_CXX_STANDARD ${SystemC_CXX_STANDARD})

link_libraries(SystemC::systemc)

include_directories(
        ${PROJECT_SOURCE_DIR}/neural_hw
        ${SYSTEMC_INCLUDE_DIR}
)

set(SOURCE_FILES
        neural_hw/bus.cpp
        neural_hw/control_unit.cpp
        neural_hw/cpu.cpp
        neural_hw/iocontroller.cpp
        neural_hw/local_mem.cpp
        neural_hw/net_config.cpp
        neural_hw/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${SYSTEMC_LIBRARY})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
