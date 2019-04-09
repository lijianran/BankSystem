
// BankSystemView.h : CBankSystemView ��Ľӿ�
//

#pragma once
#include "MainMenu.h"
#include "Support.h"

class CBankSystemView : public CView
{
protected: // �������л�����
	CBankSystemView();
	DECLARE_DYNCREATE(CBankSystemView)

// ����
public:
	CBankSystemDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CBankSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CMainMenu * m_MainMenu;
	CFont m_font;
	CBitmap bmp;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenu();
	afx_msg void OnAbout();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // BankSystemView.cpp �еĵ��԰汾
inline CBankSystemDoc* CBankSystemView::GetDocument() const
   { return reinterpret_cast<CBankSystemDoc*>(m_pDocument); }
#endif

