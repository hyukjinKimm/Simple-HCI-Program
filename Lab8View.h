
// Lab8View.h: CLab8View 클래스의 인터페이스
//

#pragma once


class CLab8View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CLab8View() noexcept;
	DECLARE_DYNCREATE(CLab8View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_LAB8_FORM };
#endif

// 특성입니다.
public:
	CLab8Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CLab8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit_name;
	CEdit m_edit_id;
	CComboBox m_combo_dep;
	CEdit m_edit_address;
	CButton m_radio_man;
	CButton m_radio_girl;
	CButton m_check_agree;
	afx_msg void OnBnClickedRadioMan();
	afx_msg void OnBnClickedRadioGirl();
	afx_msg void OnEnChangeEditAddress();
	afx_msg void OnBnClickedCheckAgree();
	afx_msg void OnEnChangeEditName();
	afx_msg void OnEnChangeEditNumber();
	CListBox m_left;
	CListBox m_right;
	CScrollBar m_red;
	afx_msg void OnCbnSelchangeComboDepartment();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

#ifndef _DEBUG  // Lab8View.cpp의 디버그 버전
inline CLab8Doc* CLab8View::GetDocument() const
   { return reinterpret_cast<CLab8Doc*>(m_pDocument); }
#endif

