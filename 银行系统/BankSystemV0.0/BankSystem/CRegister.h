#pragma once


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
public:
	UserData GetData();
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
};
