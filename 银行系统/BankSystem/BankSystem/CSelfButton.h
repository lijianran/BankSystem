#pragma once

//�Զ��尴ť

class CSelfButton : public CButton
{

	DECLARE_DYNAMIC(CSelfButton)


public:
	CSelfButton();
	virtual ~CSelfButton();

protected:
	//��ť����ͼ��  
	CImage m_imgButton;

	//��ťpng·�����������㣬����������3��״̬  
	CString m_strImgPath;

	//�����ڱ���ͼƬ����·����͸��png��Ҫʹ��  
	CString m_strImgParentPath;

	double m_x;
	double m_y;
	CDC m_dcBmp;   //���岢����һ���ڴ��豸����
	CBitmap m_bmpBackground;

public:
	//���ð�ť����ͼƬ·���������ڱ���ͼƬ·��  
	void SetImagePath(CString strImgPath, CString strParentImgPath);

	//��ʼ����ť����Ҫ�ǵ�����ť��λ�ã�����͸��ɫ  
	bool SetMyButton(int nX/*���Ͻ�X����*/, int nY/*���Ͻ�Y����*/, int nW/*ͼ���*/, int nH/*ͼ���*/, bool bIsPng/*�Ƿ���PNGͼƬ*/);

	//�Ի��ƺ���  
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	void SetButton(int nX, int nY, int nW, int nH, double dx, double dy);
protected:
	DECLARE_MESSAGE_MAP()

public:
};

