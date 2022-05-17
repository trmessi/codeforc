#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
using namespace std;
using namespace cv;
class ContentFinder
{
private:
	float hranges[2];
	const float* ranges[3];
	int channels[3];
	float threshold;
	cv::Mat histogram;
public:
	ContentFinder() :threshold(0.1f)
	{
		ranges[0] = hranges;
		ranges[1] = hranges;
		ranges[2] = hranges;
	}

	void setThreshold(float t)
	{
		threshold = t;
	}

	void setHistogram(const cv::Mat& image)
	{
		cv::normalize(image, histogram, 1.0);
	}

	cv::Mat find(const cv::Mat& image)
	{
		cv::Mat reslut;
		hranges[0] = 0.0;
		hranges[1] = 256.0;
		channels[0] = 0;
		channels[1] = 1;
		channels[2] = 2;
		return find(image, hranges[0], hranges[1], channels);
	}
	cv::Mat find(const cv::Mat& image, float minValue, float maxValue, int* channels)
	{

		cv::Mat result;
		hranges[0] = minValue;
		hranges[1] = maxValue;
		for (int i = 0; i < histogram.dims; i++)
		{
			this->channels[i] = channels[i];
		}
		cv::calcBackProject(&image,
			1,
			channels,
			histogram,
			result,
			ranges,
			255.0
		);
		if (threshold > 0.0)
		{
			cv::threshold(result, result, 255.0 * threshold, 255, cv::THRESH_BINARY);
		}

		return result;
	}
};