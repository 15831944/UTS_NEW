// UTOP_ShakerInit.h : UTOP_ShakerInit DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_ShakerInitApp
// �@��e�Č���Ո��� UTOP_ShakerInit.cpp
//

class CUTOP_ShakerInitApp : public CWinApp
{
public:
	CUTOP_ShakerInitApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


extern CUTOP_ShakerInitApp theApp;