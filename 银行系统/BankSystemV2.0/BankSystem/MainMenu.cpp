// MainMenu.cpp : 实现文件
//

#include "stdafx.h"
#include "BankSystem.h"
#include "MainMenu.h"
#include "afxdialogex.h"


// CMainMenu 对话框

IMPLEMENT_DYNAMIC(CMainMenu, CDialogEx)

CMainMenu::CMainMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainMenu::IDD, pParent)
{
	m_minWidth = 1020;
	m_minHeight = 658;
	m_oldWidth = 1;
	m_oldHeight = 1;
	m_x = 1;
	m_y = 1;
	m_childposx = 275;
	m_childposy = 75;
	m_handle.ReadData();
	m_visuable = false;
}

CMainMenu::~CMainMenu()
{
	m_handle.SaveData();
}

bool CMainMenu::IsVisuable()
{
	bool flag = m_visuable;
	if (m_visuable)
		m_visuable = false;
	else
		m_visuable = true;
	return flag;
}


bool CMainMenu::CheckErrors_Print(int Operators)
{
	switch (Operators)
	{
	case ERRORNUMBER:
		::MessageBox(this->m_hWnd, _T("账户错误！"), _T("警告"), MB_OK);
		return false;
	case ERRORPASSWORD:
		::MessageBox(this->m_hWnd, _T("密码错误！"), _T("警告"), MB_OK);
		return false;
	case ERRORMONEY:
		::MessageBox(this->m_hWnd, _T("金额错误！"), _T("警告"), MB_OK);
		return false;
	case ERRORTRANSNUM:
		::MessageBox(this->m_hWnd, _T("转账账户错误！"), _T("警告"), MB_OK);
		return false;
	case ERRORZERO:
		::MessageBox(this->m_hWnd, _T("操作失败！"), _T("警告"), MB_OK);
		return false;
	case ERRORUSERNAME:
		::MessageBox(this->m_hWnd, _T("用户名错误！"), _T("警告"), MB_OK);
		return false;
	case ERRORIDNUM:
		::MessageBox(this->m_hWnd, _T("身份证号码错误！"), _T("警告"), MB_OK);
		return false;
	case ERROROVERDRAW:
		::MessageBox(this->m_hWnd, _T("不允许账户透支！"), _T("警告"), MB_OK);
		return false;
	case NONEERROR:
		::MessageBox(this->m_hWnd, _T("本次操作成功！"), _T("成功"), MB_OK);
		return true;
	default:
		return true;
	}
}

bool CMainMenu::PrintSrearchInfo(list<UserData> datas)
{
	if (!datas.empty())
	{
		CString message = _T("尊敬的客户，已为您查询到以下账户信息：");
		list<CString> messages;
		list<UserData>::iterator iter = datas.begin();
		while (iter != datas.end())
		{
			UserData tmp = *iter;
			CString onemessage;
			onemessage = _T("\n  号码：\t") + tmp.number +
				_T("\n  用户名：\t") + tmp.username +
				_T("\n  身份证号码：") + tmp.id +
				_T("\n  手机号码：") + tmp.phone +
				_T("\n  地址：\t") + tmp.address;
			messages.push_back(onemessage);
			iter++;
		}
		int i = 1;
		list<CString>::iterator iter_messages = messages.begin();
		while (iter_messages != messages.end())
		{
			CString num;
			num.Format(_T("%d"), i);
			CString tmp = *iter_messages;
			message = message + "\n" + _T("账户") + num + ':' + tmp;
			iter_messages++;
			i++;
		}
		::MessageBox(this->m_hWnd, message, _T("信息查询"), MB_OK);
		return true;
	}
	return false;
}

void CMainMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_REGISTER, m_RegisterButton);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_SaveButton);
	DDX_Control(pDX, IDC_BUTTON_DRAW, m_DrawButoon);
	DDX_Control(pDX, IDC_BUTTON_SEARCH, m_SearchButton);
	DDX_Control(pDX, IDC_BUTTON_TRANSFER, m_TransferButton);
	DDX_Control(pDX, IDC_BUTTON_CANCLE, m_CancleButton);
	DDX_Control(pDX, IDC_BUTTON_BACK, m_BackButton);
	DDX_Control(pDX, IDC_STATIC_NAME, m_Static_Name);
	DDX_Control(pDX, IDC_STATIC_EMAIL, m_Static_Email);
	DDX_Control(pDX, IDC_STATIC_QQ, m_Static_qq);
	DDX_Control(pDX, IDC_STATIC_MAINMENU, m_Static_Mainmenu);
}


