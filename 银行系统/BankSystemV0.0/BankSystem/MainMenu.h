#pragma once
#include "Operator.h"
#include "CRegister.h"
#include "CCancle.h"
#include "CSearch.h"
#include "CSearchmoney.h"
#include "CSearchinfo.h"
#include "CSave.h"
#include "CDraw.h"
#include "CTransfer.h"

// CMainMenu �Ի���

class CMainMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CMainMenu)

public:
	CMainMenu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainMenu();

protected:
	COperator m_handle;
	bool m_visuable;

public:
	bool IsVisuable();

protected:
	bool CheckErrors_Print(int Operators);
	bool PrintSrearchInfo(list<UserData> datas);

// �Ի�������
	enum { IDD = IDD_MAINMENU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRegister();
	afx_msg void OnBnClickedButtonCancle();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonDraw();
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedTransfer();
};
