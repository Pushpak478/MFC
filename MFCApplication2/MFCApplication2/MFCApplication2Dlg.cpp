
// MFCApplication2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "MFCModalessClass.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
	ON_BN_CLICKED(IDC_BUTTON3, &CAboutDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplication2Dlg dialog



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, m_enableVal(FALSE)
	, m_editCtrlVal(_T(""))
	, m_comboCtrlval(0)
	, m_editCtrl2Val(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	pModeless = nullptr;
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_enablectrl);
	DDX_Check(pDX, IDC_CHECK1, m_enableVal);
	DDX_Control(pDX, IDC_EDIT1, m_editCtrl);
	//DDX_Control(pDX, IDC_COMBO1, m_comboCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_editCtrlVal);
	DDX_Control(pDX, IDC_EDIT2, m_editCtrl2);
	DDX_Text(pDX, IDC_EDIT2, m_editCtrl2Val);
	DDX_CBIndex(pDX, IDC_COMBO1, m_comboCtrlval);
	DDX_Control(pDX, IDC_SPIN1, m_spinCtrl);
	DDX_Text(pDX, IDC_EDIT3, m_spinCtrlVal);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(UWM_MODELESS_CLOSED, &CMFCApplication2Dlg::OnModelessClosed)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication2Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication2Dlg::OnEnChangedEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication2Dlg::OnCbnSelChangedCombo1)
	ON_EN_KILLFOCUS(IDC_EDIT1,&CMFCApplication2Dlg::OnEnKillFocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT3, &CMFCApplication2Dlg::OnEnKillFocusEdit3)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication2Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication2Dlg::OnEnChangeEdit2)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN1, &CMFCApplication2Dlg::OnNMOutofmemorySpin1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplication2Dlg message handlers
void CMFCApplication2Dlg::OnEnChangedEdit1() {

	UpdateData(TRUE);
	m_editCtrl2Val = m_editCtrlVal;
	UpdateData(FALSE);
}

void CMFCApplication2Dlg::OnEnKillFocusEdit1() {

	m_editCtrl.GetWindowTextW(m_editTempVal);
	int length = m_editTempVal.GetLength();
	CCHAR ch;
	CString temp = _T("");
	
	for (int i = 0; i < length; i++) {
		ch = m_editTempVal[i];
		if (!((ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z'))) {

			int input = AfxMessageBox(L"You have entered the wrong input",
				MB_YESNO | MB_ICONERROR);
			if (input == IDYES) {
				if(m_prevVal.IsEmpty())
					m_editCtrl.SetWindowTextW(temp);
				else m_editCtrl.SetWindowTextW(m_prevVal);
			}
			else if (input == IDNO) {
				m_editCtrl.SetWindowTextW(_T(""));
			}
			break;
		}
		temp += ch;
	}
	m_prevVal = temp;
}

void CMFCApplication2Dlg::OnEnKillFocusEdit3() {

	//int value = m_spinCtrl.GetPos();
	UpdateData(TRUE);
	int value = _ttoi(m_spinCtrlVal);
	int lowerbound = 0, upperbound = 0;
	m_spinCtrl.GetRange(lowerbound, upperbound);
	if (value < lowerbound || value >= upperbound) {

		if (AfxMessageBox(_T("You have entered the number out of the range"), MB_OK | MB_ICONERROR) == IDOK) {
			m_spinCtrl.SetPos(lowerbound);
		}
	}
}

void CMFCApplication2Dlg::OnCbnSelChangedCombo1() {

	UpdateData(TRUE);
	CString str;

	static_cast<CComboBox*>(GetDlgItem(IDC_COMBO1))->GetLBText(m_comboCtrlval, str);
	if (str == _T("Show")) {
		GetDlgItem(IDC_CHECK2)->ShowWindow(SW_SHOW);
	}
	else if (str == _T("Hide")) {
		GetDlgItem(IDC_CHECK2)->ShowWindow(SW_HIDE);
	}
}

LRESULT CMFCApplication2Dlg::OnModelessClosed(WPARAM, LPARAM)
{
	if (pModeless != nullptr) {

		GetDlgItem(IDC_COMBO1)->EnableWindow(pModeless->m_checkCtrlVal);
		pModeless = nullptr;
		return 0;
	}	
}

void CMFCApplication2Dlg::InitializeComboBox() {

	CString str;
	CComboBox* pBox = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	if (pBox != nullptr) {

		for (int i = 0; i < 30; i++) {

			str.Format(_T("%d"), i);
			pBox->AddString(str);
			str = "";
		}
	}
	pBox->AddString(_T("Show"));
	pBox->AddString(_T("Hide"));
	pBox->SetCurSel(2);
}

void CMFCApplication2Dlg::InitializeSpinControl() {

	m_spinCtrl.SetBuddy(GetDlgItem(IDC_EDIT3));

	UDACCEL udAccel;

	int SizeOfAccel = sizeof(UDACCEL);
	udAccel.nSec = 10;
	udAccel.nInc = 5;

	m_spinCtrl.SetAccel(SizeOfAccel, &udAccel);
	m_spinCtrl.SetRange(5, 1000);
	m_spinCtrl.SetPos(5);
}


BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitializeComboBox();
	InitializeSpinControl();

	if (m_enableVal) {

		m_editCtrl.EnableWindow(TRUE);
	} else {
		m_editCtrl.EnableWindow(FALSE);
	}
	

	UpdateData(FALSE);
	
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here

	m_enableVal = !m_enableVal;
	GetDlgItem(IDC_EDIT1)->EnableWindow(m_enableVal);
	//UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	m_bHideStaticTextVal = !m_bHideStaticTextVal;
	if (m_bHideStaticTextVal) {
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("Show Text"));
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	}
	else {
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("Hide Text"));
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	}
}



void CMFCApplication2Dlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCApplication2Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCApplication2Dlg::OnNMOutofmemorySpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(_T("You have entered the number out of the range"), MB_OK | MB_ICONERROR);

}


void CAboutDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	pModeless = new MFCModalessClass();
	if (pModeless != nullptr) {
		BOOL bRet = pModeless->Create(this);
		if (!bRet) {
			return;
		}
		pModeless->ShowWindow(SW_SHOW);
	}
}

BOOL CMFCApplication2Dlg::PreTranslateMessage(MSG* pMsg) {


	if (m_editCtrl.m_hWnd == pMsg->hwnd) {

		if (pMsg->message == WM_CHAR) {

			if (!(pMsg->wParam >= 97 && pMsg->wParam <= 122)) {
				return TRUE;
			}
		}

		if (pMsg->message == WM_KEYDOWN) {

			if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
			{
				return TRUE;                // Do not process further
			}
			if (pMsg->wParam == VK_TAB) {
				
				//GotoDlgCtrl(GetDlgItem(IDC_SPIN1));
				//m_spinCtrl.SetFocus();
				GotoDlgCtrl(GetDlgItem(IDC_EDIT3));
				return TRUE;
			}
		}
	}
	return FALSE;
	//return
}
