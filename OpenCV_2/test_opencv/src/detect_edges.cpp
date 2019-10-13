
// Load an image and detect edges using Canny
// with Sobel kernel.
//
// Works with OpenCV 2.
// Code is from the OpenCV 'samples' directory.

#include <cstdio> // printf

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp> // imread, imshow

int edgeThresh = 1;
int edgeThreshScharr = 1;

cv::Mat image;
cv::Mat gray;
cv::Mat blurImage;
cv::Mat edge1;
cv::Mat edge2;
cv::Mat cedge;

const char* window_name1 = "Edge map : Canny default (Sobel gradient)";

// Define a trackbar callback
static void onTrackbar(int, void*)
{
    cv::blur(gray, blurImage, cv::Size(3,3));

    // Run the edge detector on grayscale
    cv::Canny(blurImage, edge1, edgeThresh, edgeThresh*3, 3);
    cedge = cv::Scalar::all(0);

    image.copyTo(cedge, edge1);
    cv::imshow(window_name1, cedge);
}

static void help()
{
    printf("\nThis sample demonstrates Canny edge detection \n"
           "Usage: \n"
           "    rosrun test_opencv detect_edges -image=$(rospack find test_opencv)/images/sudoku.png \n\n");
}

const char* keys =
{
    "{h|help||}{|image|<none>|input image name}" // OpenCV 2
    //"{help h||}{@image |default.jpg|input image name}" // OpenCV 3 and 4
};

int main(int argc, const char** argv)
{
    cv::CommandLineParser parser(argc, argv, keys);

    const std::string filename = parser.get<std::string>("image"); // OpenCV 2
    //const std::string filename = parser.get<std::string>(0); // OpenCV 3 and 4

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

    // Add a toolbar
    cv::createTrackbar("Canny threshold default", window_name1, &edgeThresh, 100, onTrackbar);

    // Show the image
    onTrackbar(0, 0);

    // Wait for a key stroke; the same function arranges events processing
    cv::waitKey(0);

    return 0;
}
