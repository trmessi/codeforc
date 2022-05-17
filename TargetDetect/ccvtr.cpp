// ccvtr.cpp: 实现文件
//

#include "pch.h"
#include "TargetDetect.h"
#include "afxdialogex.h"
#include "ccvtr.h"
#include "TargetDetectDlg.h"
#include<Python.h>
#include<winsock.h>
#include<stdlib.h>
#include<windows.h>
#include <iostream>
#include <shellapi.h>
#include <tchar.h>
#pragma comment(lib,"ws2_32.lib")
CString FileName12;


// ccvtr 对话框

IMPLEMENT_DYNAMIC(ccvtr, CDialog)

ccvtr::ccvtr(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CCVTR, pParent)
{

}

ccvtr::~ccvtr()
{
}

void ccvtr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, getpicturetr, C_Gettr);
}


BEGIN_MESSAGE_MAP(ccvtr, CDialog)
	ON_BN_CLICKED(readpicturetr, &ccvtr::OnBnClickedreadpicturetr)
	ON_BN_CLICKED(runtr, &ccvtr::OnBnClickedruntr)
	ON_BN_CLICKED(canceltr, &ccvtr::OnBnClickedcanceltr)
END_MESSAGE_MAP()


// ccvtr 消息处理程序
BOOL ccvtr::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	C_Gettr.EnableWindow(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void ccvtr::OnBnClickedreadpicturetr()
{
	UpdateData(TRUE);
	CString filter;
	CString filename;
	filter = "所有文件(*.avi,*.3gp,*.mp4,*.rm,*rmvb,*flash) | *.avi;*.3gp;*.mp4;*.rm;*.rmvb;*flash";//视频文件类型。
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter, NULL);
	if (dlg.DoModal() == IDOK)  //用户单击OK按钮中止对话框的返回值
	{
		filename = dlg.GetPathName();   //获取文件路径名 如D:\\1.jpg                                   
	}
	FileName12 = filename;
	VideoCapture capture(filename.GetBuffer(0));     // capture对象。
	if (!capture.isOpened())
	{
		cout << "erro" << endl;
		return;
	}
	MessageBox(_T("Read Vedio is successful!"), MB_OK);
	C_Gettr.EnableWindow(1);
	CWnd* pWnd1 = GetDlgItem(getpicturetr);
	VideoCapture capture1(FileName12.GetBuffer(0));     // capture对象。
	if (!capture.isOpened())
	{
		cout << "Read vedio id error" << endl;
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
}
BOOL OpenExeFile(LPCSTR mode, LPCSTR filename)
{
	SHELLEXECUTEINFO shell = { sizeof(shell) };
	shell.fMask = SEE_MASK_FLAG_DDEWAIT;
	shell.lpVerb = mode;
	shell.lpFile = filename;
	shell.nShow = SW_SHOWNORMAL;
	BOOL ret = ShellExecuteEx(&shell);
	return ret;
}
void ccvtr::OnBnClickedruntr()
{
	//WORD w_req = MAKEWORD(2, 2);//版本号
	//WSADATA wsadata;
	//SOCKET mysocket = socket(AF_INET, SOCK_STREAM, 0);
	//WSAStartup(w_req, &wsadata);
	//sockaddr_in server_addr;
	//server_addr.sin_family = AF_INET;
	//server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	//server_addr.sin_port = htons(9527);
	//connect(mysocket, (sockaddr*)&server_addr, sizeof(sockaddr_in));
	//int len;

	// TODO: 在此添加控件通知处理程序代码

	//ShellExecuteA(NULL, "open", "D:/TargetDetect/trpy/main.exe", NULL, "D:\TargetDetect\trpy", SW_SHOW);
	OpenExeFile("open", ".\\main.exe");//filename是const wchar_t*类型
}
void ccvtr::OnBnClickedcanceltr()
{
	// TODO: 在此添加控件通知处理程序代码
}
