## opencv2_catkin

A catkin wrapper for OpenCV 2.4.13.5 (22 Dec 2017)  
This downloads and compiles the source code.  

Note: The SIFT algorithm is included with this version of OpenCV.  

Author: David Butterworth, 2017-2018.  
Based on a package by ETHZ-ASL. Removed dependency on `catkin_simple`.  

### Installation

This package was tested on Ubuntu 16.04  

Copy this package into the `src` directory of your catkin workspace.  
Build your catkin workspace:  
e.g.  
Use `catkin build` from `catkin_tools`.  

Ignore the compiler warnings:  
```
cmake/OpenCVPackaging.cmake:23
CPACK_PACKAGE_VERSION does not match version provided by version.hpp header!

modules/core/src/opengl_interop.cpp:65
'void {anonymous}::throw_nogl()' defined but not used
```

### Usage

Check the `test_opencv` package for an example.  
