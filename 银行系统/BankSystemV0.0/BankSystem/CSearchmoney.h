#pragma once


// CSearchmoney 对话框

class CSearchmoney : public CDialogEx
{
	DECLARE_DYNAMIC(CSearchmoney)

public:
	CSearchmoney(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSearchmoney();
protected:
	CString m_account;
	CString m_password;

public:
	CString GetNumber() { return m_account; }
	CString GetPassword() { return m_password; }

protected:
	bool CheckBox();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCHMONEY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedButtonCancle();
	afx_msg void OnEnChangeEditAccount();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
