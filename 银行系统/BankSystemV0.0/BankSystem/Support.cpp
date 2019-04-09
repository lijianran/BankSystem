// Support.cpp : 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "Support.h"
#include "afxdialogex.h"


// CSupport 对话框

IMPLEMENT_DYNAMIC(CSupport, CDialogEx)

CSupport::CSupport(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSupport::IDD, pParent)
{

}

CSupport::~CSupport()
{
}

void CSupport::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSupport, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSupport::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSupport 消息处理程序


void CSupport::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

}
