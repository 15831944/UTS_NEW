// UTOP_UVC_LEDControl.h : UTOP_UVC_LEDControl DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_UVC_LEDControlApp
// �@��e�Č���Ո��� UTOP_UVC_LEDControl.cpp
//

class CUTOP_UVC_LEDControlApp : public CWinApp
{
public:
	CUTOP_UVC_LEDControlApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_UVC_LEDControlApp theApp;