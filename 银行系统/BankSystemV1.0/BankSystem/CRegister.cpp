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
	if (m_EditFont != NULL)
		delete m_EditFont;
}

void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_NAME, m_Static_Name);
	DDX_Control(pDX, IDC_STATIC_ID, m_Static_ID);
	DDX_Control(pDX, IDC_STATIC_PHONE, m_Sataic_Phone);
	DDX_Control(pDX, IDC_STATIC_ADDRESS, m_Sataic_Address);
	DDX_Control(pDX, IDC_STATIC_PASSWORD, m_Sataic_Password);
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
ON_WM_CTLCOLOR()
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

void CRegister::SetWndPos(int x, int y)
{
	xpos = x;
	ypos = y;
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


BOOL CRegister::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CRect temprect(0, 0, 1211, 861);
	CWnd::SetWindowPos(NULL, xpos + 370, ypos + 160, temprect.Width(), temprect.Height(), SWP_NOZORDER /*| SWP_NOMOVE*/);

	//加文字
	m_Static_Name.Init(300, 100, 200, 70);
	m_Static_ID.Init(300, 200, 200, 70);
	m_Sataic_Phone.Init(300, 300, 200, 70);
	m_Sataic_Address.Init(300, 400, 200, 70);
	m_Sataic_Password.Init(300, 500, 200, 70);
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
	GetDlgItem(IDC_NAME)->SetWindowPos(NULL, 500, 100, 400, 64, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_ID)->SetWindowPos(NULL, 500, 200, 400, 64, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_PHONE)->SetWindowPos(NULL, 500, 300, 400, 70, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_ADDRESS)->SetWindowPos(NULL, 500, 400, 400, 70, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_PASSWORD)->SetWindowPos(NULL, 500, 500, 400, 70, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_NAME)->SetFont(m_EditFont);
	GetDlgItem(IDC_ID)->SetFont(m_EditFont);
	GetDlgItem(IDC_PHONE)->SetFont(m_EditFont);
	GetDlgItem(IDC_ADDRESS)->SetFont(m_EditFont);
	GetDlgItem(IDC_PASSWORD)->SetFont(m_EditFont);
	//按钮
	GetDlgItem(IDC_BUTTON1)->SetWindowPos(NULL, 350, 700, 200, 70, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_BUTTON2)->SetWindowPos(NULL, 700, 700, 200, 70, SWP_NOZORDER /*| SWP_NOSIZE*/);


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


HBRUSH CRegister::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
