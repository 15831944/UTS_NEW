// UTOP_ChangeOutputMode.h : UTOP_ChangeOutputMode DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_ChangeOutputModeApp
// �@��e�Č���Ո��� UTOP_ChangeOutputMode.cpp
//

class CUTOP_ChangeOutputModeApp : public CWinApp
{
public:
	CUTOP_ChangeOutputModeApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ChangeOutputModeApp theApp;