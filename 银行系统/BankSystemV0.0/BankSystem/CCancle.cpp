// CCancle.cpp: 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "CCancle.h"
#include "afxdialogex.h"


// CCancle 对话框

IMPLEMENT_DYNAMIC(CCancle, CDialogEx)

CCancle::CCancle(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CANCLE, pParent)
{

}

CCancle::~CCancle()
{
}

bool CCancle::CheckBox()
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

void CCancle::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCancle, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCancle::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCancle::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT_NUMBER, &CCancle::OnEnChangeEditNumber)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CCancle::OnEnChangeEditPassword)
END_MESSAGE_MAP()


// CCancle 消息处理程序


void CCancle::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (CheckBox())
	{
		CString message = _T("确定将账户 ") + m_account + _T(" 注销吗？");
		if ((::MessageBox(this->m_hWnd, message, _T("警告"), MB_OKCANCEL)) == IDOK)
			CDialogEx::OnOK();
	}
}


void CCancle::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if ((::MessageBox(this->m_hWnd, _T("确定取消本次销户操作吗？"), _T("警告"), MB_OKCANCEL)) == IDOK)
		CDialogEx::OnCancel();
}


void CCancle::OnEnChangeEditNumber()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_NUMBER, m_account);

}


void CCancle::OnEnChangeEditPassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_PASSWORD, m_password);

}


BOOL CCancle::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		OnBnClickedCancel();
		return FALSE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return FALSE;
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}
