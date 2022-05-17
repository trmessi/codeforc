#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
using namespace std;
using namespace cv;
class ColorHistogram//彩色图像
{
private:
	int histSize[3];  //每个维度的大小
	float hranges[2]; //值得范围（三个维度用同一个值）
	const float* ranges[3];//每个维度的范围
	int channels[3];//需要处理的通道
public:
	ColorHistogram()
	{
		//准备用于彩色图像的默认参数
		//每个维度的大小和范围是相等的
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;//BGR范围为0~256
		hranges[1] = 256.0;
		ranges[0] = hranges;//这个类中
		ranges[1] = hranges;//所有通道的范围都相等
		ranges[2] = hranges;
		channels[0] = 0; //三个通道：B
		channels[1] = 1; //G
		channels[2] = 2; //R
	}

	void setSize(int size)
	{
		histSize[0] = histSize[1] = histSize[2] = size;
	}
	//计算直方图
	cv::Mat getHistogram(const cv::Mat& image)
	{
		cv::Mat hist;
		cv::calcHist(&image, 1,//单幅图像的直方图
			channels,//用到的通道
			cv::Mat(), //不使用的掩码
			hist, //得到的直方图
			3, //这是一个三维直方图
			histSize,//箱子数量 
			ranges);//像素值的范围
		return hist;
	}
	//计算直方图
	cv::SparseMat getSparseHistogram(const cv::Mat& image)
	{
		cv::SparseMat hist(3,//维数
			histSize, //每个维度的大小 
			CV_32F);
		cv::calcHist(&image, 1,//单幅图像的直方图
			channels, //用到的通道
			cv::Mat(), //不使用掩码
			hist, //得到的直方图
			3, //这是三维直方图
			histSize, //箱子数量
			ranges);//像素值的范围
		return hist;
	}

	cv::Mat getHueHistogram(const cv::Mat& image, int minSaturation = 0)
	{
		cv::Mat hist;
		cv::Mat hsv;
		cv::cvtColor(image, hsv, CV_BGR2HSV);
		cv::Mat mask;
		if (minSaturation > 0)
		{
			std::vector<cv::Mat>v;
			cv::split(hsv, v);
			cv::threshold(v[1], mask, minSaturation, 255, cv::THRESH_BINARY);
		}

		hranges[0] = 0.0;
		hranges[1] = 180.0;
		channels[0] = 0;

		cv::calcHist(&hsv, 1,
			channels,
			mask,
			hist,
			1,
			histSize,
			ranges);
		return hist;
	}
};