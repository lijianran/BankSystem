// CTransfer.cpp: 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "CTransfer.h"
#include "afxdialogex.h"


// CTransfer 对话框

IMPLEMENT_DYNAMIC(CTransfer, CDialogEx)

CTransfer::CTransfer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRANSFER, pParent)
{

}

CTransfer::~CTransfer()
{
}

bool CTransfer::CheckBox()
{
	bool flag = true;
	if (m_selfnum[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("您的账户不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_password[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("密码不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_goalnum[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("转账账户不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_money[0] != '\0')
	{
		for (int j = 0; j < m_money.GetLength(); j++)
		{
			if (m_money[j] < 48 || m_money[j] > 57)
			{
				::MessageBox(this->m_hWnd, _T("请输入正确金额！"), _T("警告"), MB_OK);
				return false;
			}
		}
		int i;
		i = _ttoi(m_money);
		if (i > 1000000)
		{
			::MessageBox(this->m_hWnd, _T("一次转账不能超过百万万元！"), _T("警告"), MB_OK);
			flag = false;
		}
	}
	else
	{
		::MessageBox(this->m_hWnd, _T("请输入转账金额！"), _T("警告"), MB_OK);
		flag = false;
	}
	return flag;
}

void CTransfer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTransfer, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTransfer::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTransfer::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT_SELF, &CTransfer::OnEnChangeEditSelf)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CTransfer::OnEnChangeEditPassword)
	ON_EN_CHANGE(IDC_EDIT_GOAL, &CTransfer::OnEnChangeEditGoal)
	ON_EN_CHANGE(IDC_EDIT_MONEY, &CTransfer::OnEnChangeEditMoney)
END_MESSAGE_MAP()


// CTransfer 消息处理程序


void CTransfer::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (CheckBox())
	{
		CString message = _T("确定转账") + m_money + _T("元到账户 ") + m_goalnum + _T(" 中？");
		if ((::MessageBox(this->m_hWnd, message, _T("警告"), MB_OKCANCEL)) == IDOK)
			CDialogEx::OnOK();
	}
}


void CTransfer::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if ((::MessageBox(this->m_hWnd, _T("确定取消存钱操作吗？"), _T("警告"), MB_OKCANCEL)) == IDOK)
		CDialogEx::OnCancel();
}


void CTransfer::OnEnChangeEditSelf()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_SELF, m_selfnum);

}


void CTransfer::OnEnChangeEditPassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_PASSWORD, m_password);

}


void CTransfer::OnEnChangeEditGoal()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_GOAL, m_goalnum);

}


void CTransfer::OnEnChangeEditMoney()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_MONEY, m_money);

}


BOOL CTransfer::PreTranslateMessage(MSG* pMsg)
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
