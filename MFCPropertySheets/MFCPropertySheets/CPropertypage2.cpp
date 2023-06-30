// CPropertypage2.cpp : implementation file
//

#include "pch.h"
#include "MFCPropertySheets.h"
#include "MyPropertySheet.h"
#include "CPropertypage2.h"


// CPropertypage2

IMPLEMENT_DYNAMIC(CPropertypage2, CMFCPropertyPage)

CPropertypage2::CPropertypage2() :
	CMFCPropertyPage(CPropertypage2::IDD)
	, m_edit1CtrlVal(_T(""))
	, m_enableVal(FALSE) {

}

CPropertypage2::~CPropertypage2()
{
}

void CPropertypage2::DoDataExchange(CDataExchange * pDX) {

	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1Ctrl);
	DDX_Text(pDX, IDC_EDIT1, m_edit1CtrlVal);
	DDX_Check(pDX, IDC_CHECK1, m_enableVal);
}

BOOL CPropertypage2::OnSetActive() {

	SetModified(FALSE);

	if (m_isSetFocusOnCheckBox) {

		m_isSetFocusOnCheckBox = FALSE;
		GotoDlgCtrl(GetDlgItem(IDC_CHECK1));
	}
	if (m_isSetFocusOnEditCtrl) {

		m_isSetFocusOnEditCtrl = FALSE;
		GotoDlgCtrl(GetDlgItem(IDC_CHECK1));

	} 

	MyPropertySheet* pParent = static_cast<MyPropertySheet*>(GetParent());
	if (pParent != nullptr) {

		m_edit1CtrlVal = pParent->p1.m_edit1CtrlVal;
		m_enableVal = pParent->p1.m_enableValue;
		UpdateData(FALSE);
	}

	return CMFCPropertyPage::OnSetActive();
}

BOOL CPropertypage2::OnInitDialog() {

	CMFCPropertyPage::OnInitDialog();

	UpdateData(FALSE);
	return 1;
}


BEGIN_MESSAGE_MAP(CPropertypage2, CMFCPropertyPage)
	ON_BN_CLICKED(IDC_CHECK1, &CPropertypage2::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_EDIT1, &CPropertypage2::OnChanged)
END_MESSAGE_MAP()



// CPropertypage2 message handlers




void CPropertypage2::OnBnClickedCheck1()
{
	SetModified(TRUE);
}

void CPropertypage2::OnChanged()
{
	SetModified(TRUE);

}

BOOL CPropertypage2::OnKillActive() {

	UpdateData(TRUE);

	if (m_edit1CtrlVal.IsEmpty()) {

		if (AfxMessageBox(L"You have not entered atleast one control",
			MB_OK | MB_ICONERROR)) {

			GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
			return 0;
		}
	}
	else if (!m_enableVal) {

		if (AfxMessageBox(L"You have not entered atleast one control",
			MB_OK | MB_ICONERROR)) {

			GotoDlgCtrl(GetDlgItem(IDC_CHECK1));
			return 0;
		}
	}
		
	return CMFCPropertyPage::OnKillActive();
}
