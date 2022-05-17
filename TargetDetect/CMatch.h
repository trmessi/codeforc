#pragma once


// CMatch 对话框

class CMatch : public CDialog
{
	DECLARE_DYNAMIC(CMatch)

public:
	CMatch(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMatch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MATCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton C_ReadImg1;
	CButton C_ReadImg2;
	CButton C_DetectImg;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedreadimg1();
	afx_msg void OnBnClickedreadimg2();
	afx_msg void OnBnClickeddetectimg();
};


