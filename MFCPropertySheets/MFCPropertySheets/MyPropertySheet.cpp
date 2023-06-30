#include "pch.h"
#include "MyPropertySheet.h"


MyPropertySheet::MyPropertySheet() : CMFCPropertySheet(_T("Main tab window")) {

	AddPage(&p1);
	AddPage(&p2);
	SetLook(CMFCPropertySheet::PropSheetLook_OneNoteTabs);
}

BEGIN_MESSAGE_MAP(MyPropertySheet,CMFCPropertySheet)
	
END_MESSAGE_MAP()

MyPropertySheet::~MyPropertySheet()
{


}

void MyPropertySheet::DoDataExchange(CDataExchange * pDX) {

	CMFCPropertySheet::DoDataExchange(pDX);
}

BOOL MyPropertySheet::OnInitDialog() {

	CMFCPropertySheet::OnInitDialog();
	return 1;

}

BOOL MyPropertySheet::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (wParam == IDOK) { // OK button clicked...
		//if (!ValidSettings(true)) return TRUE; // NOT valid, prevent further processing.

		int pageIndex = GetActiveIndex();
		if (p1.m_edit1CtrlVal.IsEmpty()) {

			if (AfxMessageBox(L"You have not entered atleast one control",
				MB_OK | MB_ICONERROR)) {

				//GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
				return TRUE;
			}
		}
		else if (!p1.m_enableValue) {

			if (AfxMessageBox(L"You have not entered atleast one control",
				MB_OK | MB_ICONERROR)) {

				//GotoDlgCtrl(GetDlgItem(IDC_CHECK1));
				return TRUE;
			}
		}
		else if (p2.m_edit1CtrlVal.IsEmpty()) {

			if (AfxMessageBox(L"You have not entered atleast one control",
				MB_OK | MB_ICONERROR)) {

				p2.m_isSetFocusOnEditCtrl = TRUE;
				p2.m_isSetFocusOnCheckBox = FALSE;
				bool bRet = SetActivePage(&p2);
				return TRUE;
			}
		}
		else if (!p2.m_enableVal) {

			if (AfxMessageBox(L"You have not entered atleast one control",
				MB_OK | MB_ICONERROR)) {

				p2.m_isSetFocusOnEditCtrl = TRUE;
				p2.m_isSetFocusOnCheckBox = FALSE;
				SetActivePage(&p2);
				return TRUE;
			}
		}
	}
	return CMFCPropertySheet::OnCommand(wParam, lParam);
}