#include "stdafx.h"
#include "CSelFont.h"


CSelFont::CSelFont()
{
	::ZeroMemory(&m_selFont, sizeof(m_selFont));
	m_selFont.lfHeight = 20;
	m_TextColor = RGB(0, 0, 0);

}


CSelFont::~CSelFont()
{
}

void CSelFont::Init(int nX, int nY, int nW, int nH, double dy)
{
	m_y = dy;
	if(dy!=0)
		m_selFont.lfHeight = int(m_selFont.lfHeight * m_y);

	MoveWindow(nX, nY, nW, nH);
}

void CSelFont::SetTextSize(int size)//参数为逻辑字体大小
{
	m_selFont.lfHeight = size;
}

void CSelFont::SetTextFont(CString name)//参数为逻辑字体名
{
	//strcpy(m_LogFont.lfFaceName, FontName);
	::lstrcpy(m_selFont.lfFaceName, name);
}

void CSelFont::SetTextWeight(int weight)//参数为逻辑字体粗细 (value from 0 to 1000 and step is 100)
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

	HBRUSH hr = (HBRUSH)GetStockObject(NULL_BRUSH);
	//让文字的背景透明  
	pDC->SetBkMode(TRANSPARENT);
	//设置文字的颜色
	pDC->SetTextColor(m_TextColor);
	//设置逻辑字体的高度
	//m_selFont.lfHeight = int(20 * m_y);
	//设置逻辑字体为粗体字
	m_selFont.lfWeight = FW_BOLD;
	//设置字体为黑体
	::lstrcpy(m_selFont.lfFaceName, _T("黑体"));
	//用逻辑字体创建一个CFont对象
	font.CreateFontIndirect(&m_selFont);
	//应用字体  

	pDC->SelectObject(&font);
	return hr;
	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
}

