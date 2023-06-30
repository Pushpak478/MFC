#pragma once
#include <afxwin.h>
#include "MFCApplication2.h"
#include "resource.h"

class MFCModalessClass : public CDialog {
public:
	MFCModalessClass();
	BOOL Create(CWnd* pParent);
	void OnCancel();
	void OnOK();
	void OnDestroy();
	// Dialog Data
	enum { IDD = IDD_MODELESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	void InitializeComboBox();


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);

	//afx_msg void OnPaint();
	//afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CWnd* m_pParent = nullptr;





	afx_msg void OnBnClickedCheck1();
	CButton m_checkCtrl;
	BOOL m_checkCtrlVal = 0;
	CEdit m_edit1Ctrl;
	CEdit m_edit2Ctrl;
	CComboBox m_comboCtrl;
};

