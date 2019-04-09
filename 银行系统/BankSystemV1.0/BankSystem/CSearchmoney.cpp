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
	if (m_EditFont != NULL)
		delete m_EditFont;
}

void CSearchmoney::SetWndPos(int x, int y)
{
	xpos = x;
	ypos = y;
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
	DDX_Control(pDX, IDC_STATIC_ACCOUNT, m_Static_Account);
	DDX_Control(pDX, IDC_STATIC_PASSWORD, m_Static_Password);
}


BEGIN_MESSAGE_MAP(CSearchmoney, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CSearchmoney::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CSearchmoney::OnBnClickedButtonCancle)
	ON_EN_CHANGE(IDC_EDIT_ACCOUNT, &CSearchmoney::OnEnChangeEditAccount)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CSearchmoney::OnEnChangeEditPassword)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
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


BOOL CSearchmoney::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect temprect(0, 0, 1211, 861);
	CWnd::SetWindowPos(NULL, xpos + 370, ypos + 160, temprect.Width(), temprect.Height(), SWP_NOZORDER /*| SWP_NOMOVE*/);
	//加文字
	m_Static_Account.Init(150, 100, 380, 70);
	m_Static_Password.Init(150, 200, 380, 70);
	//编辑框
	m_EditFont = new CFont;
	m_EditFont->CreateFont(40,            // nHeight 
		0,           // nWidth 
		0,           // nEscapement 
		0,           // nOrientation 
		FW_BOLD,     // nWeight 
		FALSE,        // bItalic 
		FALSE,       // bUnderline 
		0,           // cStrikeOut 
		ANSI_CHARSET,              // nCharSet 
		OUT_DEFAULT_PRECIS,        // nOutPrecision 
		CLIP_DEFAULT_PRECIS,       // nClipPrecision 
		DEFAULT_QUALITY,           // nQuality 
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
		_T("consolas"));
	GetDlgItem(IDC_EDIT_ACCOUNT)->SetWindowPos(NULL, 500, 100, 400, 64, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_EDIT_PASSWORD)->SetWindowPos(NULL, 500, 200, 400, 64, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_EDIT_ACCOUNT)->SetFont(m_EditFont);
	GetDlgItem(IDC_EDIT_PASSWORD)->SetFont(m_EditFont);
	//按钮
	GetDlgItem(IDC_BUTTON_SEARCH)->SetWindowPos(NULL, 350, 700, 200, 70, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_BUTTON_CANCLE)->SetWindowPos(NULL, 700, 700, 200, 70, SWP_NOZORDER /*| SWP_NOSIZE*/);
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


HBRUSH CSearchmoney::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
