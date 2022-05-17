// CTail.cpp: 实现文件
//

#include "pch.h"
#include "TargetDetect.h"
#include "CTail.h"
#include "afxdialogex.h"
#include "TargetDetectDlg.h"
CString FileName;


// CTail 对话框

IMPLEMENT_DYNAMIC(CTail, CDialog)

CTail::CTail(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TAIL, pParent)
{

}

CTail::~CTail()
{
}

void CTail::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_tail, C_GetTail);
}


BEGIN_MESSAGE_MAP(CTail, CDialog)
	ON_BN_CLICKED(IDC_readvideo1, &CTail::OnBnClickedreadvideo1)
	ON_BN_CLICKED(IDC_tail, &CTail::OnBnClickedtail)
END_MESSAGE_MAP()


// CTail 消息处理程序


BOOL CTail::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	C_GetTail.EnableWindow(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void ShowPic1(const cv::Mat& image, CWnd* pWnd)
{
	BITMAPINFO* pBmpInfo1;
	if (image.channels() == 1)
	{
		pBmpInfo1 = (BITMAPINFO*)new char[sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD)];
		pBmpInfo1->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		pBmpInfo1->bmiHeader.biWidth = image.cols;//src_rec.Width();
		pBmpInfo1->bmiHeader.biHeight = -image.rows; //-src_rec.Height();//为负值
		pBmpInfo1->bmiHeader.biPlanes = 1;
		pBmpInfo1->bmiHeader.biBitCount = 8;//八位
		pBmpInfo1->bmiHeader.biCompression = BI_RGB;
		pBmpInfo1->bmiHeader.biSizeImage = 0;
		pBmpInfo1->bmiHeader.biXPelsPerMeter = 0;
		pBmpInfo1->bmiHeader.biYPelsPerMeter = 0;
		pBmpInfo1->bmiHeader.biClrUsed = 0;
		pBmpInfo1->bmiHeader.biClrImportant = 0;

		for (int i = 0; i < 256; i++)//只有灰度图像需要颜色表
		{
			pBmpInfo1->bmiColors[i].rgbBlue = pBmpInfo1->bmiColors[i].rgbGreen = pBmpInfo1->bmiColors[i].rgbRed = (BYTE)i;
			pBmpInfo1->bmiColors[i].rgbReserved = 0;
		}
	}
	else if (image.channels() == 3)
	{
		pBmpInfo1 = (BITMAPINFO*) new char[sizeof(BITMAPINFOHEADER)];
		pBmpInfo1->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		pBmpInfo1->bmiHeader.biWidth = image.cols;//src_rec.Width();
		pBmpInfo1->bmiHeader.biHeight = -image.rows; //-src_rec.Height();//为负值
		pBmpInfo1->bmiHeader.biPlanes = 1;
		pBmpInfo1->bmiHeader.biBitCount = 24;//24位
		pBmpInfo1->bmiHeader.biCompression = BI_RGB;
		pBmpInfo1->bmiHeader.biSizeImage = 0;
		pBmpInfo1->bmiHeader.biXPelsPerMeter = 0;
		pBmpInfo1->bmiHeader.biYPelsPerMeter = 0;
		pBmpInfo1->bmiHeader.biClrUsed = 0;
		pBmpInfo1->bmiHeader.biClrImportant = 0;
	}
	else
	{
		MessageBox(NULL, _T("图片错误！"), _T("错误"), MB_OK);
		return;
	}
	HDC h_dc = pWnd->GetDC()->GetSafeHdc();
	CRect BoxSize;
	pWnd->GetClientRect(&BoxSize);
	SetStretchBltMode(h_dc, HALFTONE);

	float cx, cy, dx, dy, k, t;//跟控件的宽和高以及图片宽和高有关的参数
	cx = image.cols;
	cy = image.rows;//获取图片的宽 高
	k = cy / cx;//获得图片的宽高比

	dx = BoxSize.Width();
	dy = BoxSize.Height();//获得控件的宽高比
	t = dy / dx;//获得控件的宽高比

	if (k >= t)
	{

		BoxSize.right = floor(BoxSize.bottom / k);
		BoxSize.left = (dx - BoxSize.right) / 2;
		BoxSize.right = floor(BoxSize.bottom / k) + (dx - BoxSize.right) / 2;
	}
	else
	{
		BoxSize.bottom = floor(k * BoxSize.right);
		BoxSize.top = (dy - BoxSize.bottom) / 2;
		BoxSize.bottom = floor(k * BoxSize.right) + (dy - BoxSize.bottom) / 2;
	}
	int jj = StretchDIBits(h_dc, BoxSize.left, BoxSize.top, BoxSize.Width(), BoxSize.Height(), 0, 0, image.cols, image.rows, (void*)image.data,
		(BITMAPINFO*)pBmpInfo1, DIB_RGB_COLORS, SRCCOPY);
	delete[]pBmpInfo1;
	return;
}

void ShowVideo1( cv::VideoCapture& vedio,CWnd* pWnd1,CWnd* pWnd2)
{
	Mat frame;
	Mat foreground;	// 前景图片
	cv::BackgroundSubtractorMOG mog;
	bool stop(false);
	while (!stop)
	{
		if (!vedio.read(frame))
		{
			break;
		}
		// 更新背景图片并且输出前景
		mog(frame, foreground, 0.01);
		// 输出的前景图片并不是2值图片，要处理一下显示  
		threshold(foreground, foreground, 128, 255, THRESH_BINARY_INV);
		// show foreground
		ShowPic1(foreground,pWnd2);
		ShowPic1(frame,pWnd1);
		if (waitKey(10) == 27)
		{
			stop = true;
		}
	}
}

void CTail::OnBnClickedreadvideo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString filter;
	CString filename;
	filter = "所有文件(*.avi,*.3gp,*.mp4,*.rm,*rmvb,*flash) | *.avi;*.3gp;*.mp4;*.rm;*.rmvb;*flash";//视频文件类型。
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter, NULL);
	if (dlg.DoModal() == IDOK)  //用户单击OK按钮中止对话框的返回值
	{
		filename = dlg.GetPathName();   //获取文件路径名 如D:\\1.jpg                                   
	}
	FileName = filename;
	VideoCapture capture(filename.GetBuffer(0));     // capture对象。
	if (!capture.isOpened())
	{
		cout << "erro" << endl;
		return;
	}
	MessageBox(_T("Read Vedio is successful!"), MB_OK);
	C_GetTail.EnableWindow(1);
	UpdateData(FALSE);
}


void CTail::OnBnClickedtail()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CWnd* pWnd1 = GetDlgItem(IDC_ShowImg4);
	CWnd* pWnd2 = GetDlgItem(IDC_ShowImg5);
	VideoCapture capture(FileName.GetBuffer(0));     // capture对象。
	if (!capture.isOpened())
	{
		cout << "Read vedio id error" << endl;
		return;
	}
	UpdateData(FALSE);
	ShowVideo1(capture, pWnd1, pWnd2);
}
