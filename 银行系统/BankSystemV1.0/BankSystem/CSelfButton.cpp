#include "stdafx.h"
#include "CSelfButton.h"

IMPLEMENT_DYNAMIC(CSelfButton, CButton)


CSelfButton::CSelfButton()
{
}

CSelfButton::~CSelfButton()
{
}


BEGIN_MESSAGE_MAP(CSelfButton, CButton)
END_MESSAGE_MAP()

void CSelfButton::SetImagePath(CString strImgPath, CString strParentImgPath)
{
	m_strImgPath = strImgPath;
	m_strImgParentPath = strParentImgPath;
}

bool CSelfButton::InitMyButton(int nX, int nY, int nW, int nH, bool bIsPng)
{
	HRESULT hr = 0;
	if (m_strImgPath.IsEmpty())
		return false;
	hr = m_imgButton.Load(m_strImgPath);

	if (FAILED(hr))
		return false;

	if (bIsPng)
	{
		if (m_imgButton.GetBPP() == 32)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < m_imgButton.GetWidth(); i++)
			{
				for (j = 0; j < m_imgButton.GetHeight(); j++)
				{
					byte * pbyte = (byte *)m_imgButton.GetPixelAddress(i, j);
					pbyte[0] = pbyte[0] * pbyte[3] / 255;
					pbyte[1] = pbyte[1] * pbyte[3] / 255;
					pbyte[2] = pbyte[2] * pbyte[3] / 255;
				}
			}
		}
	}

	//MoveWindow(nX, nY, nW, nH);
	CRect temprect(0, 0, 212, 95);
	CWnd::SetWindowPos(NULL, nX, nY, temprect.Width(), temprect.Height(), SWP_NOZORDER /*| SWP_NOMOVE*/);

	return true;
}

void CSelfButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (!lpDrawItemStruct)
		return;
	HDC hMemDC;
	HBITMAP bmpMem;
	HGDIOBJ hOldObj;
	bmpMem = CreateCompatibleBitmap(lpDrawItemStruct->hDC,
		lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left,
		lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top);
	if (!bmpMem)
		return;
	hMemDC = CreateCompatibleDC(lpDrawItemStruct->hDC);
	if (!hMemDC)
	{
		if (bmpMem)
		{
			::DeleteObject(bmpMem);
			bmpMem = NULL;
		}
		return;
	}

	hOldObj = ::SelectObject(hMemDC, bmpMem);

	RECT rectTmp = { 0 };

	rectTmp = lpDrawItemStruct->rcItem;

	MapWindowPoints(GetParent(), &rectTmp);

	int nW = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left;

	int nH = lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top;

	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		//��ť��ѡ��  
		m_imgButton.BitBlt(hMemDC, 0, 0, nW, nH, nW * 2, 0, SRCCOPY);
	}
	else if (lpDrawItemStruct->itemState & ODS_FOCUS)
	{
		//����״̬  
		m_imgButton.BitBlt(hMemDC, 0, 0, nW, nH, nW, 0, SRCCOPY);
	}
	else
	{
		//Ĭ��״̬  
		CImage imgParent;

		imgParent.Load(m_strImgParentPath);

		imgParent.Draw(hMemDC, 0, 0, nW, nH, rectTmp.left, rectTmp.top, nW, nH);

		m_imgButton.AlphaBlend(hMemDC, 0, 0, nW, nH, 0, 0, nW, nH);

		imgParent.Destroy();

	}

	::BitBlt(lpDrawItemStruct->hDC, 0, 0, nW, nH, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldObj);

	if (bmpMem)
	{
		::DeleteObject(bmpMem);
		bmpMem = NULL;
	}

	if (hMemDC)
	{
		::DeleteDC(hMemDC);
		hMemDC = NULL;
	}
	return;
}

//void CSelfButton::KeepButtonDown()
//{
	//HDC hMemDC;
	//HBITMAP bmpMem;
	//HGDIOBJ hOldObj;
	//bmpMem = CreateCompatibleBitmap(lpDrawItemStruct->hDC,
	//	lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left,
	//	lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top);
	//if (!bmpMem)
	//	return;
	//hMemDC = CreateCompatibleDC(lpDrawItemStruct->hDC);
	//if (!hMemDC)
	//{
	//	if (bmpMem)
	//	{
	//		::DeleteObject(bmpMem);
	//		bmpMem = NULL;
	//	}
	//	return;
	//}
	//hOldObj = ::SelectObject(hMemDC, bmpMem);

	//int nW = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left;

	//int nH = lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top;

	//m_imgButton.BitBlt(hMemDC, 0, 0, nW, nH, nW * 2, 0, SRCCOPY);

//}
