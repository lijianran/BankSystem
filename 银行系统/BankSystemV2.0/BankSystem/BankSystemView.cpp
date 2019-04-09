
// BankSystemView.cpp : CBankSystemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBankSystemView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MENU, &CBankSystemView::OnMenu)
	ON_COMMAND(ID_ABOUT, &CBankSystemView::OnAbout)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CBankSystemView ����/����

CBankSystemView::CBankSystemView()
{
	// TODO: �ڴ˴���ӹ������
	m_MainMenu = NULL;
}

CBankSystemView::~CBankSystemView()
{
	if (m_MainMenu != NULL)
		delete m_MainMenu;
}

BOOL CBankSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CBankSystemView ����

void CBankSystemView::OnDraw(CDC* /*pDC*/)
{
	CBankSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//CEdit *pEdit=new CEdit;
	//pEdit->Create(WS_VISIBLE|ES_LEFT,CRect(100,100,200,140),this,WM_USER+100);//����ʹ��CreateEx()
	//pEdit->ShowWindow(SW_SHOW);

	//CPaintDC dc(this);
	//LPCWSTR text1 = TEXT("manage of students grades");  
	//::TextOut(dc, 100, 100, text1, lstrlen(text1));
}


// CBankSystemView ��ӡ


void CBankSystemView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBankSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CBankSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CBankSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CBankSystemView ���

#ifdef _DEBUG
void CBankSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CBankSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBankSystemDoc* CBankSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBankSystemDoc)));
	return (CBankSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CBankSystemView ��Ϣ�������


void CBankSystemView::OnMenu()
{
	// TODO: �ڴ���������������
	if (m_MainMenu == NULL)
	{
		m_MainMenu = new CMainMenu;
		if (!m_MainMenu->IsVisuable())
		{
			::MessageBox(this->m_hWnd, _T("��ӭʹ�ñ�����ϵͳ��\n\nϵͳ�Ѿ���ʼ���ɹ���"), _T("��ӭ"), MB_OK);
			m_MainMenu->Create(IDD_MAINMENU, this);
			m_MainMenu->ShowWindow(SW_SHOW);
		}
	}
	else
	{
		if (!m_MainMenu->IsVisuable())
		{
			::MessageBox(this->m_hWnd, _T("��ӭʹ�ñ�����ϵͳ��"), _T("��ӭ"), MB_OK);
			m_MainMenu->ShowWindow(SW_SHOW);
		}
		else
			::MessageBox(this->m_hWnd, _T("������ϵͳ�������У��벻Ҫ�ظ����У�"), _T("����"), MB_OK);
	}
}


void CBankSystemView::OnAbout()
{
	// TODO: �ڴ���������������
	CSupport temp_support;
	temp_support.DoModal();
}


void CBankSystemView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
	//m_font.CreateFont(160, 60, 0, 0, 600,
	//	TRUE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, _T("Arial"));
	//CFont *pOldFont = dc.SelectObject(&m_font);
	//dc.SetTextColor(RGB(255, 0, 0));
	//dc.TextOutW(300, 200, _T("��ӭ�����������У�"));
	//m_font.DeleteObject();

	//bmp.LoadBitmapA(IDB_SUPPORT);
	//brush.CreatePatternBrush(&bmp);
	//bmp.DeleteObject();
	CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(144, 144, 144));

}

