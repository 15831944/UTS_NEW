// UTOP_StopAux.h : UTOP_StopAux DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_StopAuxApp
// �@��e�Č���Ո��� UTOP_StopAux.cpp
//

class CUTOP_StopAuxApp : public CWinApp
{
public:
	CUTOP_StopAuxApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_StopAuxApp theApp;