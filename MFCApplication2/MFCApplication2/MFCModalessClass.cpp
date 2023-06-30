#include "pch.h"
#include "MFCModalessClass.h"
#include "MFCApplication2Dlg.h"



MFCModalessClass::MFCModalessClass() : CDialog(MFCModalessClass::IDD) {

}


BEGIN_MESSAGE_MAP(MFCModalessClass, CDialog) 

	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()

	ON_BN_CLICKED(IDC_CHECK1, &MFCModalessClass::OnBnClickedCheck1)
END_MESSAGE_MAP()

BOOL MFCModalessClass::Create(CWnd* pParent) {

	this->m_pParent = pParent;
	return CDialog::Create(MFCModalessClass::IDD, m_pParent);
}

void MFCModalessClass::OnCancel() {

	DestroyWindow();
}

void MFCModalessClass::OnOK() {

	UpdateData(TRUE);
	DestroyWindow();
}
void MFCModalessClass::OnDestroy() {

	m_pParent->SendMessage(UWM_MODELESS_CLOSED);
	CDialog::OnDestroy();
}

void MFCModalessClass::DoDataExchange(CDataExchange * pDX) {

	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_CHECK1, m_checkCtrl);
	DDX_Check(pDX, IDC_CHECK1, m_checkCtrlVal);
	DDX_Control(pDX, IDC_EDIT1, m_edit1Ctrl);
	DDX_Control(pDX, IDC_EDIT2, m_edit2Ctrl);
	DDX_Control(pDX, IDC_COMBO1, m_comboCtrl);
}

void MFCModalessClass::InitializeComboBox() {

	CString str;
	
	for (int i = 0; i < 30; i++) {

		str.Format(_T("%d"), i);
		m_comboCtrl.AddString(str);
		str = "";
	}
	m_comboCtrl.AddString(_T("Show"));
	m_comboCtrl.AddString(_T("Hide"));
}

BOOL MFCModalessClass::OnInitDialog() {

	CDialog::OnInitDialog();

	CMFCApplication2Dlg* pParent = static_cast<CMFCApplication2Dlg*>(m_pParent);

	m_checkCtrlVal = pParent->m_enableVal;
	m_edit1Ctrl.SetWindowTextW(pParent->m_editCtrlVal);
	m_edit2Ctrl.SetWindowTextW(pParent->m_editCtrl2Val);

	InitializeComboBox();
	m_comboCtrl.SetCurSel(pParent->m_comboCtrlval);

	UpdateData(FALSE);

	return 0;
}

void MFCModalessClass::OnSysCommand(UINT nID, LPARAM lParam) {


}






void MFCModalessClass::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
}
