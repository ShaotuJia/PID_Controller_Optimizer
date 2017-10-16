add_executable(pid_optimizer main.cpp ../include/optimizer.cpp ../include/PID.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/matplotlib-cpp
    
)
find_package(PythonLibs 2.7)
target_include_directories(pid_optimizer PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(pid_optimizer ${PYTHON_LIBRARIES})