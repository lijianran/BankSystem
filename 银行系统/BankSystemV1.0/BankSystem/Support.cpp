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
	DDX_Control(pDX, IDC_STATIC_PIC, m_SupportPic);
}


BEGIN_MESSAGE_MAP(CSupport, CDialogEx)
END_MESSAGE_MAP()


// CSupport ��Ϣ�������


BOOL CSupport::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect temprect(0, 0, 1030, 1030);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);
	GetDlgItem(IDC_STATIC_PIC)->SetWindowPos(NULL, 300, 300, 0, 0, SWP_NOZORDER | SWP_NOSIZE);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
