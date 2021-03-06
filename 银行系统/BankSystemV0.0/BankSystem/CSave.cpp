// CSave.cpp: 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "CSave.h"
#include "afxdialogex.h"


// CSave 对话框

IMPLEMENT_DYNAMIC(CSave, CDialogEx)

CSave::CSave(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SAVEMONEY, pParent)
{

}

CSave::~CSave()
{
}

bool CSave::CheckBox()
{
	bool flag = true;
	if (m_account[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("账户不能为空！"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_password[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("密码不能为空！"), _T("警告"), MB_OK);
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
			::MessageBox(this->m_hWnd, _T("一次存款不能超过百万元！"), _T("警告"), MB_OK);
			flag = false;
		}
	}
	else
	{
		::MessageBox(this->m_hWnd, _T("请输入存款金额！"), _T("警告"), MB_OK);
		flag = false;
	}
	return flag;
}

void CSave::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSave, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CSave::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CSave::OnBnClickedButtonCancle)
	ON_EN_CHANGE(IDC_EDIT_ACCOUNT, &CSave::OnEnChangeEditAccount)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CSave::OnEnChangeEditPassword)
	ON_EN_CHANGE(IDC_EDIT_MONEY, &CSave::OnEnChangeEditMoney)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CSave 消息处理程序



void CSave::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (CheckBox())
		CDialogEx::OnOK();
}


void CSave::OnBnClickedButtonCancle()
{
	// TODO: 在此添加控件通知处理程序代码
	if ((::MessageBox(this->m_hWnd, _T("确定取消存钱操作吗？"), _T("警告"), MB_OKCANCEL)) == IDOK)
		CDialogEx::OnCancel();

}


void CSave::OnEnChangeEditAccount()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_ACCOUNT, m_account);

}


void CSave::OnEnChangeEditPassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_PASSWORD, m_password);

}


void CSave::OnEnChangeEditMoney()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_MONEY, m_money);

}


void CSave::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	OnBnClickedButtonCancle();
	//CDialogEx::OnClose();
}


BOOL CSave::PreTranslateMessage(MSG* pMsg)
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
