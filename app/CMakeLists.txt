add_executable(shell-app main.cpp ../include/optimizer.cpp ../include/PID.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/matplotlib-cpp
    
)
find_package(PythonLibs 2.7)
target_include_directories(shell-app PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(shell-app ${PYTHON_LIBRARIES})