// UTOP_RS232Release.h : UTOP_RS232Release DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_RS232ReleaseApp
// �@��e�Č���Ո��� UTOP_RS232Release.cpp
//

class CUTOP_RS232ReleaseApp : public CWinApp
{
public:
	CUTOP_RS232ReleaseApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_RS232ReleaseApp theApp;