#pragma once
#include <afx.h>
class CMyData :
    public CObject
{
    DECLARE_SERIAL(CMyData);

public:
    CMyData();
    ~CMyData();
    void Serialize(CArchive& ar);
    void initialize();

    CString m_name, m_address, m_id;
    int m_agree, m_man, m_girl, m_dep;

};

