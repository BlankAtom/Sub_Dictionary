#pragma once

#include <opencv2/opencv.hpp>

extern "C" __declspec(dllexport) int frameExchange(cv::Mat & src, cv::Mat & dct);

