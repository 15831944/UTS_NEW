// UTOP_Shading_Asus.h : UTOP_Shading_Asus DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTOP_Shading_AsusApp
// �@??�e��?��?��? UTOP_Shading_Asus.cpp
//

class CUTOP_Shading_AsusApp : public CWinApp
{
public:
	CUTOP_Shading_AsusApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_Shading_AsusApp theApp;