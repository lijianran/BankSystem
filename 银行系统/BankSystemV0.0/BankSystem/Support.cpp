// Support.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BankSystem.h"
#include "Support.h"
#include "afxdialogex.h"


// CSupport �Ի���

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


// CSupport ��Ϣ�������


void CSupport::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}
