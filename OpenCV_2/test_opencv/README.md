## test_opencv

A catkin package containing some simple tests to check if OpenCV is installed correctly and that your ROS packages are linking to the correct library version.  

### Usage:

Print the OpenCV version:  
`$ rosrun test_opencv print_version`  

Load an image and detect edges using Canny  
with two different kernels:  
`$ rosrun test_opencv detect_edges -image=$(rospack find test_opencv)/images/sudoku.png`  

Load an image and detect SIFT features:  
(The SIFT algorithm is bundled with OpenCV version 2)  
`$ rosrun test_opencv test_sift $(rospack find test_opencv)/images/fruits.jpg`  

