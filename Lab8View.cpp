//B711050, 김혁진
// Lab8View.cpp: CLab8View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Lab8.h"
#endif

#include "Lab8Doc.h"
#include "Lab8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab8View

IMPLEMENT_DYNCREATE(CLab8View, CFormView)

BEGIN_MESSAGE_MAP(CLab8View, CFormView)
	ON_BN_CLICKED(IDC_RADIO_MAN, &CLab8View::OnBnClickedRadioMan)
	ON_BN_CLICKED(IDC_RADIO_GIRL, &CLab8View::OnBnClickedRadioGirl)
	ON_EN_CHANGE(IDC_EDIT_ADDRESS, &CLab8View::OnEnChangeEditAddress)
	ON_BN_CLICKED(IDC_CHECK_AGREE, &CLab8View::OnBnClickedCheckAgree)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CLab8View::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_NUMBER, &CLab8View::OnEnChangeEditNumber)
	ON_CBN_SELCHANGE(IDC_COMBO_DEPARTMENT, &CLab8View::OnCbnSelchangeComboDepartment)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CLab8View::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CLab8View::OnBnClickedButtonLeft)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// CLab8View 생성/소멸

CLab8View::CLab8View() noexcept
	: CFormView(IDD_LAB8_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLab8View::~CLab8View()
{
}

void CLab8View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_edit_name);
	DDX_Control(pDX, IDC_EDIT_NUMBER, m_edit_id);
	DDX_Control(pDX, IDC_COMBO_DEPARTMENT, m_combo_dep);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, m_edit_address);
	DDX_Control(pDX, IDC_RADIO_MAN, m_radio_man);
	DDX_Control(pDX, IDC_RADIO_GIRL, m_radio_girl);
	DDX_Control(pDX, IDC_CHECK_AGREE, m_check_agree);
	DDX_Control(pDX, IDC_LIST_HATE, m_left);
	DDX_Control(pDX, IDC_LIST_LIKE, m_right);
	DDX_Control(pDX, IDC_SCROLLBAR_RED, m_red);
}

BOOL CLab8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CLab8View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CLab8Doc* pDoc = GetDocument();

	m_edit_name.SetWindowTextW(pDoc->m_data.m_name);
	m_edit_address.SetWindowTextW(pDoc->m_data.m_address);
	m_edit_id.SetWindowTextW(pDoc->m_data.m_id);
	m_radio_man.SetCheck(pDoc->m_data.m_man);
	m_radio_girl.SetCheck(pDoc->m_data.m_girl);
	m_check_agree.SetCheck(pDoc->m_data.m_agree);
	m_combo_dep.SetCurSel(pDoc->m_data.m_dep);

	m_left.ResetContent();
	m_right.ResetContent();

	m_left.AddString(CString("운동"));
	m_left.AddString(CString("음악듣기"));
	m_left.AddString(CString("책읽기"));
	m_left.AddString(CString("산책하기"));

	m_red.SetScrollRange(0, 255);
	m_red.SetScrollPos(100);

}


// CLab8View 진단

#ifdef _DEBUG
void CLab8View::AssertValid() const
{
	CFormView::AssertValid();
}

void CLab8View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLab8Doc* CLab8View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab8Doc)));
	return (CLab8Doc*)m_pDocument;
}
#endif //_DEBUG


// CLab8View 메시지 처리기


void CLab8View::OnBnClickedRadioMan()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CLab8Doc* pDoc = GetDocument();
	if (pDoc->m_data.m_girl) {
		m_radio_girl.SetCheck(0);
		pDoc->m_data.m_girl = m_radio_girl.GetCheck();
		pDoc->m_data.m_man = m_radio_man.GetCheck();
		pDoc->SetModifiedFlag();
	}
}


void CLab8View::OnBnClickedRadioGirl()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLab8Doc* pDoc = GetDocument();
	if (pDoc->m_data.m_man) {
		m_radio_man.SetCheck(0);
		pDoc->m_data.m_man = m_radio_man.GetCheck();
		pDoc->m_data.m_girl = m_radio_girl.GetCheck();
		pDoc->SetModifiedFlag();
	}
}


void CLab8View::OnEnChangeEditAddress()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	CLab8Doc* pDoc = GetDocument();
	CString str;

	m_edit_address.GetWindowText(str);
	pDoc->m_data.m_address = str;
	pDoc->SetModifiedFlag();
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CLab8View::OnBnClickedCheckAgree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLab8Doc* pDoc = GetDocument();
	pDoc->m_data.m_agree = m_check_agree.GetCheck();
	pDoc->SetModifiedFlag();
}


void CLab8View::OnEnChangeEditName()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	CLab8Doc* pDoc = GetDocument();
	CString str;

	m_edit_name.GetWindowText(str);
	pDoc->m_data.m_name = str;
	pDoc->SetModifiedFlag();
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CLab8View::OnEnChangeEditNumber()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	CLab8Doc* pDoc = GetDocument();
	CString str;

	m_edit_id.GetWindowText(str);
	pDoc->m_data.m_id = str;
	pDoc->SetModifiedFlag();
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CLab8View::OnCbnSelchangeComboDepartment()
{
	CLab8Doc* pDoc = GetDocument();

	int nIndex = m_combo_dep.GetCurSel();
	pDoc->m_data.m_dep = nIndex;
	pDoc->SetModifiedFlag();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CLab8View::OnBnClickedButtonRight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nIndex = m_left.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_left.GetText(nIndex, str);
		m_left.DeleteString(nIndex);
		m_left.SetCurSel(nIndex); // 삭제된 다음 위치의 항목이 자동 선택됨
		m_right.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("오른쪽에서 왼쪽으로..."));
	}
}


void CLab8View::OnBnClickedButtonLeft()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nIndex = m_right.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_right.GetText(nIndex, str);
		m_right.DeleteString(nIndex);
		m_right.SetCurSel(nIndex); // 삭제된 다음 위치의 항목이 자동 선택됨
		m_left.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("왼쪽에서 오른쪽으로..."));
	}
}


void CLab8View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int pos;
	int delta = 0;
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar != NULL) { // 스크롤바 컨트롤에서 발생한 메시지이면...
		if (pScrollBar->GetSafeHwnd() == m_red.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_PAGELEFT:
				delta = -20;
				break;
			case SB_PAGERIGHT:
				delta = 20;
				break;
			case SB_LINELEFT:
				delta = -4;
				break;
			case SB_LINERIGHT:
				delta = 4;
				break;
			}
			if (delta != 0) {
				pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}
			Invalidate();
		}
	}
	else // 윈도우 스크롤바에서 발생한 메시지이면...
		CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}
