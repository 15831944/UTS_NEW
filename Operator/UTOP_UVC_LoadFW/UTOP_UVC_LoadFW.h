// UTOP_UVC_LoadFW.h : UTOP_UVC_LoadFW DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_UVC_LoadFWApp
// �@��e�Č���Ո��� UTOP_UVC_LoadFW.cpp
//

class CUTOP_UVC_LoadFWApp : public CWinApp
{
public:
	CUTOP_UVC_LoadFWApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
extern CUTOP_UVC_LoadFWApp theApp;