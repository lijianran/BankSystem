#pragma once


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

public:
	CString GetSelfNum() { return m_selfnum; }
	CString GetPassword() { return m_password; }
	CString GetGoalNum() { return m_goalnum; }
	int GetMoney() { return _ttoi(m_money); }

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
};
