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

void CSelFont::SetTextSize(int size)//����Ϊ�߼������С
{
	m_selFont.lfHeight = size;
}

void CSelFont::SetTextFont(CString name)//����Ϊ�߼�������
{
	//strcpy(m_LogFont.lfFaceName, FontName);
	::lstrcpy(m_selFont.lfFaceName, name);
}

void CSelFont::SetTextWeight(int weight)//����Ϊ�߼������ϸ (value from 0 to 1000 and step is 100)
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

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


HBRUSH CSelFont::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����
	CFont font;
	if (!pDC)
		return NULL;

	HBRUSH hr = (HBRUSH)GetStockObject(NULL_BRUSH);
	//�����ֵı���͸��  
	pDC->SetBkMode(TRANSPARENT);
	//�������ֵ���ɫ
	pDC->SetTextColor(m_TextColor);
	//�����߼�����ĸ߶�
	//m_selFont.lfHeight = int(20 * m_y);
	//�����߼�����Ϊ������
	m_selFont.lfWeight = FW_BOLD;
	//��������Ϊ����
	::lstrcpy(m_selFont.lfFaceName, _T("����"));
	//���߼����崴��һ��CFont����
	font.CreateFontIndirect(&m_selFont);
	//Ӧ������  

	pDC->SelectObject(&font);
	return hr;
	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
}

