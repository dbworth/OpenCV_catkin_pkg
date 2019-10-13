
// Print the OpenCV version.
//
// Works with OpenCV 2, 3 and 4.

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**)
{
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;
    std::cout << "Major version : " << CV_MAJOR_VERSION << std::endl;
    std::cout << "Minor version : " << CV_MINOR_VERSION << std::endl;
    std::cout << "Subminor version : " << CV_SUBMINOR_VERSION << std::endl;
}

