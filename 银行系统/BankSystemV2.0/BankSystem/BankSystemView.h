
// BankSystemView.h : CBankSystemView 类的接口
//

#pragma once
#include "MainMenu.h"
#include "Support.h"

class CBankSystemView : public CView
{
protected: // 仅从序列化创建
	CBankSystemView();
	DECLARE_DYNCREATE(CBankSystemView)

// 特性
public:
	CBankSystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
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

// 生成的消息映射函数
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

#ifndef _DEBUG  // BankSystemView.cpp 中的调试版本
inline CBankSystemDoc* CBankSystemView::GetDocument() const
   { return reinterpret_cast<CBankSystemDoc*>(m_pDocument); }
#endif

