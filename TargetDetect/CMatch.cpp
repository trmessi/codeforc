// CMatch.cpp: 实现文件
//

#include "pch.h"
#include "TargetDetect.h"
#include "CMatch.h"
#include "afxdialogex.h"
#include "TargetDetectDlg.h"

CString Path1, Path2;

// CMatch 对话框

IMPLEMENT_DYNAMIC(CMatch, CDialog)

CMatch::CMatch(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MATCH, pParent)
{

}

CMatch::~CMatch()
{
}

void CMatch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_readimg1, C_ReadImg1);
	DDX_Control(pDX, IDC_readimg2, C_ReadImg2);
	DDX_Control(pDX, IDC_detectimg, C_DetectImg);
}


BEGIN_MESSAGE_MAP(CMatch, CDialog)
	ON_BN_CLICKED(IDC_readimg1, &CMatch::OnBnClickedreadimg1)
	ON_BN_CLICKED(IDC_readimg2, &CMatch::OnBnClickedreadimg2)
	ON_BN_CLICKED(IDC_detectimg, &CMatch::OnBnClickeddetectimg)
END_MESSAGE_MAP()


// CMatch 消息处理程序


BOOL CMatch::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	C_ReadImg2.EnableWindow(0);
	C_DetectImg.EnableWindow(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void ShowPicture(const cv::Mat& image, CWnd* pWnd)
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
		MessageBox(NULL, _T("图片错误！"),_T("错误"), MB_OK);
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


void CMatch::OnBnClickedreadimg1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString _picture_path;
	CWnd* pWnd = GetDlgItem(IDC_ShowImg1);
	//UpdateData（）中间的代码就是选取文件的
	UpdateData(TRUE);
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("(*.jpg)|*.jpg|"), this); //规定图片的类型是jpg
	if (dlg.DoModal() == IDOK)
	{
		_picture_path = dlg.GetPathName();//获取图片的路径
	}
	Path1 = _picture_path;//记录图片的路径
	C_ReadImg2.EnableWindow(1);
	UpdateData(FALSE);
	Mat image = imread(_picture_path.GetBuffer(0));
	ShowPicture(image, pWnd);
}


void CMatch::OnBnClickedreadimg2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString _picture_path;
	CWnd* pWnd = GetDlgItem(IDC_ShowImg2);
	//UpdateData（）中间的代码就是选取文件的
	UpdateData(TRUE);
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("(*.jpg)|*.jpg|"), this); //规定图片的类型是jpg
	if (dlg.DoModal() == IDOK)
	{
		_picture_path = dlg.GetPathName();
	}
	Path2 = _picture_path;
	C_DetectImg.EnableWindow(1);
	UpdateData(FALSE);
	Mat image = imread(_picture_path.GetBuffer(0));
	ShowPicture(image, pWnd);
}


void CMatch::OnBnClickeddetectimg()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd* pWnd = GetDlgItem(IDC_ShowImg3);
	UpdateData(TRUE);
	string path1 = Path1.GetBuffer(0);
	string path2 = Path2.GetBuffer(0);
	Mat image1 = imread(path1);
	if (image1.empty())
	{
		cout << "Please try read picture again!" << endl;
		return;
	}
	cv::Rect rect(110, 45, 35, 45);
	cv::rectangle(image1, rect, cv::Scalar(0, 0, 255));
	cv::Mat imageROI1 = image1(rect);
	int minSat = 65;
	ColorHistogram hc;
	cv::Mat colorhist = hc.getHueHistogram(imageROI1, minSat);
	ContentFinder finder;
	finder.setHistogram(colorhist);
	finder.setThreshold(0.2f);
	cv::Mat hsv;
	cv::cvtColor(image1, hsv, CV_BGR2HSV);

	Mat image2 = imread(path2);
	if (image2.empty())
	{
		cout << "Please try read picture again!" << endl;
		return;
	}
	cv::cvtColor(image2, hsv, CV_BGR2HSV);
	int ch[1] = { 0 };
	finder.setThreshold(-0.1f);
	cv::rectangle(image2, rect, cv::Scalar(0, 0, 255));
	cv::Mat result1 = finder.find(hsv, 0.0f, 180.0f, ch);
	Rect rect1(87, 29, 35, 40);
	cv::TermCriteria criteria(cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS,
		10,
		1);
	cv::rectangle(image2, rect1, cv::Scalar(0, 255, 0));
	UpdateData(FALSE);
	ShowPicture(image2, pWnd);
}
