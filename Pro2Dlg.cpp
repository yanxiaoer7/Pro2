
// Pro2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Pro2.h"
#include "Pro2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString CString_L, CString_L1, CString_P, CString_X, CString_N1, CString_N2, CString_M1, CString_M2, CString_M;
double double_L, double_L1, double_P, double_X, double_N1, double_N2, double_M1, double_M2, double_M;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPro2Dlg 对话框



CPro2Dlg::CPro2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRO2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPro2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT5, IDC_EDIT5_CString);
	DDX_Control(pDX, IDC_EDIT6, IDC_EDIT6_CString);
	DDX_Control(pDX, IDC_EDIT7, IDC_EDIT7_CString);
	DDX_Control(pDX, IDC_EDIT8, IDC_EDIT8_CString);
	DDX_Control(pDX, IDC_SLIDER1, IDC_SLIDER1_CString);
	DDX_Control(pDX, IDC_EDIT4, IDC_EDIT4_CString);
	DDX_Control(pDX, IDCANCEL, IDD_IDCANCEL_DIALOG);
}

BEGIN_MESSAGE_MAP(CPro2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDOK, &CPro2Dlg::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CPro2Dlg::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// CPro2Dlg 消息处理程序

BOOL CPro2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	IDC_SLIDER1_CString.SetRange(0, 3000);  // 设置滑动条的最小和最大值
	IDC_SLIDER1_CString.SetPos(1000);          // 设置滑动条的初始位置


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPro2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。


void CPro2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPro2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPro2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	calculate();


}


void CPro2Dlg::calculate() {
	GetDlgItemText(IDC_EDIT1, CString_L);
	GetDlgItemText(IDC_EDIT2, CString_L1);
	GetDlgItemText(IDC_EDIT3, CString_P);
	GetDlgItemText(IDC_EDIT4, CString_X);

	double_L = _ttof(CString_L);
	double_L1 = _ttof(CString_L1);
	double_P = _ttof(CString_P);
	double_X = _ttof(CString_X);

	double_N1 = calculate_N1(double_L, double_L1, double_P, double_X);
	double_N2 = calculate_N2(double_P, double_N1);
	double_M1 = calculate_M1(double_N1, double_X);
	double_M2 = calculate_M2(double_N2, double_L, double_X, double_L1);
	double_M = min(double_M1, double_M2);

	CString_N1.Format(_T("%lf"), double_N1);
	CString_N2.Format(_T("%lf"), double_N2);
	CString_M1.Format(_T("%lf"), double_M1);;
	CString_M2.Format(_T("%lf"), double_M2);

	IDC_EDIT5_CString.SetWindowText(CString_N1);
	IDC_EDIT6_CString.SetWindowText(CString_N2);
	IDC_EDIT7_CString.SetWindowText(CString_M1);
	IDC_EDIT8_CString.SetWindowText(CString_M2);

	DrawMomentPoint(double_X, double_M);
}

double calculate_N1(double L, double L1, double P, double X) {
	return 0.5 * P * (L - X) / L + 0.5 * P * (L - X - L1) / L;
}
double calculate_N2(double P, double N1) {
	return P - N1;
}
double calculate_M1(double N1, double X) {
	return N1 * X;
}
double calculate_M2(double N2, double L, double X, double L1) {
	return N2 * (L - X - L1);
}

void CPro2Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CPro2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// 检查是否是你的滑块控件发出的消息
	if (pScrollBar != NULL && pScrollBar->GetDlgCtrlID() == IDC_SLIDER1)
	{
		// 调用你希望在滑块移动后执行的函数
		OnSliderMoved();
	}
	// 调用基类版本的OnHScroll来确保消息被正确处理
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CPro2Dlg::OnSliderMoved()
{
	// 滑块移动后希望执行的代码
	int nPos = IDC_SLIDER1_CString.GetPos(); // 获取滑动条当前位置
	// ... 根据滑块位置更新数据和UI ...
	double_X = nPos / 100.0;
	CString_X.Format(_T("%lf"), double_X);
	IDC_EDIT4_CString.SetWindowText(CString_X);
	calculate();
}

void CPro2Dlg::DrawMomentPoint(double double_X, double double_M)
{
	const int controlWidth = 360;  // 控件宽度
	const int controlHeight = 120; // 控件高度
	const double maxX = 30.0;      // double_X的最大值
	const double maxY = 4000.0;    // double_M的最大值
	const int pointSize = 2;       // 点的大小（半径）

	if (double_M >= 0)
	{
		// 转换点为屏幕坐标
		int screenX = static_cast<int>((double_X / maxX) * controlWidth);
		int screenY = static_cast<int>((double_M / maxY) * controlHeight);
		m_Points.push_back(CPoint(screenX, controlHeight - screenY));
	}

	CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC);
	if (pStatic == nullptr) return;

	CDC* pDC = pStatic->GetDC();
	CRect rect;
	pStatic->GetClientRect(&rect);

	pDC->FillSolidRect(rect, RGB(255, 255, 255));

	for (const auto& point : m_Points)
	{
		// 绘制一个小圆形作为点
		pDC->Ellipse(point.x - pointSize, point.y - pointSize,
			point.x + pointSize, point.y + pointSize);
	}

	ReleaseDC(pDC);
}













