set(GTEST_SHUFFLE 1)

add_executable(
    optimizer-test
    main.cpp
    test.cpp
    ../include/optimizer.cpp
    ../include/PID.cpp
)

target_include_directories(optimizer-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(optimizer-test PUBLIC gtest)
