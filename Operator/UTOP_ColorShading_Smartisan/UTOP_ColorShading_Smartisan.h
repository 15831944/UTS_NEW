// UTOP_ColorShading_Smartisan.h : UTOP_ColorShading_Smartisan DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_ColorShading_SmartisanApp
// �@��e�Č���Ո��� UTOP_ColorShading_Smartisan.cpp
//

class CUTOP_ColorShading_SmartisanApp : public CWinApp
{
public:
	CUTOP_ColorShading_SmartisanApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorShading_SmartisanApp theApp;