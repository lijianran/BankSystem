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
	if (m_EditFont != NULL)
		delete m_EditFont;
}

void CSave::SetWndPos(int x, int y, double dx, double dy)
{
	xpos = x;
	ypos = y;
	m_x = dx;
	m_y = dy;
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
	DDX_Control(pDX, IDC_STATIC_ACCOUNT, m_Static_Account);
	DDX_Control(pDX, IDC_STATIC_PASSWORD, m_Static_Password);
	DDX_Control(pDX, IDC_STATIC_MONEY, m_Static_Money);
}


BEGIN_MESSAGE_MAP(CSave, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CSave::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CSave::OnBnClickedButtonCancle)
	ON_EN_CHANGE(IDC_EDIT_ACCOUNT, &CSave::OnEnChangeEditAccount)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CSave::OnEnChangeEditPassword)
	ON_EN_CHANGE(IDC_EDIT_MONEY, &CSave::OnEnChangeEditMoney)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
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


BOOL CSave::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect temprect(0, 0, int(749 * m_x), int(586 * m_y));
	CWnd::SetWindowPos(NULL, xpos, ypos, temprect.Width(), temprect.Height(), SWP_NOZORDER /*| SWP_NOMOVE*/);
	//加文字
	int zx = int(120 * m_x);
	int zw = int(180 * m_x);
	int zh = int(42 * m_y);
	m_Static_Account.Init(zx, int(100 * m_y), zw, zh, m_y);
	m_Static_Password.Init(zx, int(200 * m_y), zw, zh, m_y);
	m_Static_Money.Init(zx, int(300 * m_y), zw, zh, m_y);
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
	GetDlgItem(IDC_EDIT_ACCOUNT)->SetWindowPos(NULL, kx, int(100 * m_y), kw, kh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_EDIT_PASSWORD)->SetWindowPos(NULL, kx, int(200 * m_y), kw, kh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_EDIT_MONEY)->SetWindowPos(NULL, kx, int(300 * m_y), kw, kh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_EDIT_ACCOUNT)->SetFont(m_EditFont);
	GetDlgItem(IDC_EDIT_PASSWORD)->SetFont(m_EditFont);
	GetDlgItem(IDC_EDIT_MONEY)->SetFont(m_EditFont);
	//按钮
	GetDlgItem(IDC_BUTTON_OK)->SetWindowPos(NULL, int(200 * m_x), int(480 * m_y), int(120 * m_x), int(42 * m_y), SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_BUTTON_CANCLE)->SetWindowPos(NULL, int(440 * m_x), int(480 * m_y), int(120 * m_x), int(42 * m_y), SWP_NOZORDER /*| SWP_NOSIZE*/);

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


HBRUSH CSave::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CSave::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
					   //加载背景图
	CRect rect;
	GetClientRect(&rect);
	BITMAP bitmap;
	m_bmpBackground.GetBitmap(&bitmap);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &m_dcBmp, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	////消除瑕疵,圆润
	CRgn rgnTmp;
	rgnTmp.CreateRoundRectRgn(rect.left + 3, rect.top + 3, rect.right - rect.left - 3, rect.bottom - rect.top - 3, 6, 6);
	SetWindowRgn(rgnTmp, TRUE);
}
