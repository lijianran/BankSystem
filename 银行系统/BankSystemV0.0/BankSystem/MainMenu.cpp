// MainMenu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BankSystem.h"
#include "MainMenu.h"
#include "afxdialogex.h"


// CMainMenu �Ի���

IMPLEMENT_DYNAMIC(CMainMenu, CDialogEx)

CMainMenu::CMainMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainMenu::IDD, pParent)
{
	m_handle.ReadData();
	m_visuable = false;
}

CMainMenu::~CMainMenu()
{
	m_handle.SaveData();
}

bool CMainMenu::IsVisuable()
{
	bool flag = m_visuable;
	if (m_visuable)
		m_visuable = false;
	else
		m_visuable = true;
	return flag;
}

bool CMainMenu::CheckErrors_Print(int Operators)
{
	switch (Operators)
	{
	case ERRORNUMBER:
		::MessageBox(this->m_hWnd, _T("�˻�����"), _T("����"), MB_OK);
		return false;
	case ERRORPASSWORD:
		::MessageBox(this->m_hWnd, _T("�������"), _T("����"), MB_OK);
		return false;
	case ERRORMONEY:
		::MessageBox(this->m_hWnd, _T("������"), _T("����"), MB_OK);
		return false;
	case ERRORTRANSNUM:
		::MessageBox(this->m_hWnd, _T("ת���˻�����"), _T("����"), MB_OK);
		return false;
	case ERRORZERO:
		::MessageBox(this->m_hWnd, _T("����ʧ�ܣ�"), _T("����"), MB_OK);
		return false;
	case ERRORUSERNAME:
		::MessageBox(this->m_hWnd, _T("�û�������"), _T("����"), MB_OK);
		return false;
	case ERRORIDNUM:
		::MessageBox(this->m_hWnd, _T("���֤�������"), _T("����"), MB_OK);
		return false;
	case ERROROVERDRAW:
		::MessageBox(this->m_hWnd, _T("�������˻�͸֧��"), _T("����"), MB_OK);
		return false;
	case NONEERROR:
		::MessageBox(this->m_hWnd, _T("���β����ɹ���"), _T("�ɹ�"), MB_OK);
		return true;
	default:
		return true;
	}
}

bool CMainMenu::PrintSrearchInfo(list<UserData> datas)
{
	if (!datas.empty())
	{
		CString message = _T("�𾴵Ŀͻ�����Ϊ����ѯ�������˻���Ϣ��");
		list<CString> messages;
		list<UserData>::iterator iter = datas.begin();
		while (iter != datas.end())
		{
			UserData tmp = *iter;
			CString onemessage;
			onemessage = _T("\n  ���룺\t") + tmp.number +
				_T("\n  �û�����\t") + tmp.username +
				_T("\n  ���֤���룺") + tmp.id +
				_T("\n  �ֻ����룺") + tmp.phone +
				_T("\n  ��ַ��\t") + tmp.address;
			messages.push_back(onemessage);
			iter++;
		}
		int i = 1;
		list<CString>::iterator iter_messages = messages.begin();
		while (iter_messages != messages.end())
		{
			CString num;
			num.Format(_T("%d"), i);
			CString tmp = *iter_messages;
			message = message + "\n" + _T("�˻�") + num + ':' + tmp;
			iter_messages++;
			i++;
		}
		::MessageBox(this->m_hWnd, message, _T("��Ϣ��ѯ"), MB_OK);
		return true;
	}
	return false;
}

void CMainMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &CMainMenu::OnBnClickedButtonRegister)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CMainMenu::OnBnClickedButtonCancle)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMainMenu::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_DRAW, &CMainMenu::OnBnClickedButtonDraw)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CMainMenu::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CMainMenu::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_TRANSFER, &CMainMenu::OnBnClickedTransfer)
END_MESSAGE_MAP()


// CMainMenu ��Ϣ�������


