## test_opencv

A catkin package containing some simple tests to check if OpenCV is installed correctly and that your ROS packages are linking to the correct library version.  

### Usage:

Print the OpenCV version:  
`$ rosrun test_opencv print_version`  

Load an image and detect edges using Canny  
with two different kernels:  
`$ rosrun test_opencv detect_edges $(rospack find test_opencv)/images/sudoku.png`  

(optional) Test if OpenCV was compiled with SIFT.  
You need to enable the non-free module in `opencv4_catkin` and edit the `CMakeLists.txt` file in this package.  
`$ rosrun test_opencv test_sift $(rospack find test_opencv)/images/fruits.jpg`  

