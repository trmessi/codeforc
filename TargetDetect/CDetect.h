#pragma once


// CDetect 对话框

class CDetect : public CDialog
{
	DECLARE_DYNAMIC(CDetect)

public:
	CDetect(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDetect();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DETECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton C_GetDetect;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedreadvideo2();
	afx_msg void OnBnClickedgetdetect();
};
