// UTOP_AutoExposure.h : UTOP_AutoExposure DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTOP_AutoExposureApp
// �@??�e��?��?��? UTOP_AutoExposure.cpp
//

class CUTOP_AutoExposureApp : public CWinApp
{
public:
	CUTOP_AutoExposureApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_AutoExposureApp theApp;