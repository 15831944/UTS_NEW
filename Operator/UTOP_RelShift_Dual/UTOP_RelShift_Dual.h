// UTOP_RelShift_Dual.h : UTOP_RelShift_Dual DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_RelShift_DualApp
// �@��e�Č���Ո��� UTOP_RelShift_Dual.cpp
//

class CUTOP_RelShift_DualApp : public CWinApp
{
public:
	CUTOP_RelShift_DualApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_RelShift_DualApp theApp;