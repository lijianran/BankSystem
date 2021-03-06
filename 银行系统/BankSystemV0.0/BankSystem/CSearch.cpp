// CSearch.cpp: 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "CSearch.h"
#include "afxdialogex.h"


// CSearch 对话框

IMPLEMENT_DYNAMIC(CSearch, CDialogEx)

CSearch::CSearch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCH, pParent)
{
	m_money = false;
	m_info = false;
}

CSearch::~CSearch()
{
}

void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSearch, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHMONEY, &CSearch::OnBnClickedButtonSearchmoney)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHINFO, &CSearch::OnBnClickedButtonSearchinfo)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CSearch::OnBnClickedButtonCancle)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CSearch 消息处理程序


void CSearch::OnBnClickedButtonSearchmoney()
{
	// TODO: 在此添加控件通知处理程序代码
	m_money = true;
	CDialogEx::OnOK();
}


void CSearch::OnBnClickedButtonSearchinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	m_info = true;
	CDialogEx::OnOK();
}


void CSearch::OnBnClickedButtonCancle()
{
	// TODO: 在此添加控件通知处理程序代码
	if ((::MessageBox(this->m_hWnd, _T("确定取消查询操作？"), _T("警告"), MB_OKCANCEL)) == IDOK)
		CDialogEx::OnCancel();

}


void CSearch::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	OnBnClickedButtonCancle();
	//CDialogEx::OnClose();
}
