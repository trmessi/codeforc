#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
using namespace std;
using namespace cv;
class ColorHistogram//��ɫͼ��
{
private:
	int histSize[3];  //ÿ��ά�ȵĴ�С
	float hranges[2]; //ֵ�÷�Χ������ά����ͬһ��ֵ��
	const float* ranges[3];//ÿ��ά�ȵķ�Χ
	int channels[3];//��Ҫ�����ͨ��
public:
	ColorHistogram()
	{
		//׼�����ڲ�ɫͼ���Ĭ�ϲ���
		//ÿ��ά�ȵĴ�С�ͷ�Χ����ȵ�
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;//BGR��ΧΪ0~256
		hranges[1] = 256.0;
		ranges[0] = hranges;//�������
		ranges[1] = hranges;//����ͨ���ķ�Χ�����
		ranges[2] = hranges;
		channels[0] = 0; //����ͨ����B
		channels[1] = 1; //G
		channels[2] = 2; //R
	}

	void setSize(int size)
	{
		histSize[0] = histSize[1] = histSize[2] = size;
	}
	//����ֱ��ͼ
	cv::Mat getHistogram(const cv::Mat& image)
	{
		cv::Mat hist;
		cv::calcHist(&image, 1,//����ͼ���ֱ��ͼ
			channels,//�õ���ͨ��
			cv::Mat(), //��ʹ�õ�����
			hist, //�õ���ֱ��ͼ
			3, //����һ����άֱ��ͼ
			histSize,//�������� 
			ranges);//����ֵ�ķ�Χ
		return hist;
	}
	//����ֱ��ͼ
	cv::SparseMat getSparseHistogram(const cv::Mat& image)
	{
		cv::SparseMat hist(3,//ά��
			histSize, //ÿ��ά�ȵĴ�С 
			CV_32F);
		cv::calcHist(&image, 1,//����ͼ���ֱ��ͼ
			channels, //�õ���ͨ��
			cv::Mat(), //��ʹ������
			hist, //�õ���ֱ��ͼ
			3, //������άֱ��ͼ
			histSize, //��������
			ranges);//����ֵ�ķ�Χ
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