BEGIN_MESSAGE_MAP(CMainMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &CMainMenu::OnBnClickedButtonRegister)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CMainMenu::OnBnClickedButtonCancle)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMainMenu::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_DRAW, &CMainMenu::OnBnClickedButtonDraw)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CMainMenu::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CMainMenu::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_TRANSFER, &CMainMenu::OnBnClickedButtonTransfer)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
	ON_WM_SIZE()
	ON_WM_SETCURSOR()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()


// CMainMenu 消息处理程序


void CMainMenu::OnBnClickedButtonRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegister temp_register;
	CRect Rect;
	GetWindowRect(&Rect);
	int x = Rect.left + int(m_childposx * m_x);
	int y = Rect.top + int(m_childposy * m_y);
	temp_register.SetWndPos(x, y, m_x, m_y);
	if (temp_register.DoModal() == IDOK)
	{
		UserData data = temp_register.GetData();
		CString number = m_handle.Register(data);
		CString message = _T("尊敬的") + data.username
			+ _T("客户：\n\t恭喜你顺利开户!\n\t您的账户为： ") + number;
		::MessageBox(this->m_hWnd, message, _T("操作成功"), MB_OK);
	}
}


void CMainMenu::OnBnClickedButtonCancle()
{
	// TODO: 在此添加控件通知处理程序代码
	CCancle temp_cancle;
	CRect Rect;
	GetWindowRect(&Rect);
	int x = Rect.left + int(m_childposx * m_x);
	int y = Rect.top + int(m_childposy * m_y);
	temp_cancle.SetWndPos(x, y, m_x, m_y);
	if (temp_cancle.DoModal() == IDOK)
	{
		CString number = temp_cancle.GetNumber();
		CString password = temp_cancle.GetPassword();
		if (!CheckErrors_Print(m_handle.Cancle(number, password)))
			OnBnClickedButtonCancle();
	}
}


void CMainMenu::OnBnClickedButtonSave()
{
	// TODO: 在此添加控件通知处理程序代码
	CSave temp_save;
	CRect Rect;
	GetWindowRect(&Rect);
	int x = Rect.left + int(m_childposx * m_x);
	int y = Rect.top + int(m_childposy * m_y);
	temp_save.SetWndPos(x, y, m_x, m_y);
	if (temp_save.DoModal() == IDOK)
	{
		CString number = temp_save.GetNumber();
		CString password = temp_save.GetPassword();
		int money = temp_save.GetMoney();
		if (!CheckErrors_Print(m_handle.SaveMoney(number, password, money)))
			OnBnClickedButtonSave();
	}
}


void CMainMenu::OnBnClickedButtonDraw()
{
	// TODO: 在此添加控件通知处理程序代码
	CDraw temp_draw;
	CRect Rect;
	GetWindowRect(&Rect);
	int x = Rect.left + int(m_childposx * m_x);
	int y = Rect.top + int(m_childposy * m_y);
	temp_draw.SetWndPos(x, y, m_x, m_y);
	if (temp_draw.DoModal() == IDOK)
	{
		CString number = temp_draw.GetNumber();
		CString password = temp_draw.GetPassword();
		int money = temp_draw.GetMoney();
		if (!CheckErrors_Print(m_handle.DrawMoney(number, password, money)))
			OnBnClickedButtonDraw();
	}
}


void CMainMenu::OnBnClickedButtonSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CSearch temp_search;
	CRect Rect;
	GetWindowRect(&Rect);
	int x = Rect.left + int(m_childposx * m_x);
	int y = Rect.top + int(m_childposy * m_y);
	temp_search.SetWndPos(x, y, m_x, m_y);
	if (temp_search.DoModal() == IDOK)
	{
		if (temp_search.IsMoney())
		{
			CSearchmoney temp_searchMoney;
			temp_searchMoney.SetWndPos(x, y, m_x, m_y);
			if (temp_searchMoney.DoModal() == IDOK)
			{
				CString number = temp_searchMoney.GetNumber();
				CString password = temp_searchMoney.GetPassword();
				int key = m_handle.SearchMoney(number, password);
				if (CheckErrors_Print(key))
				{
					CString money;
					money.Format(_T("%d"), key);
					CString message;
					message = _T("账户") + number + _T("余额为 ") + money + _T(" 元。");
					::MessageBox(this->m_hWnd, message, _T("余额查询"), MB_OK);
				}
				else
					OnBnClickedButtonSearch();
			}
		}
		if (temp_search.IsInfo())
		{
			CSearchinfo temp_searchinfo;
			temp_searchinfo.SetWndPos(x, y, m_x, m_y);
			if (temp_searchinfo.DoModal() == IDOK)
			{
				CString name = temp_searchinfo.GetName();
				CString id = temp_searchinfo.GetId();
				list<UserData> datas;
				if (CheckErrors_Print(m_handle.SearchInfo(name, id, datas)))
					PrintSrearchInfo(datas);
				else
					OnBnClickedButtonSearch();
			}
		}
	}
}


