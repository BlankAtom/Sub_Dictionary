#include "pch.h"
#include "user_proc.h"
#include "Rocael.h"

int frameExchange(cv::Mat& src, cv::Mat& dst) {

	std::cout << "Hello, user_proc" << std::endl;
	Rocael ro;
	return ro.grayWorld(src, dst);

		//return 1;
}
