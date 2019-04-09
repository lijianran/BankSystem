
#pragma once
//数据交互类
#include "UserData.h"
#include <io.h>
#include <direct.h>
#include <fstream>
#include <iomanip>
#include <list>
using namespace std;

class COperator
{
public:
	COperator();
	~COperator(){}
public:
	CString Register(UserData data);
	int Cancle(CString num, CString pwd);
	int SaveMoney(CString num, CString pwd, int money);
	int DrawMoney(CString num, CString pwd, int money);
	int SearchMoney(CString num, CString pwd);
	int SearchInfo(CString name, CString id, list<UserData>& return_datas);
	int Transfer(CString self, CString pwd, CString goal, int money);

	void SaveData();
	void ReadData();
protected:
	CString ProduceNum();
	bool CreateFolder(char fileName[]);

protected:
	CUserData m_UserDatas;
	int m_number;

};