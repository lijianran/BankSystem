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

void CSearch::SetWndPos(int x, int y)
{
	xpos = x;
	ypos = y;
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
	ON_WM_CTLCOLOR()
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


BOOL CSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect temprect(0, 0, 1211, 861);
	CWnd::SetWindowPos(NULL, xpos + 370, ypos + 160, temprect.Width(), temprect.Height(), SWP_NOZORDER /*| SWP_NOMOVE*/);
	////m_Caption.Init(700, 20, 300, 60);
	//m_Caption.Init(0, 0, 300, 60);

	//按钮
	GetDlgItem(IDC_BUTTON_SEARCHMONEY)->SetWindowPos(NULL, 50, 270, 300, 200, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_BUTTON_SEARCHINFO)->SetWindowPos(NULL, 450, 270, 300, 200, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_BUTTON_CANCLE)->SetWindowPos(NULL, 860, 270, 300, 200, SWP_NOZORDER /*| SWP_NOSIZE*/);


	//加背景图
	CString strBmpPath = _T(".\\res\\SelfUI\\内容背景图.png");

	CImage img;

	img.Load(strBmpPath);

	//MoveWindow(0, 0, img.GetWidth(), img.GetHeight());

	CBitmap bmpTmp;

	bmpTmp.Attach(img.Detach());

	m_bkBrush.CreatePatternBrush(&bmpTmp);

	//消除瑕疵,圆润
	CRgn rgnTmp;
	RECT rc;
	GetClientRect(&rc);
	rgnTmp.CreateRoundRectRgn(rc.left + 3, rc.top + 3, rc.right - rc.left - 3, rc.bottom - rc.top - 3, 6, 6);
	SetWindowRgn(rgnTmp, TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CSearch::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd == this)
	{
		return m_bkBrush;
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
