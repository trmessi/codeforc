#include<iostream>
#include<opencv2/opencv.hpp>
#include "ColorHistogram.h"
#include "ContentFinder.h"
#include <opencv2/video/tracking.hpp>
#include <opencv2/ocl/ocl.hpp>
using namespace std;
using namespace cv;
// TargetDetectDlg.h: 头文件
//

#pragma once


// CTargetDetectDlg 对话框
class CTargetDetectDlg : public CDialogEx
{
// 构造
public:
	CTargetDetectDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TARGETDETECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedmatch();
	afx_msg void OnBnClickedtail();
	afx_msg void OnBnClickeddetect();
	afx_msg void OnBnClickedgotr();
};
