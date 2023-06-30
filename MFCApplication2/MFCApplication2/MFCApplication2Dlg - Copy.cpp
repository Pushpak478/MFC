
// MFCApplication2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
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
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication2Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication2Dlg::OnEnChangedEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication2Dlg::OnCbnSelChangedCombo1)
	ON_EN_KILLFOCUS(IDC_EDIT1,&CMFCApplication2Dlg::OnEnKillFocusEdit1)
END_MESSAGE_MAP()


// CMFCApplication2Dlg message handlers
void CMFCApplication2Dlg::OnEnChangedEdit1() {

	UpdateData(TRUE);
	m_editCtrl2Val = m_editCtrlVal;
	UpdateData(FALSE);
}

void CMFCApplication2Dlg::OnEnKillFocusEdit1() {

	UpdateData(TRUE);
	m_editCtrl2Val = m_editCtrlVal + _T("12");
	UpdateData(FALSE);
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

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	

	if (m_enableVal) {
		m_editCtrl.EnableWindow(TRUE);
	}
	else {
		m_editCtrl.EnableWindow(FALSE);
	}

	GotoDlgCtrl(GetDlgItem(IDC_CHECK1));
	UpdateData(FALSE);
	pBox->SetCurSel(2);

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

	return FALSE;  // return TRUE  unless you set the focus to a control
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

