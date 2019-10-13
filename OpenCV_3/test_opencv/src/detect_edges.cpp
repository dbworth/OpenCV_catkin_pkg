
// Load an image and detect edges using Canny
// with two different kernels.
//
// Works with OpenCV 3 and 4.
// Code is from the OpenCV 'samples' directory.

#include <cstdio> // printf

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp> // imshow
#include <opencv2/imgcodecs.hpp> // imread
#include <opencv2/core/utility.hpp> // CommandLineParser (OpenCV 3 and 4)

int edgeThresh = 1;
int edgeThreshScharr = 1;

cv::Mat image;
cv::Mat gray;
cv::Mat blurImage;
cv::Mat edge1;
cv::Mat edge2;
cv::Mat cedge;

const char* window_name1 = "Edge map : Canny default (Sobel gradient)";
const char* window_name2 = "Edge map : Canny with custom gradient (Scharr)";

// Define a trackbar callback
static void onTrackbar(int, void*)
{
    cv::blur(gray, blurImage, cv::Size(3,3));

    // Run the edge detector on grayscale
    cv::Canny(blurImage, edge1, edgeThresh, edgeThresh*3, 3);
    cedge = cv::Scalar::all(0);

    image.copyTo(cedge, edge1);
    cv::imshow(window_name1, cedge);

    // Canny detector with scharr
    cv::Mat dx;
    cv::Mat dy;
    cv::Scharr(blurImage, dx, CV_16S, 1, 0);
    cv::Scharr(blurImage, dy, CV_16S, 0, 1);
    cv::Canny(dx,dy, edge2, edgeThreshScharr, edgeThreshScharr*3);

    // Using Canny's output as a mask, we display our result
    cedge = cv::Scalar::all(0);
    image.copyTo(cedge, edge2);
    cv::imshow(window_name2, cedge);
}

static void help()
{
    printf("\nThis sample demonstrates Canny edge detection \n"
           "Usage: \n"
           "    rosrun test_opencv detect_edges $(rospack find test_opencv)/images/sudoku.png \n\n");
}

const char* keys =
{
    "{help h||}{@image |default.jpg|input image name}" // OpenCV 3 and 4
};

int main(int argc, const char** argv)
{
    cv::CommandLineParser parser(argc, argv, keys);
    const std::string filename = parser.get<std::string>(0); // OpenCV 3 and 4

    //image = cv::imread(cv::samples::findFile(filename), cv::IMREAD_COLOR);
    image = cv::imread(filename, cv::IMREAD_COLOR);

    if (image.empty())
    {
        printf("\nCannot read image file: %s\n", filename.c_str());
        help();
        return -1;
    }

    cedge.create(image.size(), image.type());
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Create a window
    cv::namedWindow(window_name1, 1);
    cv::namedWindow(window_name2, 1);

    // Add a toolbar
    cv::createTrackbar("Canny threshold default", window_name1, &edgeThresh, 100, onTrackbar);
    cv::createTrackbar("Canny threshold Scharr", window_name2, &edgeThreshScharr, 400, onTrackbar);

    // Show the image
    onTrackbar(0, 0);

    // Wait for a key stroke; the same function arranges events processing
    cv::waitKey(0);

    return 0;
}
