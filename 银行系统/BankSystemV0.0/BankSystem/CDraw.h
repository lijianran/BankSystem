#pragma once


// CDraw 对话框

class CDraw : public CDialogEx
{
	DECLARE_DYNAMIC(CDraw)

public:
	CDraw(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDraw();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWMONEY };
#endif
protected:
	CString m_account;
	CString m_password;
	CString m_money;

public:
	CString GetNumber() { return m_account; }
	CString GetPassword() { return m_password; }
	int GetMoney() { return _ttoi(m_money); }

protected:
	bool CheckBox();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonCancle();
	afx_msg void OnEnChangeEditAccount();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnEnChangeEditMoney();
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
