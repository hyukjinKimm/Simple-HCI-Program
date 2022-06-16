#include "pch.h"
#include "CMyData.h"

IMPLEMENT_SERIAL(CMyData, CObject, 1)

CMyData::CMyData()
{
	m_name = m_address = m_id= CString("");
	m_man = 1;
	m_girl = 0;
	m_agree = 0;
	m_dep = -1;
	
}
CMyData::~CMyData()
{

}

void CMyData::initialize()
{
	m_name = m_address = m_id =  CString("");
	m_man = 1;
	m_girl = 0;
	m_agree = 0;
	m_dep = -1;
}

void CMyData::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << m_name << m_address << m_id << m_man << m_girl << m_agree << m_dep;
	}
	else
	{
		ar >> m_name >> m_address >> m_id >> m_man >> m_girl >> m_agree >> m_dep;
	}
}