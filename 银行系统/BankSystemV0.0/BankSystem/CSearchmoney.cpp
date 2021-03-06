// CSearchmoney.cpp: 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "CSearchmoney.h"
#include "afxdialogex.h"


// CSearchmoney 对话框

IMPLEMENT_DYNAMIC(CSearchmoney, CDialogEx)

CSearchmoney::CSearchmoney(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCHMONEY, pParent)
{

}

CSearchmoney::~CSearchmoney()
{
}

bool CSearchmoney::CheckBox()
{
	bool flag = true;
	if (m_account[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("账户不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_password[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("密码不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	return flag;
}

void CSearchmoney::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSearchmoney, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CSearchmoney::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CSearchmoney::OnBnClickedButtonCancle)
	ON_EN_CHANGE(IDC_EDIT_ACCOUNT, &CSearchmoney::OnEnChangeEditAccount)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CSearchmoney::OnEnChangeEditPassword)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CSearchmoney 消息处理程序


void CSearchmoney::OnBnClickedButtonSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	if (CheckBox())
		CDialogEx::OnOK();

}


void CSearchmoney::OnBnClickedButtonCancle()
{
	// TODO: 在此添加控件通知处理程序代码
	if ((::MessageBox(this->m_hWnd, _T("确定取消查询操作吗？"), _T("警告"), MB_OKCANCEL)) == IDOK)
		CDialogEx::OnCancel();

}


void CSearchmoney::OnEnChangeEditAccount()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_ACCOUNT, m_account);

}


void CSearchmoney::OnEnChangeEditPassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_PASSWORD, m_password);

}


void CSearchmoney::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	OnBnClickedButtonCancle();
	//CDialogEx::OnClose();
}


BOOL CSearchmoney::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		OnBnClickedButtonCancle();
		return FALSE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return FALSE;
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}
