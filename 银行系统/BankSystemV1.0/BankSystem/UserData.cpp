#include "stdafx.h"
#include "UserData.h"

CUserData::CUserData()
{

}
CUserData::~CUserData()
{

}

void CUserData::AddUserData(UserData data)
{
	UserData user;
	user.username = data.username;
	user.id = data.id;
	user.phone = data.phone;
	user.address = data.address;
	user.password = data.password;
	user.number = data.number;
	user.money = data.money;
	m_Datas.push_back(user);
}

void CUserData::DelUserData(int key)
{
	list<UserData>::iterator iter = m_Datas.begin();
	for (int i = 0; i < key; i++)
		iter++;
	m_DeldNums.push_back(iter->number);
	m_Datas.erase(iter);
}

void CUserData::SaveMoney(int key, int money)
{
	list<UserData>::iterator iter = m_Datas.begin();
	for (int i = 0; i < key; i++)
		iter++;
	iter->money += money;
}

bool CUserData::DrawMoney(int key, int money)
{
	list<UserData>::iterator iter = m_Datas.begin();
	for (int i = 0; i < key; i++)
		iter++;
	if (iter->money >= money)
		iter->money -= money;
	else
		return false;
	return true;
}

void CUserData::AddDeldNums(CString num)
{
	m_DeldNums.push_back(num);
}

CString CUserData::GetOneDeldNums()
{
	CString fornt = m_DeldNums.front();
	m_DeldNums.pop_front();
	return fornt;
}
