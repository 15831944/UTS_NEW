// UTOP_ColorAccuracy.h : UTOP_ColorAccuracy DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTOP_ColorAccuracyApp
// �@??�e��?��?��? UTOP_ColorAccuracy.cpp
//

class CUTOP_ColorAccuracyApp : public CWinApp
{
public:
	CUTOP_ColorAccuracyApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorAccuracyApp theApp;