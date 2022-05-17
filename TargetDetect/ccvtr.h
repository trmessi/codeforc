#pragma once
#include "afxdialogex.h"


// ccvtr 对话框

class ccvtr : public CDialog
{
	DECLARE_DYNAMIC(ccvtr)

public:
	ccvtr(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ccvtr();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CCVTR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton C_Gettr;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedreadpicturetr();
	afx_msg void OnBnClickedruntr();
	afx_msg void OnBnClickedcanceltr();
};
