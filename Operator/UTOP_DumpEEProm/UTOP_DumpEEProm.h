// UTOP_DumpEEProm.h : UTOP_DumpEEProm DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_DumpEEPromApp
// �@��e�Č���Ո��� UTOP_DumpEEProm.cpp
//

class CUTOP_DumpEEPromApp : public CWinApp
{
public:
	CUTOP_DumpEEPromApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_DumpEEPromApp theApp;