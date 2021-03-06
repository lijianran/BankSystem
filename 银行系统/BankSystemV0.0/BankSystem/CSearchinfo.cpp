// CSearchinfo.cpp: 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "CSearchinfo.h"
#include "afxdialogex.h"


// CSearchinfo 对话框

IMPLEMENT_DYNAMIC(CSearchinfo, CDialogEx)

CSearchinfo::CSearchinfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCHINFO, pParent)
{

}

CSearchinfo::~CSearchinfo()
{
}

bool CSearchinfo::CheckBox()
{
	bool flag = true;
	if (m_name[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("姓名不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	if (m_id[0] == '\0')
	{
		::MessageBox(this->m_hWnd, _T("身份证号码不能为空"), _T("警告"), MB_OK);
		flag = false;
	}
	return flag;
}

void CSearchinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSearchinfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CSearchinfo::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CSearchinfo::OnBnClickedButtonCancle)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CSearchinfo::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_ID, &CSearchinfo::OnEnChangeEditId)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CSearchinfo 消息处理程序


void CSearchinfo::OnBnClickedButtonSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	if (CheckBox())
		CDialogEx::OnOK();

}


void CSearchinfo::OnBnClickedButtonCancle()
{
	// TODO: 在此添加控件通知处理程序代码
	if ((::MessageBox(this->m_hWnd, _T("确定取消查询操作吗？"), _T("警告"), MB_OKCANCEL)) == IDOK)
		CDialogEx::OnCancel();

}


void CSearchinfo::OnEnChangeEditName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_NAME, m_name);

}


void CSearchinfo::OnEnChangeEditId()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_ID, m_id);

}


void CSearchinfo::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	OnBnClickedButtonCancle();
	//CDialogEx::OnClose();
}


BOOL CSearchinfo::PreTranslateMessage(MSG* pMsg)
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
