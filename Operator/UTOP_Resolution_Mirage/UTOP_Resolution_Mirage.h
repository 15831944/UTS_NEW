// UTOP_Resolution_Mirage.h : UTOP_Resolution_Mirage DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTOP_Resolution_MirageApp
// �@??�e��?��?��? UTOP_Resolution_Mirage.cpp
//

class CUTOP_Resolution_MirageApp : public CWinApp
{
public:
	CUTOP_Resolution_MirageApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_Resolution_MirageApp theApp;