void CMainMenu::OnBnClickedButtonTransfer()
{
	// TODO: 在此添加控件通知处理程序代码
	CTransfer temp_transfer;
	CRect Rect;
	GetWindowRect(&Rect);
	int x = Rect.left + int(m_childposx * m_x);
	int y = Rect.top + int(m_childposy * m_y);
	temp_transfer.SetWndPos(x, y, m_x, m_y);
	if (temp_transfer.DoModal() == IDOK)
	{
		CString selfnum = temp_transfer.GetSelfNum();
		CString password = temp_transfer.GetPassword();
		CString goalnum = temp_transfer.GetGoalNum();
		int money = temp_transfer.GetMoney();
		if (!CheckErrors_Print(m_handle.Transfer(selfnum, password, goalnum, money)))
			OnBnClickedButtonTransfer();
	}
}


void CMainMenu::OnBnClickedButtonBack()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_BUTTON_BACK))->SetFocus();

	if ((::MessageBox(this->m_hWnd, _T("确定结束本次服务？"), _T("警告"), MB_OKCANCEL)) == IDOK)
	{
		CWnd *parentWnd = this->GetParent();
		ShowWindow(SW_HIDE);
		::MessageBox(parentWnd->GetSafeHwnd(), _T("欢迎再次使用本系统！"), _T("感谢"), MB_OK);
		m_visuable = false;
	}
}



