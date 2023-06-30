#pragma once


// CPropPage1
#include "resource.h"

class CPropPage1 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CPropPage1)
	enum {IDD = IDD_PROPPAGE_1};

public:
	CPropPage1();
	virtual ~CPropPage1();

protected:
	virtual void DoDataExchange(CDataExchange* pDX); 
	BOOL OnInitDialog();
	BOOL PreTranslateMessage(MSG * pMsg);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg BOOL OnKillActive();
	afx_msg BOOL OnSetActive();
	afx_msg void OnOK();
	afx_msg void OnChanged();
	CEdit m_edit1Ctrl;
	CString m_edit1CtrlVal;
	BOOL m_enableValue;
};


