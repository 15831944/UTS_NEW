// UTOP_UVC_EraseEEProm.h : UTOP_UVC_EraseEEProm DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_UVC_EraseEEPromApp
// �@��e�Č���Ո��� UTOP_UVC_EraseEEProm.cpp
//

class CUTOP_UVC_EraseEEPromApp : public CWinApp
{
public:
	CUTOP_UVC_EraseEEPromApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_UVC_EraseEEPromApp theApp;