void CMainMenu::OnBnClickedButtonRegister()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRegister temp_register;
	if (temp_register.DoModal() == IDOK)
	{
		UserData data = temp_register.GetData();
		CString number = m_handle.Register(data);
		CString message = _T("�𾴵�") + data.username 
			+ _T("�ͻ���\n\t��ϲ��˳������!\n\t�����˻�Ϊ�� ") + number;
		::MessageBox(this->m_hWnd, message, _T("�����ɹ�"), MB_OK);
	}
}


void CMainMenu::OnBnClickedButtonCancle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCancle temp_cancle;
	if (temp_cancle.DoModal() == IDOK)
	{
		CString number = temp_cancle.GetNumber();
		CString password = temp_cancle.GetPassword();
		if (!CheckErrors_Print(m_handle.Cancle(number, password)))
			OnBnClickedButtonCancle();
	}
}


void CMainMenu::OnBnClickedButtonSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSave temp_save;
	if (temp_save.DoModal() == IDOK)
	{
		CString number = temp_save.GetNumber();
		CString password = temp_save.GetPassword();
		int money = temp_save.GetMoney();
		if (!CheckErrors_Print(m_handle.SaveMoney(number, password, money)))
			OnBnClickedButtonSave();
	}
}


void CMainMenu::OnBnClickedButtonDraw()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDraw temp_draw;
	if (temp_draw.DoModal() == IDOK)
	{
		CString number = temp_draw.GetNumber();
		CString password = temp_draw.GetPassword();
		int money = temp_draw.GetMoney();
		if (!CheckErrors_Print(m_handle.DrawMoney(number, password, money)))
			OnBnClickedButtonDraw();
	}
}


void CMainMenu::OnBnClickedButtonSearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSearch temp_search;
	if (temp_search.DoModal() == IDOK)
	{
		if (temp_search.IsMoney())
		{
			CSearchmoney temp_searchMoney;
			if (temp_searchMoney.DoModal() == IDOK)
			{
				CString number = temp_searchMoney.GetNumber();
				CString password = temp_searchMoney.GetPassword();
				int key = m_handle.SearchMoney(number, password);
				if (CheckErrors_Print(key))
				{
					CString money;
					money.Format(_T("%d"), key);
					CString message;
					message = _T("�˻�") + number + _T("���Ϊ ") + money + _T(" Ԫ��");
					::MessageBox(this->m_hWnd, message, _T("����ѯ"), MB_OK);
				}
				else
					OnBnClickedButtonSearch();
			}
		}
		if (temp_search.IsInfo())
		{
			CSearchinfo temp_searchinfo;
			if (temp_searchinfo.DoModal() == IDOK)
			{
				CString name = temp_searchinfo.GetName();
				CString id = temp_searchinfo.GetId();
				list<UserData> datas;
				if (CheckErrors_Print(m_handle.SearchInfo(name, id, datas)))
					PrintSrearchInfo(datas);
				else
					OnBnClickedButtonSearch();
			}
		}
	}
}


void CMainMenu::OnBnClickedTransfer()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTransfer temp_transfer;
	if (temp_transfer.DoModal() == IDOK)
	{
		CString selfnum = temp_transfer.GetSelfNum();
		CString password = temp_transfer.GetPassword();
		CString goalnum = temp_transfer.GetGoalNum();
		int money = temp_transfer.GetMoney();
		if (!CheckErrors_Print(m_handle.Transfer(selfnum, password, goalnum, money)))
			OnBnClickedTransfer();
	}
}


void CMainMenu::OnBnClickedButtonBack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if ((::MessageBox(this->m_hWnd, _T("ȷ���������η���"), _T("����"), MB_OKCANCEL)) == IDOK)
	{
		CWnd *parentWnd = this->GetParent();
		DestroyWindow();
		::MessageBox(parentWnd->GetSafeHwnd(), _T("��ӭ�ٴ�ʹ�ñ�ϵͳ��"), _T("��л"), MB_OK);
		m_visuable = false;
	}
}

