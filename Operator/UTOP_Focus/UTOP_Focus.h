// UTOP_Focus.h : UTOP_Focus DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_FocusApp
// �@��e�Č���Ո��� UTOP_Focus.cpp
//

class CUTOP_FocusApp : public CWinApp
{
public:
	CUTOP_FocusApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_FocusApp theApp;