cmake_minimum_required(VERSION 2.8)
project(test_opencv)

# use C++11
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  #cv_bridge # Use OpenCV provided by ROS
  opencv3_catkin
)

find_package(OpenCV 3 REQUIRED)

catkin_package()

message("OpenCV_INCLUDE_DIRS = " ${OpenCV_INCLUDE_DIRS})
message("OpenCV_LIBRARIES = " ${OpenCV_LIBRARIES})

include_directories(${catkin_INCLUDE_DIRS}
                    ${OpenCV_INCLUDE_DIRS})


add_executable(print_version src/print_version.cpp)
target_link_libraries(print_version ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


add_executable(detect_edges src/detect_edges.cpp)
target_link_libraries(detect_edges ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


# (optional) You need to enable the non-free library in opencv3_catkin.
add_executable(test_sift src/test_sift.cpp)
target_link_libraries(test_sift ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
