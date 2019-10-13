
// Test if OpenCV was compiled with SIFT.
// You need to enable the non-free library.
//
// Works with OpenCV 3 and 4.

#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

//#include <opencv2/nonfree/features2d.hpp> // SIFT (OpenCV 2)

#include <opencv2/core/utility.hpp> // CommandLineParser (OpenCV 3 and 4)
#include <opencv2/xfeatures2d.hpp> // SIFT (OpenCV 3 and 4)

const char* keys =
{
    "{help h||}{@image |default.jpg|input image name}"
};

int main(int argc, const char** argv)
{
    cv::CommandLineParser parser(argc, argv, keys);

    // OpenCV 2
    //if (argc != 2) std::cout << "ERROR: Missing argument" << std::endl;
    //const std::string filename = std::string(argv[1]);

    // OpenCV 3 and 4
    const std::string filename = parser.get<std::string>(0);

    //std::cout << "filename = " << filename << std::endl;

    //cv::Mat image = cv::imread(filename, cv::IMREAD_COLOR);
    cv::Mat image = cv::imread(filename, cv::IMREAD_GRAYSCALE);

    if (image.empty())
    {
        printf("\nCannot read image file: %s\n", filename.c_str());
        return -1;
    }

    std::vector<cv::KeyPoint> keypoints;

    // OpenCV 2
    //{
    //    cv::SiftFeatureDetector detector;
    //    detector.detect(image, keypoints);
    //}

    // OpenCV 3 and 4
    {
        const int num_features = 0;
        const int num_octave_layers = 3;
        const double contrast_threshold = 0.04;
        const double edge_threshold = 10;
        const double sigma = 1.6;
        cv::Ptr<cv::Feature2D> f2d = cv::xfeatures2d::SiftFeatureDetector::create(num_features,
                                                                                  num_octave_layers,
                                                                                  contrast_threshold,
                                                                                  edge_threshold,
                                                                                  sigma);
        f2d->detect(image, keypoints);
    }

    cv::Mat output;
    cv::drawKeypoints(image, keypoints, output);
    cv::imshow("keypoints", output);
    cv::waitKey(0);

    return 0;
}
