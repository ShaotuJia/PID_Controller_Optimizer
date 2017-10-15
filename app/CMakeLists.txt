add_executable(shell-app main.cpp ../include/optimizer.cpp ../include/PID.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
