// UTOP_EraseEEProm_V5U.h : UTOP_EraseEEProm_V5U DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_EraseEEProm_V5UApp
// �@��e�Č���Ո��� UTOP_EraseEEProm_V5U.cpp
//

class CUTOP_EraseEEProm_V5UApp : public CWinApp
{
public:
	CUTOP_EraseEEProm_V5UApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_EraseEEProm_V5UApp theApp;