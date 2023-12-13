
// Pro2Dlg.h: 头文件
//

#include<cmath>
#include<vector>

#pragma once

extern CString CString_L, CString_L1, CString_P, CString_X, CString_N1, CString_N2, CString_M1, CString_M2, CString_M;
extern double double_L, double_L1, double_P, double_X, double_N1, double_N2, double_M1, double_M2, double_M;

// CPro2Dlg 对话框
class CPro2Dlg : public CDialogEx
{
// 构造
public:
	CPro2Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRO2_DIALOG };
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
	afx_msg void OnBnClickedOk();
	afx_msg void calculate();
	afx_msg void DrawMomentPoint(double double_X, double double_M);
	CEdit IDC_EDIT5_CString;
	CEdit IDC_EDIT6_CString;
	CEdit IDC_EDIT7_CString;
	CEdit IDC_EDIT8_CString;
	CSliderCtrl IDC_SLIDER1_CString;
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	void OnSliderMoved(); // 你希望在滑块移动后调用的函数
	CEdit IDC_EDIT4_CString;
	CStatic m_plotArea;
	CButton IDD_IDCANCEL_DIALOG;
	std::vector<CPoint> m_Points;
};


static double calculate_N1(double L, double L1, double P, double X);
static double calculate_N2(double P, double N1);
static double calculate_M1(double N1, double X);
static double calculate_M2(double N2, double L, double X, double L1);