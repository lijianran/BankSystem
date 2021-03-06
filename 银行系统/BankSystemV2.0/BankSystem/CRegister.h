#pragma once

#include "CSelFont.h"

// CRegister 对话框

class CRegister : public CDialogEx
{
	DECLARE_DYNAMIC(CRegister)

public:
	CRegister(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CRegister();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

protected:
	UserData m_data;
	CBrush m_bkBrush;
	CFont *m_EditFont;
	CDC m_dcBmp;   //定义并创建一个内存设备环境
	CBitmap m_bmpBackground;
	int xpos, ypos;
	double m_x, m_y;
public:
	UserData GetData();
	void SetWndPos(int x, int y, double dx, double dy);
protected:
	bool CheckBox();

public:
	afx_msg void OnBnClickedOK();
	afx_msg void OnBnClickedCancle();
	afx_msg void OnEnChangeName();
	afx_msg void OnEnChangeId();
	afx_msg void OnEnChangePhone();
	afx_msg void OnEnChangeAddress();
	afx_msg void OnEnChangePassword();
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	CSelFont m_Static_Name;
	CSelFont m_Static_ID;
	CSelFont m_Sataic_Phone;
	CSelFont m_Sataic_Address;
	CSelFont m_Sataic_Password;
public:
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
