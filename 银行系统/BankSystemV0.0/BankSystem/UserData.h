
#pragma once
#include "stdafx.h"
#include <list>
using namespace std;

class CUserData
{
public:
	CUserData();
	~CUserData();
private:
	list<UserData> m_Datas;
	list<CString> m_DeldNums;

protected:
	

public:
	void AddUserData(UserData data);
	void DelUserData(int key);
	void SaveMoney(int key, int money);
	bool DrawMoney(int key, int money);
	void AddDeldNums(CString num);
	list<UserData> GetUserDatas() { return m_Datas; }
	CString GetOneDeldNums();
	list<CString> GetDeldNums() { return m_DeldNums; }

};