BOOL CMainMenu::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		//OnBnClickedButtonBack();
		return FALSE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return FALSE;
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CMainMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//m_Static_Mainmenu.SetTextSize(50);
	//m_Static_Mainmenu.SetTextFont(_T("黑体"));
	//m_Static_Mainmenu.SetTextColor(RGB(255,255,255));
	//m_Static_Mainmenu.Init(0, 10, 200, 50, 0);


	CRect temprect(0, 0, 1020, 658);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER /*| SWP_NOMOVE*/);
	//::SetWindowPos(m_hWnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
	CRect rect;
	GetClientRect(&rect);
	m_oldWidth = rect.Width(); 
	m_oldHeight = rect.Height();
	////背景图
	//CString strBmpPath = _T(".\\res\\SelfUI\\主背景图.png");
	//CImage img;
	//img.Load(strBmpPath);
	////MoveWindow(0, 0, img.GetWidth(), img.GetHeight());
	//CBitmap bmpTmp;
	//bmpTmp.Attach(img.Detach());
	//m_bkBrush.CreatePatternBrush(&bmpTmp);

	//加载背景图
	CString strBmpPath = _T(".\\res\\SelfUI\\主背景图.png");
	CImage img;
	img.Load(strBmpPath);
	m_bmpBackground.Attach(img.Detach());

	CDC *dc = GetDC();
	m_dcBmp.CreateCompatibleDC(dc);             //创建兼容性DC
												//用完之后释放
	ReleaseDC(dc);
	//bmpBackground.LoadBitmap(IDB_BITMAP1);    //载入资源中图片
	m_dcBmp.SelectObject(&m_bmpBackground);

	//按钮
	m_RegisterButton.SetImagePath(_T(".\\res\\SelfUI\\Buttons\\开户.png"), _T(".\\res\\SelfUI\\主背景图.png"));
	m_SaveButton.SetImagePath(_T(".\\res\\SelfUI\\Buttons\\存款.png"), _T(".\\res\\SelfUI\\主背景图.png"));
	m_DrawButoon.SetImagePath(_T(".\\res\\SelfUI\\Buttons\\提款.png"), _T(".\\res\\SelfUI\\主背景图.png"));
	m_SearchButton.SetImagePath(_T(".\\res\\SelfUI\\Buttons\\查询.png"), _T(".\\res\\SelfUI\\主背景图.png"));
	m_TransferButton.SetImagePath(_T(".\\res\\SelfUI\\Buttons\\转账.png"), _T(".\\res\\SelfUI\\主背景图.png"));
	m_CancleButton.SetImagePath(_T(".\\res\\SelfUI\\Buttons\\销户.png"), _T(".\\res\\SelfUI\\主背景图.png"));
	m_BackButton.SetImagePath(_T(".\\res\\SelfUI\\Buttons\\退出.png"), _T(".\\res\\SelfUI\\主背景图.png"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CMainMenu::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	//if (pWnd == this)
	//{
	//	return m_bkBrush;
	//}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


LRESULT CMainMenu::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetWindowRect(&rect);
	if (point.x <= rect.left + 5 && point.y < rect.bottom - 10 && point.y>rect.top + 10)
		return HTLEFT;
	else if (point.x >= rect.right - 5 && point.y < rect.bottom - 10 && point.y>rect.top + 10)
		return HTRIGHT;
	//else if (point.y <= rect.top + 5 && point.x > rect.left + 10 && point.x < rect.right - 10)
	//	return HTTOP;
	else if (point.y >= rect.bottom - 5 && point.x > rect.left + 10 && point.x < rect.right - 10)
		return HTBOTTOM;
	//else if (point.x <= rect.left + 10 && point.y <= rect.top + 10)
	//	return HTTOPLEFT;
	//else if (point.x >= rect.right - 10 && point.y <= rect.top + 10)
	//	return HTTOPRIGHT;
	else if (point.x <= rect.left + 10 && point.y >= rect.bottom - 10)
		return HTBOTTOMLEFT;
	else if (point.x >= rect.right - 10 && point.y >= rect.bottom - 10)
		return HTBOTTOMRIGHT;
	else if (point.y > rect.top + 10 && point.y <= rect.top + 75 * m_y
		&& point.x > rect.left + 10 && point.x < rect.right - 10)
		return HTCAPTION;
	else
		return CDialogEx::OnNcHitTest(point);
}


void CMainMenu::OnSize(UINT nType, int cx, int cy)
{
	//CDialogEx::OnSize(nType, cx, cy);
	// TODO: 在此处添加消息处理程序代码
	if (m_oldHeight == 1)
		return;
	m_x = double(cx) / double(m_oldWidth);
	m_y = double(cy) / double(m_oldHeight);
	Invalidate(FALSE);
}


BOOL CMainMenu::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CPoint ptCur;
	//CRect rect;
	//GetCursorPos(&ptCur);
	//GetWindowRect(&rect);

	////if (rect.Width() >= m_nCxFullScreen - 3 && rect.Height() >= m_nCyFullScreen - 3)
	////	return CDialog::OnSetCursor(pWnd, nHitTest, message);

	//if (CRect(rect.left, rect.top, rect.left + 3, rect.top + 3).PtInRect(ptCur) || CRect(rect.right - 3, rect.bottom - 3, rect.right, rect.bottom).PtInRect(ptCur))
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENWSE)));
	//	return 0;
	//}
	//else if (CRect(rect.left, rect.bottom - 3, rect.left + 3, rect.bottom).PtInRect(ptCur) || CRect(rect.left, rect.bottom - 3, rect.left + 3, rect.bottom).PtInRect(ptCur))
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENESW)));
	//	return 0;
	//}
	//else if (CRect(rect.left, rect.top, rect.right - 128, rect.top + 3).PtInRect(ptCur) || CRect(rect.left, rect.bottom - 3, rect.right, rect.bottom).PtInRect(ptCur))
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENS)));
	//	return 0;
	//}
	//else if (CRect(rect.left, rect.top, rect.left + 3, rect.bottom).PtInRect(ptCur) || CRect(rect.right - 3, rect.top, rect.right, rect.bottom).PtInRect(ptCur))
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEWE)));
	//	return 0;
	//}

	////return CDialog::OnSetCursor(pWnd, nHitTest, message);
	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
	//if (nHitTest == HTCAPTION || nHitTest == HTSYSMENU || nHitTest == HTMENU || nHitTest == HTCLIENT)
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW))); //IDC_ARROW 标准的箭头  
	//	return 0;
	//}
	//else if (nHitTest == HTTOP || nHitTest == HTBOTTOM)
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENS)));//IDC_SIZENS 双箭头指向南北 
	//	return 0;
	//}
	//else if (nHitTest == HTLEFT || nHitTest == HTRIGHT)
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEWE)));//IDC_SIZEWE 双箭头指向东西 
	//	return 0;
	//}
	//else if (nHitTest == HTTOPLEFT || nHitTest == HTBOTTOMRIGHT)
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENWSE)));//IDC_SIZENWSE 双箭头指向西北和东南 
	//	return 0;
	//}
	//else if (nHitTest == HTTOPRIGHT || nHitTest == HTBOTTOMLEFT)
	//{
	//	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENESW))); //IDC_SIZENESW 双箭头指向东北和西南 
	//	return 0;
	//}
}


