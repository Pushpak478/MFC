// CPropPage1.cpp : implementation file
//

#include "pch.h"
#include "MFCPropertySheets.h"
#include "MyPropertySheet.h"
#include "CPropPage1.h"


// CPropPage1

IMPLEMENT_DYNAMIC(CPropPage1, CMFCPropertyPage)

CPropPage1::CPropPage1() :CMFCPropertyPage(CPropPage1::IDD)
, m_edit1CtrlVal(_T(""))
, m_enableValue(FALSE)
{

}

CPropPage1::~CPropPage1()
{
}

void CPropPage1::DoDataExchange(CDataExchange * pDX) {

	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1Ctrl);
	DDX_Text(pDX, IDC_EDIT1, m_edit1CtrlVal);
	DDX_Check(pDX, IDC_CHECK1, m_enableValue);
}

BOOL CPropPage1::OnInitDialog() {

	CMFCPropertyPage::OnInitDialog();
	return 1;
}

BOOL CPropPage1::PreTranslateMessage(MSG* pMsg) {


	if (m_edit1Ctrl.m_hWnd == pMsg->hwnd) {

		if (pMsg->message == WM_KEYDOWN) {

			if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
			{
				return TRUE;                // Do not process further
			}

			CString	temp = _T("");
			for (int i = 0; i < m_edit1CtrlVal.GetLength(); i++) {
				if (!(m_edit1CtrlVal[i] > 'a' && m_edit1CtrlVal[i] < 'z')) {

					pMsg->wParam = NULL;
					m_edit1Ctrl.SetWindowTextW(temp);
					GotoDlgCtrl(GetDlgItem(IDC_CHECK1));
					return TRUE;
				}
				temp += m_edit1CtrlVal[i];
			}
			
		}
	}
	return FALSE;
	//return CMFCPropertyPage::PreTranslateMessage(pMsg);
}


BEGIN_MESSAGE_MAP(CPropPage1, CMFCPropertyPage)ON_EN_CHANGE(IDC_EDIT1, &CPropPage1::OnEnChangeEdit1)
	
	ON_BN_CLICKED(IDC_CHECK1, &CPropPage1::OnChanged)
END_MESSAGE_MAP()



// CPropPage1 message handlers
void CPropPage1::OnChanged() {

	SetModified(TRUE);
}



void CPropPage1::OnEnChangeEdit1()
{
	SetModified(TRUE);
	UpdateData(TRUE);
}

BOOL CPropPage1::OnKillActive() {

	UpdateData(TRUE);
	static bool isFirst = false;

	if (!isFirst) {
		isFirst = true;
		return 1;
	}

	if (m_edit1CtrlVal.IsEmpty()) {

		if (AfxMessageBox(L"You have not entered atleast one control",
			MB_OK | MB_ICONERROR)) {

			GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
			return 0;
		}
	}
	else if (!m_enableValue) {

		if (AfxMessageBox(L"You have not entered atleast one control",
			MB_OK | MB_ICONERROR)) {

			GotoDlgCtrl(GetDlgItem(IDC_CHECK1));
			return 0;
		}
	}
	return CMFCPropertyPage::OnKillActive() ;
}
BOOL CPropPage1::OnSetActive() {

	SetModified(FALSE);
	MyPropertySheet* pParent = static_cast<MyPropertySheet*>(GetParent());
	if (pParent != nullptr) {

		m_edit1CtrlVal = pParent->p2.m_edit1CtrlVal;
		m_enableValue = pParent->p2.m_enableVal;
		UpdateData(FALSE);
	}
	return CMFCPropertyPage::OnSetActive();

}

void CPropPage1::OnOK() {

	CMFCPropertyPage::OnOK();
}
