#include "pch.h"
#include "user_proc.h"
#include "Rocael.h"

int frameExchange(cv::Mat& src, cv::Mat& dst) {

	//std::cout << "Hello, user_proc" << std::endl;
	Rocael ro;
	return ro.grayWorld(src, dst);

		//return 1;
}

int frameExchange_second(cv::Mat& src, cv::Mat& dst) {
	Rocael ro;
	return ro.testFunc(src, dst);
}

int frameExchange_third(cv::Mat& src, cv::Mat& dst)
{
	Rocael ro;
	return ro.testFunc2(src, dst);
}

int frameExchange_forth(cv::Mat& src, cv::Mat& dst)
{
	Rocael ro;
	return ro.testFunc3(src, dst);
}