void CMainMenu::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//switch (nHitTest)
	//{
	//case HTTOP:
	//	SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_TOP, MAKELPARAM(point.x, point.y));
	//	return;
	//case HTBOTTOM:
	//	SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOM, MAKELPARAM(point.x, point.y));
	//	return;
	//case HTLEFT:
	//	SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_LEFT, MAKELPARAM(point.x, point.y));
	//	return;
	//case HTRIGHT:
	//	SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_RIGHT, MAKELPARAM(point.x, point.y));
	//	return;
	//case HTTOPLEFT:
	//	SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPLEFT, MAKELPARAM(point.x, point.y));
	//	return;
	//case HTTOPRIGHT:
	//	SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPRIGHT, MAKELPARAM(point.x, point.y));
	//	return;
	//case HTBOTTOMLEFT:
	//	SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMLEFT, MAKELPARAM(point.x, point.y));
	//	return;
	//case HTBOTTOMRIGHT:
	//	SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMRIGHT, MAKELPARAM(point.x, point.y));
	//	return;
	//default:
	//	//CDialog::OnNcLButtonDown(nHitTest, point);
		CDialogEx::OnNcLButtonDown(nHitTest, point);
	if (nHitTest == HTTOP)
		SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_TOP, MAKELPARAM(point.x, point.y));
	else if (nHitTest == HTBOTTOM)
		SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOM, MAKELPARAM(point.x, point.y));
	else if (nHitTest == HTLEFT)
		SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_LEFT, MAKELPARAM(point.x, point.y));
	else if (nHitTest == HTRIGHT)
		SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_RIGHT, MAKELPARAM(point.x, point.y));
	else if (nHitTest == HTTOPLEFT)
		SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPLEFT, MAKELPARAM(point.x, point.y));
	else if (nHitTest == HTTOPRIGHT)
		SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPRIGHT, MAKELPARAM(point.x, point.y));
	else if (nHitTest == HTBOTTOMLEFT)
		SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMLEFT, MAKELPARAM(point.x, point.y));
	else if (nHitTest == HTBOTTOMRIGHT)
		SendMessage(WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMRIGHT, MAKELPARAM(point.x, point.y));
}


void CMainMenu::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	//dc.FillRect(&rect, &CBrush(RGB(255, 0, 255)));//不行？
	//CRect rect, fillrect;
	//CBrush brush;
	//brush.CreateSolidBrush(RGB(255, 0, 0));//实心画刷
	//this->GetClientRect(&rect);
	//dc.FillRect(&rect, &brush); //用FillRect成员函数利用笔刷填充指定区域  
	//brush.DeleteObject();

	BITMAP bitmap;
	m_bmpBackground.GetBitmap(&bitmap);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &m_dcBmp, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	//////消除瑕疵,圆润
	////CRgn rgnTmp;
	////rgnTmp.CreateRoundRectRgn(rect.left + 3, rect.top + 3, 
	////	rect.right - rect.left - 3, rect.bottom - rect.top - 3, 6, 6);
	////SetWindowRgn(rgnTmp, TRUE);
	////::SetWindowPos(m_hWnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);

	int x = int(51 * m_x);
	int w = int(146.25 * m_x);
	int h = int(58 * m_y);
	m_RegisterButton.SetButton(x, int(117 * m_y), w, h, m_x, m_y);
	m_SaveButton.SetButton(x, int(187 * m_y), w, h, m_x, m_y);
	m_DrawButoon.SetButton(x, int(256 * m_y), w, h, m_x, m_y);
	m_SearchButton.SetButton(x, int(325 * m_y), w, h, m_x, m_y);
	m_TransferButton.SetButton(x, int(395 * m_y), w, h, m_x, m_y);
	m_CancleButton.SetButton(x, int(464 * m_y), w, h, m_x, m_y);
	m_BackButton.SetButton(x, int(535 * m_y), w, h, m_x, m_y);
	
	//m_Static_Mainmenu.SetTextSize(int(50 * m_y));
	//m_Static_Mainmenu.Init(int(0 * m_x), int(10 * m_y), int(200 * m_x), int(50 * m_y), m_y);

}


void CMainMenu::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: 在此处添加消息处理程序代码
	if (lpwndpos->cx < m_minWidth)
	{
		lpwndpos->cx = m_minWidth;
	}

	if (lpwndpos->cy < m_minHeight)
	{
		lpwndpos->cy = m_minHeight;
	}
}
