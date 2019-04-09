#pragma once

//自定义字体

class CSelFont : public CStatic
{
public:
	CSelFont();
	~CSelFont();
public:
	void Init(int nX, int nY, int nW, int nH, double dy);
	void SetTextSize(int size = 15);
	void SetTextFont(CString name);
	void SetTextWeight(int weight);
	void SetTextColor(COLORREF crColor);

protected:
	LOGFONT m_selFont;
	COLORREF m_TextColor;
	double m_y;

	DECLARE_MESSAGE_MAP()

public:
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

