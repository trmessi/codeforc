#pragma once


// CTail 对话框

class CTail : public CDialog
{
	DECLARE_DYNAMIC(CTail)

public:
	CTail(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTail();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAIL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton C_GetTail;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedreadvideo1();
	afx_msg void OnBnClickedtail();
};
