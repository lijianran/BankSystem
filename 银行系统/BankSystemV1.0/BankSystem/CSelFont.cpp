#include "stdafx.h"
#include "CSelFont.h"


CSelFont::CSelFont()
{
}


CSelFont::~CSelFont()
{
}

void CSelFont::Init(int nX, int nY, int nW, int nH)
{
	MoveWindow(nX, nY, nW, nH);
}

void CSelFont::SetTextSize(int size)//参数为逻辑字体大小
{
	m_selFont.lfHeight = -size;
}

void CSelFont::SetTextFont(char FontName[])//参数为逻辑字体名
{
	//strcpy(m_LogFont.lfFaceName, FontName);
	::lstrcpy(m_selFont.lfFaceName, _T("楷体"));
}

void CSelFont::SetTextWeight(int weight)// 参数为逻辑字体粗细 (value from 0 to 1000 and step is 100)
{
	m_selFont.lfWeight = weight;
}

void CSelFont::SetTextColor(COLORREF crColor)
{
	m_TextColor = crColor;
}

BEGIN_MESSAGE_MAP(CSelFont, CStatic)
	ON_WM_CTLCOLOR()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()


HBRUSH CSelFont::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


HBRUSH CSelFont::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  在此更改 DC 的任何特性
	CFont font;
	if (!pDC)
		return NULL;

	//创建一个空画刷，返回这个画刷可以让静态控件的背景透明  
	HBRUSH hr = (HBRUSH)GetStockObject(NULL_BRUSH);
	//让文字的背景透明  
	pDC->SetBkMode(TRANSPARENT);
	//设置文字的颜色为白色  
	pDC->SetTextColor(RGB(255, 230, 230));
	::ZeroMemory(&m_selFont, sizeof(m_selFont));
	//设置逻辑字体的高度    
	m_selFont.lfHeight = 30;
	//设置逻辑字体为粗体字  
	m_selFont.lfWeight = FW_BOLD;
	//设置字体为黑体
	::lstrcpy(m_selFont.lfFaceName, _T("黑体"));
	//用逻辑字体创建一个CFont对象  
	font.CreateFontIndirect(&m_selFont);
	//应用字体  
	pDC->SelectObject(&font);
	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
	return hr;
}
