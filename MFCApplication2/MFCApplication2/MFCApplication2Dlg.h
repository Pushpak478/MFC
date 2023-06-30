
// MFCApplication2Dlg.h : header file
//

#pragma once

#include "MFCModalessClass.h"

#define UWM_MODELESS_CLOSED (WM_APP + 200) // for some value n, such as 200

// CMFCApplication2Dlg dialog
class CMFCApplication2Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnEnChangedEdit1();
	afx_msg void OnEnKillFocusEdit1();
	afx_msg void OnEnKillFocusEdit3();
	afx_msg void OnCbnSelChangedCombo1();
	afx_msg LRESULT OnModelessClosed(WPARAM, LPARAM);
	void InitializeComboBox();
	void InitializeSpinControl();
	
	CButton m_enablectrl;
	MFCModalessClass* pModeless = nullptr;
	BOOL m_enableVal;
	CEdit m_editCtrl;
	CString m_editCtrlVal;
	CString m_editTempVal;
	CString m_prevVal = _T("");
	CEdit m_editCtrl2;
	CString m_editCtrl2Val;
	CComboBox m_comboCtrl;
	INT m_comboCtrlval;
	BOOL m_bHideStaticTextVal;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
	CSpinButtonCtrl m_spinCtrl;
	CString m_spinCtrlVal = _T("");
	afx_msg void OnNMOutofmemorySpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton3();

	BOOL PreTranslateMessage(MSG * pMsg);
	
};
