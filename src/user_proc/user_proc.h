#pragma once

#include <opencv2/opencv.hpp>

extern "C" __declspec(dllexport) int frameExchange(cv::Mat & src, cv::Mat & dct);
extern "C" __declspec(dllexport) int frameExchange_second(cv::Mat & src, cv::Mat & dst);
extern "C" __declspec(dllexport) int frameExchange_third(cv::Mat & src, cv::Mat & dst);
extern "C" __declspec(dllexport) int frameExchange_forth(cv::Mat & src, cv::Mat & dst);
