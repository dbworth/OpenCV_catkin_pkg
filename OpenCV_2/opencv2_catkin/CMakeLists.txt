cmake_minimum_required(VERSION 2.8)
project(opencv2_catkin)

find_package(catkin REQUIRED)

# Execute catkin_package_xml()
# This sets the 'CATKIN_GLOBAL_***' variables.
if(NOT _CATKIN_CURRENT_PACKAGE)
  catkin_package_xml()
endif()

include(ExternalProject)

file(MAKE_DIRECTORY ${CATKIN_DEVEL_PREFIX}/include)

message("\nDownloading & compiling OpenCV source ... \n")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(ExternalProject_OpenCV_2.4.13.5)

install(DIRECTORY ${CATKIN_DEVEL_PREFIX}/include/opencv2
        DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h"
                       PATTERN "*.hpp"
                       PATTERN ".svn" EXCLUDE)

catkin_package(INCLUDE_DIRS ${CATKIN_DEVEL_PREFIX}/include
               LIBRARIES opencv_calib3d
                         opencv_contrib
                         opencv_core
                         opencv_features2d
                         opencv_flann
                         opencv_highgui
                         opencv_imgproc
                         opencv_legacy
                         opencv_ml
                         opencv_nonfree
                         opencv_objdetect
                         opencv_photo
                         opencv_stitching
                         opencv_superres
                         opencv_video
                         opencv_videostab
                         opencv_viz)
