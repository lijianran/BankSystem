#pragma once

#include "CSelFont.h"

// CCancle 对话框

class CCancle : public CDialogEx
{
	DECLARE_DYNAMIC(CCancle)

public:
	CCancle(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCancle();

protected:
	CString m_account;
	CString m_password;
	CBrush m_bkBrush;
	CFont *m_EditFont;
	int xpos, ypos;

public:
	CString GetNumber() { return m_account; }
	CString GetPassword() { return m_password; }
	void SetWndPos(int x, int y);

protected:
	bool CheckBox();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CANCLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEditNumber();
	afx_msg void OnEnChangeEditPassword();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	CSelFont m_Static_Account;
	CSelFont m_Static_Password;
};
