#pragma once

#include "CSelFont.h"

// CSearchinfo 对话框

class CSearchinfo : public CDialogEx
{
	DECLARE_DYNAMIC(CSearchinfo)

public:
	CSearchinfo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSearchinfo();

protected:
	CString m_name;
	CString m_id;
	CFont *m_EditFont;
	CDC m_dcBmp;   //定义并创建一个内存设备环境
	CBitmap m_bmpBackground;
	int xpos, ypos;
	double m_x, m_y;

protected:
	bool CheckBox();

public:
	CString GetName() { return m_name; }
	CString GetId() { return m_id; }
	void SetWndPos(int x, int y, double dx, double dy);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCHINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedButtonCancle();
	afx_msg void OnEnChangeEditName();
	afx_msg void OnEnChangeEditId();
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	CSelFont m_Static_Name;
	CSelFont m_Static_ID;
public:
	afx_msg void OnPaint();
};
