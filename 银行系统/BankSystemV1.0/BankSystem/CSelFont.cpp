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

void CSelFont::SetTextSize(int size)//����Ϊ�߼������С
{
	m_selFont.lfHeight = -size;
}

void CSelFont::SetTextFont(char FontName[])//����Ϊ�߼�������
{
	//strcpy(m_LogFont.lfFaceName, FontName);
	::lstrcpy(m_selFont.lfFaceName, _T("����"));
}

void CSelFont::SetTextWeight(int weight)// ����Ϊ�߼������ϸ (value from 0 to 1000 and step is 100)
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

	//����һ���ջ�ˢ�����������ˢ�����þ�̬�ؼ��ı���͸��  
	HBRUSH hr = (HBRUSH)GetStockObject(NULL_BRUSH);
	//�����ֵı���͸��  
	pDC->SetBkMode(TRANSPARENT);
	//�������ֵ���ɫΪ��ɫ  
	pDC->SetTextColor(RGB(255, 230, 230));
	::ZeroMemory(&m_selFont, sizeof(m_selFont));
	//�����߼�����ĸ߶�    
	m_selFont.lfHeight = 30;
	//�����߼�����Ϊ������  
	m_selFont.lfWeight = FW_BOLD;
	//��������Ϊ����
	::lstrcpy(m_selFont.lfFaceName, _T("����"));
	//���߼����崴��һ��CFont����  
	font.CreateFontIndirect(&m_selFont);
	//Ӧ������  
	pDC->SelectObject(&font);
	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	return hr;
}
