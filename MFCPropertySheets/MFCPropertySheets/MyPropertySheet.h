#pragma once
#include <afxpropertysheet.h>
#include "CPropPage1.h"
#include "CPropertypage2.h"

class MyPropertySheet : public CMFCPropertySheet {

	//DECLARE_DYNAMIC(MyPropertySheet)

	public:
		MyPropertySheet();
		virtual ~MyPropertySheet();

	public:
		CPropPage1		p1;
		CPropertypage2 p2;
		
	protected:
		virtual void DoDataExchange(CDataExchange* pDX);
		BOOL OnInitDialog();
		afx_msg BOOL OnCommand(WPARAM wParam, LPARAM lParam);
		DECLARE_MESSAGE_MAP();


	};


