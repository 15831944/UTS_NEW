// UTOP_GetSN.h : UTOP_GetSN DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTOP_GetSNApp
// �@??�e��?��?��? UTOP_GetSN.cpp
//

class CUTOP_GetSNApp : public CWinApp
{
public:
	CUTOP_GetSNApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_GetSNApp theApp;