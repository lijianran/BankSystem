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

void CSearch::SetWndPos(int x, int y, double dx, double dy)
{
	xpos = x;
	ypos = y;
	m_x = dx;
	m_y = dy;
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
	ON_WM_PAINT()
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
	CRect temprect(0, 0, int(749 * m_x), int(586 * m_y));
	CWnd::SetWindowPos(NULL, xpos, ypos, temprect.Width(), temprect.Height(), SWP_NOZORDER /*| SWP_NOMOVE*/);

	//按钮
	int by = int(200 * m_y);
	int bw = int(180 * m_y);
	int bh = int(120 * m_y);
	GetDlgItem(IDC_BUTTON_SEARCHMONEY)->SetWindowPos(NULL, int(30*m_x), by, bw, bh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_BUTTON_SEARCHINFO)->SetWindowPos(NULL, int(270*m_x), by, bw, bh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	GetDlgItem(IDC_BUTTON_CANCLE)->SetWindowPos(NULL, int(516*m_x), by, bw, bh, SWP_NOZORDER /*| SWP_NOSIZE*/);
	
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


HBRUSH CSearch::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CSearch::OnPaint()
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


BOOL CSearch::PreTranslateMessage(MSG* pMsg)
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
