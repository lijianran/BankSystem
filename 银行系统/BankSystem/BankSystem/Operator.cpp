
#include "stdafx.h"
#include "Operator.h"

COperator::COperator()
{
	m_number = 1;
}

CString COperator::Register(UserData data)
{
	CString num = ProduceNum();
	data.number = num;
	m_UserDatas.AddUserData(data);
	return num;
}

int COperator::Cancle(CString num, CString pwd)
{
	list<UserData> datas = m_UserDatas.GetUserDatas();
	int i = 0;
	if (!datas.empty())
	{
		list<UserData>::iterator iter = datas.begin();
		while (iter != datas.end())
		{
			UserData tmp = *iter;
			if (tmp.number == num)
			{
				if (tmp.password == pwd)
				{
					m_UserDatas.DelUserData(i);
					return NONEERROR;
				}
				else
					return ERRORPASSWORD;
			}
			else
			{
				i++;
				iter++;
			}
		}
		return ERRORNUMBER;
	}
	else
		return ERRORZERO;
}

int COperator::SaveMoney(CString num, CString pwd, int money)
{
	list<UserData> datas = m_UserDatas.GetUserDatas();
	int i = 0;
	if (!datas.empty())
	{
		list<UserData>::iterator iter = datas.begin();
		while (iter != datas.end())
		{
			UserData tmp = *iter;
			if (tmp.number == num)
			{
				if (tmp.password == pwd)
				{
					m_UserDatas.SaveMoney(i, money);
					return NONEERROR;
				}
				else
					return ERRORPASSWORD;
			}
			else
			{
				i++;
				iter++;
			}
		}
		return ERRORNUMBER;
	}
	else
		return ERRORZERO;
}

int COperator::DrawMoney(CString num, CString pwd, int money)
{
	list<UserData> datas = m_UserDatas.GetUserDatas();
	int i = 0;
	if (!datas.empty())
	{
		list<UserData>::iterator iter = datas.begin();
		while (iter != datas.end())
		{
			UserData tmp = *iter;
			if (tmp.number == num)
			{
				if (tmp.password == pwd)
				{
					if (m_UserDatas.DrawMoney(i, money))
						return NONEERROR;
					else
						return ERROROVERDRAW;
				}
				else
					return ERRORPASSWORD;
			}
			else
			{
				i++;
				iter++;
			}
		}
		return ERRORNUMBER;
	}
	else
		return ERRORZERO;
}

int COperator::SearchMoney(CString num, CString pwd)
{
	list<UserData> datas = m_UserDatas.GetUserDatas();
	if (!datas.empty())
	{
		list<UserData>::iterator iter = datas.begin();
		while (iter != datas.end())
		{
			UserData tmp = *iter;
			if (tmp.number == num)
			{
				if (tmp.password == pwd)
					return tmp.money;
				else
					return ERRORPASSWORD;
			}
			else
				iter++;
		}
		return ERRORNUMBER;
	}
	else
		return ERRORZERO;
}

int COperator::SearchInfo(CString name, CString id, list<UserData>& return_datas)
{
	list<UserData> datas = m_UserDatas.GetUserDatas();
	if (!datas.empty())
	{
		list<UserData>::iterator iter = datas.begin();
		while (iter != datas.end())
		{
			UserData tmp = *iter;
			if (tmp.username == name)
			{
				if (tmp.id == id)
				{
					return_datas.push_back(tmp);
					iter++;
				}
				else
					return ERRORIDNUM;
			}
			else
				iter++;
		}
		if (return_datas.size() == 0)
			return ERRORUSERNAME;
		else
			return NONEERROR+1;
	}
	else
		return ERRORZERO;
}

int COperator::Transfer(CString self, CString pwd, CString goal, int money)
{
	list<UserData> datas = m_UserDatas.GetUserDatas();
	bool flag_self = false, flag_goal = false;
	int index_self = 0, index_goal = 0;
	if (!datas.empty())
	{
		list<UserData>::iterator iter = datas.begin();
		int i = 0;
		while (iter != datas.end())
		{
			UserData tmp = *iter;
			if (tmp.number == self)
			{
				if (tmp.password == pwd)
				{
					flag_self = true;
					index_self = i;
				}
				else
					return ERRORPASSWORD;
			}
			if (tmp.number == goal)
			{
				flag_goal = true;
				index_goal = i;
			}
			if (flag_self && flag_goal)
				break;
			else
			{
				iter++;
				i++;
			}
		}
		if (!flag_self)
			return ERRORNUMBER;
		if (!flag_goal)
			return ERRORTRANSNUM;
		if (!m_UserDatas.DrawMoney(index_self, money))
			return ERROROVERDRAW;
		else
			m_UserDatas.SaveMoney(index_goal, money);
		return NONEERROR;
	}
	else
		return ERRORZERO;
}

