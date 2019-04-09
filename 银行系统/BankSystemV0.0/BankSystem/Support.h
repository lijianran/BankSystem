#pragma once


// CSupport 对话框

class CSupport : public CDialogEx
{
	DECLARE_DYNAMIC(CSupport)

public:
	CSupport(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSupport();

// 对话框数据
	enum { IDD = IDD_SUPPORT };
protected:
	//BOOL ShowJpgGif(CDC* pDC,CString strPath, int x, int y);//读取文件信息方式打开JPG等图片文件  

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
