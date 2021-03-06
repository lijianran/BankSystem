// CRegister.cpp: 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "CRegister.h"
#include "afxdialogex.h"


// CRegister 对话框

IMPLEMENT_DYNAMIC(CRegister, CDialogEx)

CRegister::CRegister(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REGISTER, pParent)
{

}

CRegister::~CRegister()
{
}

void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRegister, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CRegister::OnBnClickedOK)
	ON_BN_CLICKED(IDC_BUTTON2, &CRegister::OnBnClickedCancle)
	ON_EN_CHANGE(IDC_NAME, &CRegister::OnEnChangeName)
	ON_EN_CHANGE(IDC_ID, &CRegister::OnEnChangeId)
	ON_EN_CHANGE(IDC_PHONE, &CRegister::OnEnChangePhone)
	ON_EN_CHANGE(IDC_ADDRESS, &CRegister::OnEnChangeAddress)
	ON_EN_CHANGE(IDC_PASSWORD, &CRegister::OnEnChangePassword)
ON_WM_CLOSE()
END_MESSAGE_MAP()


// CRegister 消息处理程序


void CRegister::OnBnClickedOK()
{
	// TODO: 在此添加控件通知处理程序代码
	if (CheckBox())
		if ((::MessageBox(this->m_hWnd, _T("请确保信息填写无误，本系统不提供修改功能！"), _T("警告"), MB_OKCANCEL)) == IDOK)
			CDialogEx::OnOK();
}

void CRegister::OnBnClickedCancle()
{
	// TODO: 在此添加控件通知处理程序代码
	if ((::MessageBox(this->m_hWnd, _T("确定取消开户操作吗？"), _T("警告"), MB_OKCANCEL)) == IDOK)
		CDialogEx::OnCancel();
}


void CRegister::OnEnChangeName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_NAME, m_data.username);
}


void CRegister::OnEnChangeId()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_ID, m_data.id);

}


void CRegister::OnEnChangePhone()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_PHONE, m_data.phone);

}


void CRegister::OnEnChangeAddress()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_ADDRESS, m_data.address);

}

void CRegister::OnEnChangePassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_PASSWORD, m_data.password);

}

UserData CRegister::GetData()
{
	m_data.money = 0;
	return m_data;
}

bool CRegister::CheckBox()
{
	bool flag = true;
	if (m_data.username[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("姓名不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_data.id[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("身份证号码不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_data.phone[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("电话号码不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_data.address[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("地址不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_data.password[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("密码不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	return flag;
}


void CRegister::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRegister::OnBnClickedCancle();
	//CDialogEx::OnClose();
}


BOOL CRegister::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		OnBnClickedCancle();
		return FALSE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return FALSE;
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}
