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
#include "CSelFont.h"
#include "CSelfButton.h"

// CMainMenu 对话框

class CMainMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CMainMenu)

public:
	CMainMenu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainMenu();

protected:
	COperator m_handle;
	bool m_visuable;

protected:
	CBrush m_bkBrush;
	CDC m_dcBmp;   //定义并创建一个内存设备环境
	CBitmap m_bmpBackground;

	int m_minWidth;
	int m_minHeight;
	int m_oldWidth;   //窗口的宽x
	int m_oldHeight;  //窗口的高y
	double m_x;
	double m_y;
	int m_childposx; //子窗口x
	int m_childposy; //子窗口y
public:
	bool IsVisuable();

protected:
	bool CheckErrors_Print(int Operators);
	bool PrintSrearchInfo(list<UserData> datas);

protected:
	CSelfButton m_RegisterButton;
	CSelfButton m_SaveButton;
	CSelfButton m_DrawButoon;
	CSelfButton m_SearchButton;
	CSelfButton m_TransferButton;
	CSelfButton m_CancleButton;
	CSelfButton m_BackButton;


// 对话框数据
	enum { IDD = IDD_MAINMENU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRegister();
	afx_msg void OnBnClickedButtonCancle();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonDraw();
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonTransfer();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);

protected:
	CSelFont m_Static_Name;
	CSelFont m_Static_Email;
	CSelFont m_Static_qq;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
protected:
	CSelFont m_Static_Mainmenu;
};
