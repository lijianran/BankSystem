#pragma once


// CSupport �Ի���

class CSupport : public CDialogEx
{
	DECLARE_DYNAMIC(CSupport)

public:
	CSupport(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSupport();

// �Ի�������
	enum { IDD = IDD_SUPPORT };
protected:
	//BOOL ShowJpgGif(CDC* pDC,CString strPath, int x, int y);//��ȡ�ļ���Ϣ��ʽ��JPG��ͼƬ�ļ�  

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
