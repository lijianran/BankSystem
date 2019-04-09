#include "stdafx.h"
#include "CSelfButton.h"

IMPLEMENT_DYNAMIC(CSelfButton, CButton)


CSelfButton::CSelfButton()
{
	m_x = 1;
	m_y = 1;
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
	SetMyButton(0, 0, 0, 0, true);
	//加载背景图
	CImage img;
	img.Load(m_strImgPath);
	m_bmpBackground.Attach(img.Detach());

	CDC *dc = GetDC();
	m_dcBmp.CreateCompatibleDC(dc);             //创建兼容性DC
												//用完之后释放
	ReleaseDC(dc);
	//bmpBackground.LoadBitmap(IDB_BITMAP1);    //载入资源中图片
	m_dcBmp.SelectObject(&m_bmpBackground);

}

bool CSelfButton::SetMyButton(int nX, int nY, int nW, int nH, bool bIsPng)
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
	
	BITMAP bitmap;
	m_bmpBackground.GetBitmap(&bitmap);
	int x = bitmap.bmWidth / 4;
	int y = bitmap.bmHeight;

	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		//按钮被选择  
		//m_imgButton.BitBlt(hMemDC, 0, 0, nW, nH, nW * 2, 0, SRCCOPY);
		StretchBlt(hMemDC, 0, 0, nW, nH, m_dcBmp, x*2, 0, x, y, SRCCOPY);
	}
	else if (lpDrawItemStruct->itemState & ODS_FOCUS)
	{
		//焦点状态  
		//m_imgButton.BitBlt(hMemDC, 0, 0, nW, nH, nW*m_x, 0, SRCCOPY);
		//m_imgButton.StretchBlt(hMemDC, 0, 0, nW, nH, nW, 0, nW, nH, SRCCOPY);
		
		//StretchBlt(0, 0, rect.Width(), rect.Height(), &m_dcBmp, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		StretchBlt(hMemDC, 0, 0, nW, nH, m_dcBmp, x, 0, x, y, SRCCOPY);
	}
	else
	{
		//默认状态  
		CImage imgParent;

		imgParent.Load(m_strImgParentPath);

		imgParent.Draw(hMemDC, 0, 0, nW, nH, rectTmp.left, rectTmp.top, nW, nH);

		//m_imgButton.AlphaBlend(hMemDC, 0, 0, nW, nH, 0, 0, nW, nH);
		StretchBlt(hMemDC, 0, 0, nW, nH, m_dcBmp, 0, 0, x, y, SRCCOPY);

		imgParent.Destroy();

	}

	::BitBlt(lpDrawItemStruct->hDC, 0, 0, nW, nH, hMemDC, 0, 0, SRCCOPY);
	//StretchBlt(lpDrawItemStruct->hDC, 0, 0, nW, nH, hMemDC, 0, 0, x, y, SRCCOPY);

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

void CSelfButton::SetButton(int nX, int nY, int nW, int nH, double dx, double dy)
{
	//Invalidate(FALSE);
	m_x = dx;
	m_y = dy;
	MoveWindow(nX, nY, nW, nH);

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


