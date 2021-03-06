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
ON_WM_PAINT()
ON_WM_SIZE()
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

void CRegister::SetWndPos(int x, int y, double dx, double dy)
{
	xpos = x;
	ypos = y;
	m_x = dx;
	m_y = dy;
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

	CRect temprect(0, 0, int(749 * m_x), int(586 * m_y));
	CWnd::SetWindowPos(NULL, xpos, ypos, temprect.Width(), temprect.Height(), SWP_NOZORDER /*| SWP_NOMOVE*/);
	//加文字
	int zx = int(120 * m_x);
	int zw = int(180 * m_x);
	int zh = int(42 * m_y);
	m_Static_Name.Init(zx, int(30 * m_y), zw, zh, m_y);
	m_Static_ID.Init(zx, int(130 * m_y), zw, zh, m_y);
	m_Sataic_Phone.Init(zx, int(230 * m_y), zw, zh, m_y);
	m_Sataic_Address.Init(zx, int(330 * m_y), zw, zh, m_y);
	m_Sataic_Password.Init(zx, int(430 * m_y), zw, zh, m_y);
	//编辑框
	m_EditFont = new CFont;
	m_EditFont->CreateFont(int(24*m_y),            // nHeight 
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
	int kx = int(300 * m_x);
	int kw = int(250 * m_x);
	int kh = int(42 * m_y);
	GetDlgItem(IDC_NAME)->SetWindowPos(NULL, kx, int(30*m_y), kw, kh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_ID)->SetWindowPos(NULL, kx, int(130*m_y), kw, kh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_PHONE)->SetWindowPos(NULL, kx, int(230*m_y), kw, kh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_ADDRESS)->SetWindowPos(NULL, kx, int(330*m_y), kw, kh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_PASSWORD)->SetWindowPos(NULL, kx, int(430*m_y), kw, kh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_NAME)->SetFont(m_EditFont);
	GetDlgItem(IDC_ID)->SetFont(m_EditFont);
	GetDlgItem(IDC_PHONE)->SetFont(m_EditFont);
	GetDlgItem(IDC_ADDRESS)->SetFont(m_EditFont);
	GetDlgItem(IDC_PASSWORD)->SetFont(m_EditFont);
	//按钮
	GetDlgItem(IDC_BUTTON1)->SetWindowPos(NULL, int(210*m_x), int(510*m_y), int(120*m_x), int(42*m_y), SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_BUTTON2)->SetWindowPos(NULL, int(420*m_x), int(510*m_y), int(120*m_x), int(42*m_y), SWP_NOZORDER /*| SWP_NOSIZE*/);

	//加载背景图
	CString strBmpPath = _T(".\\res\\SelfUI\\内容背景图.png");
	CImage img;
	img.Load(strBmpPath);
	m_bmpBackground.Attach(img.Detach());

	CDC *dc = GetDC();
	m_dcBmp.CreateCompatibleDC(dc);             //创建兼容性DC
												//用完之后释放
	ReleaseDC(dc);
	//bmpBackground.LoadBitmap(IDB_BITMAP1);    //载入资源中图片
	m_dcBmp.SelectObject(&m_bmpBackground);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CRegister::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CRegister::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	BITMAP bitmap;
	m_bmpBackground.GetBitmap(&bitmap);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &m_dcBmp, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	//消除瑕疵,圆润
	CRgn rgnTmp;
	rgnTmp.CreateRoundRectRgn(rect.left + 3, rect.top + 3, rect.right - rect.left - 3, rect.bottom - rect.top - 3, 6, 6);
	SetWindowRgn(rgnTmp, TRUE);
}


void CRegister::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码

}
