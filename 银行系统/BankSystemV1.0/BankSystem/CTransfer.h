#pragma once

#include "CSelFont.h"

// CTransfer 对话框

class CTransfer : public CDialogEx
{
	DECLARE_DYNAMIC(CTransfer)

public:
	CTransfer(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTransfer();
protected:
	CString m_selfnum;
	CString m_password;
	CString m_goalnum;
	CString m_money;
	CBrush m_bkBrush;
	CFont *m_EditFont;
	int xpos, ypos;

public:
	CString GetSelfNum() { return m_selfnum; }
	CString GetPassword() { return m_password; }
	CString GetGoalNum() { return m_goalnum; }
	int GetMoney() { return _ttoi(m_money); }
	void SetWndPos(int x, int y);

protected:
	bool CheckBox();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRANSFER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEditSelf();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnEnChangeEditGoal();
	afx_msg void OnEnChangeEditMoney();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	CSelFont m_Static_Account;
public:
	afx_msg void OnStnClickedStaticPassword();
protected:
	CSelFont m_Static_Password;
	CSelFont m_Static_Acconto;
	CSelFont m_Static_Money;
};
