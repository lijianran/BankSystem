#pragma once

#include "CSelFont.h"

// CSearch 对话框

class CSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSearch();

protected:
	bool m_money;
	bool m_info;
	CBrush m_bkBrush;
	int xpos, ypos;

public:
	bool IsMoney() { return m_money; }
	bool IsInfo() { return m_info; }
	void SetWndPos(int x, int y);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearchmoney();
	afx_msg void OnBnClickedButtonSearchinfo();
	afx_msg void OnBnClickedButtonCancle();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
