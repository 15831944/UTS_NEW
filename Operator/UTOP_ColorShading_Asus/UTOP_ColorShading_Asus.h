// UTOP_ColorShading_Asus.h : UTOP_ColorShading_Asus DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_ColorShading_AsusApp
// �@��e�Č���Ո��� UTOP_ColorShading_Asus.cpp
//

class CUTOP_ColorShading_AsusApp : public CWinApp
{
public:
	CUTOP_ColorShading_AsusApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorShading_AsusApp theApp;