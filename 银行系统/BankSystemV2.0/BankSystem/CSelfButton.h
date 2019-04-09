#pragma once

//自定义按钮

class CSelfButton : public CButton
{

	DECLARE_DYNAMIC(CSelfButton)


public:
	CSelfButton();
	virtual ~CSelfButton();

protected:
	//按钮背景图像  
	CImage m_imgButton;

	//按钮png路径，包括焦点，正常，按下3个状态  
	CString m_strImgPath;

	//父窗口背景图片背景路径，透明png需要使用  
	CString m_strImgParentPath;

	double m_x;
	double m_y;
	CDC m_dcBmp;   //定义并创建一个内存设备环境
	CBitmap m_bmpBackground;

public:
	//设置按钮背景图片路径，父窗口背景图片路径  
	void SetImagePath(CString strImgPath, CString strParentImgPath);

	//初始化按钮，主要是调整按钮的位置，处理透明色  
	bool SetMyButton(int nX/*左上角X坐标*/, int nY/*左上角Y坐标*/, int nW/*图像宽*/, int nH/*图像高*/, bool bIsPng/*是否是PNG图片*/);

	//自绘制函数  
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	void SetButton(int nX, int nY, int nW, int nH, double dx, double dy);
protected:
	DECLARE_MESSAGE_MAP()

public:
};

