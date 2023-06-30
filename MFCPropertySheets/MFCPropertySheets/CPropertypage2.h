#pragma once


// CPropertypage2
#include "resource.h"

class CPropertypage2 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CPropertypage2)
	enum {IDD = IDD_PROPPAGE_2};

public:
	CPropertypage2();
	virtual ~CPropertypage2();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	afx_msg BOOL OnSetActive();
	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1Ctrl;
	CString m_edit1CtrlVal;
	BOOL m_isSetFocusOnEditCtrl = false;
	BOOL m_isSetFocusOnCheckBox = false;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnChanged();
	afx_msg BOOL OnKillActive();
	BOOL m_enableVal;
};


