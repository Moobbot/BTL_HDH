
// BTL_HeDieuHanh.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CBTLHeDieuHanhApp:
// See BTL_HeDieuHanh.cpp for the implementation of this class
//

class CBTLHeDieuHanhApp : public CWinApp
{
public:
	CBTLHeDieuHanhApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CBTLHeDieuHanhApp theApp;
