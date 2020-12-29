#pragma once
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <ctime>
#include <opencv2/opencv.hpp>


extern "C" __declspec(dllexport) int frameExchange(cv::Mat & src, cv::Mat & dct);