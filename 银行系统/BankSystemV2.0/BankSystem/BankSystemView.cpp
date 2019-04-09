
// BankSystemView.cpp : CBankSystemView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "BankSystem.h"
#endif

#include "BankSystemDoc.h"
#include "BankSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBankSystemView

IMPLEMENT_DYNCREATE(CBankSystemView, CView)

BEGIN_MESSAGE_MAP(CBankSystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBankSystemView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MENU, &CBankSystemView::OnMenu)
	ON_COMMAND(ID_ABOUT, &CBankSystemView::OnAbout)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CBankSystemView 构造/析构

CBankSystemView::CBankSystemView()
{
	// TODO: 在此处添加构造代码
	m_MainMenu = NULL;
}

CBankSystemView::~CBankSystemView()
{
	if (m_MainMenu != NULL)
		delete m_MainMenu;
}

BOOL CBankSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBankSystemView 绘制

void CBankSystemView::OnDraw(CDC* /*pDC*/)
{
	CBankSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//CEdit *pEdit=new CEdit;
	//pEdit->Create(WS_VISIBLE|ES_LEFT,CRect(100,100,200,140),this,WM_USER+100);//或者使用CreateEx()
	//pEdit->ShowWindow(SW_SHOW);

	//CPaintDC dc(this);
	//LPCWSTR text1 = TEXT("manage of students grades");  
	//::TextOut(dc, 100, 100, text1, lstrlen(text1));
}


// CBankSystemView 打印


void CBankSystemView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBankSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBankSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBankSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CBankSystemView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBankSystemView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBankSystemView 诊断

#ifdef _DEBUG
void CBankSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CBankSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBankSystemDoc* CBankSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBankSystemDoc)));
	return (CBankSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CBankSystemView 消息处理程序


void CBankSystemView::OnMenu()
{
	// TODO: 在此添加命令处理程序代码
	if (m_MainMenu == NULL)
	{
		m_MainMenu = new CMainMenu;
		if (!m_MainMenu->IsVisuable())
		{
			::MessageBox(this->m_hWnd, _T("欢迎使用本银行系统！\n\n系统已经初始化成功！"), _T("欢迎"), MB_OK);
			m_MainMenu->Create(IDD_MAINMENU, this);
			m_MainMenu->ShowWindow(SW_SHOW);
		}
	}
	else
	{
		if (!m_MainMenu->IsVisuable())
		{
			::MessageBox(this->m_hWnd, _T("欢迎使用本银行系统！"), _T("欢迎"), MB_OK);
			m_MainMenu->ShowWindow(SW_SHOW);
		}
		else
			::MessageBox(this->m_hWnd, _T("本银行系统正在运行，请不要重复运行！"), _T("警告"), MB_OK);
	}
}


void CBankSystemView::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CSupport temp_support;
	temp_support.DoModal();
}


void CBankSystemView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CView::OnPaint()
	//m_font.CreateFont(160, 60, 0, 0, 600,
	//	TRUE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, _T("Arial"));
	//CFont *pOldFont = dc.SelectObject(&m_font);
	//dc.SetTextColor(RGB(255, 0, 0));
	//dc.TextOutW(300, 200, _T("欢迎光临网上银行！"));
	//m_font.DeleteObject();

	//bmp.LoadBitmapA(IDB_SUPPORT);
	//brush.CreatePatternBrush(&bmp);
	//bmp.DeleteObject();
	CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(144, 144, 144));

}

