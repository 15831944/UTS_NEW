// UTOP_Shading_Smartisan.h : UTOP_Shading_Smartisan DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTOP_Shading_SmartisanApp
// �@??�e��?��?��? UTOP_Shading_Smartisan.cpp
//

class CUTOP_Shading_SmartisanApp : public CWinApp
{
public:
	CUTOP_Shading_SmartisanApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_Shading_SmartisanApp theApp;