CString COperator::ProduceNum()
{
	list<CString> numbers = m_UserDatas.GetDeldNums();
	CString number;
	if (numbers.size() != 0)
	{
		number = m_UserDatas.GetOneDeldNums();
		return number;
	}
	else
	{
		number.Format(_T("%d"), (m_number + 10000));
		m_number++;
		return number;
	}
}

bool COperator::CreateFolder(char fileName[])
{
	//char *fileName = ".\\1\\2\\3\\UserData.txt", *tag;
	char *tag;
	for (tag = fileName; *tag; tag++)
	{
		if (*tag == '\\')
		{
			char buf[1000], path[1000];
			strcpy(buf, fileName);
			buf[strlen(fileName) - strlen(tag) + 1] = NULL;
			strcpy(path, buf);
			if (_access(path, 6) == -1)
			{
				_mkdir(path);
				return true;
			}
		}
	}
	return false;
}


void COperator::SaveData()
{
	ofstream outfile1;
	outfile1.open(".\\datas\\UserData.txt", ios::out | ios::trunc);
	if(outfile1.is_open())
	{
		outfile1 << setiosflags(ios_base::left) << setw(20) << "用户姓名";
		outfile1 << setiosflags(ios_base::left) << setw(20) << "身份证号";
		outfile1 << setiosflags(ios_base::left) << setw(20) << "用户账号";
		outfile1 << setiosflags(ios_base::left) << setw(20) << "用户密码";
		outfile1 << setiosflags(ios_base::left) << setw(20) << "账户余额";
		outfile1 << setiosflags(ios_base::left) << setw(20) << "手机号码";
		outfile1 << setiosflags(ios_base::left) << setw(20) << "用户住址";
		int form[7] = { 20,20,20,20,20,20,20 };
		list<UserData> datas = m_UserDatas.GetUserDatas();
		if (!datas.empty())
		{
			list<UserData>::iterator iter = datas.begin();
			while (iter != datas.end())
			{
				UserData tmp = *iter;
				CString money;
				money.Format(_T("%d"), tmp.money);
				CString datas[7] = { tmp.username, tmp.id, tmp.number, 
					tmp.password, money,  tmp.phone, tmp.address };
				outfile1 << '\n' ;
				for (int i = 0; i < 7; i++)
				{
					int len = WideCharToMultiByte(CP_ACP, 0, datas[i], -1, NULL, 0, NULL, NULL);
					char *buffer = new char[len + 1];
					WideCharToMultiByte(CP_ACP, 0, datas[i], -1, buffer, len, NULL, NULL);
					outfile1 << setiosflags(ios_base::left) << setw(form[i]) << buffer;
					delete[] buffer;
				}
				iter++;
			}
		}
		outfile1.close();
	}

	ofstream outfile2;
	outfile2.open(".\\datas\\DataBase.txt", ios::out | ios::trunc);
	if (outfile2.is_open())
	{
		outfile2 << "注册账户：\t" << (m_number + 10000);
		outfile2 << "\n注销后的账户：";
		list<CString> datas = m_UserDatas.GetDeldNums();
		if (!datas.empty())
		{
			list<CString>::iterator iter = datas.begin();
			while (iter != datas.end())
			{
				CString tmp = *iter;
				int len = WideCharToMultiByte(CP_ACP, 0, tmp, -1, NULL, 0, NULL, NULL);
				char *buffer = new char[len + 1];
				WideCharToMultiByte(CP_ACP, 0, tmp, -1, buffer, len, NULL, NULL);
				outfile2 << "\n" << buffer;
				delete[] buffer;
				iter++;
			}
		}
		outfile2.close();
	}
}


void COperator::ReadData()
{
	ifstream infile;
	infile.open(".\\datas\\UserData.txt", ios::in);
	if (infile.is_open())
	{
		char buffer[256];
		char str[32];
		infile.getline(buffer, 256);
		while (!infile.eof())
		{
			UserData tmp;
			CString money;
			infile >> str;
			tmp.username = str;
			infile >> str;
			tmp.id = str;
			infile >> str;
			tmp.number = str;
			infile >> str;
			tmp.password = str;
			infile >> str;
			money = str;
			tmp.money = _ttoi(money);
			infile >> str;
			tmp.phone = str;
			infile >> str;
			tmp.address = str;
			m_UserDatas.AddUserData(tmp);
			infile.getline(buffer, 256);
		}
		infile.close();
	}
	else
		CreateFolder(".\\datas\\");
	ifstream infile2;
	infile2.open(".\\datas\\DataBase.txt", ios::in);
	if (infile2.is_open())
	{
		char buffer[256];
		infile2 >> buffer;
		char number[32];
		infile2 >> number;
		CString num, deletednum;
		num = number;
		m_number = _ttoi(num) - 10000;
		infile2 >> buffer;
		while (!infile2.eof())
		{
			infile2 >> number;
			deletednum = number;
			m_UserDatas.AddDeldNums(deletednum);
		}
		infile2.close();
	}
}

