// UTOP_ColorUniformity.h : UTOP_ColorUniformity DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_ColorUniformityApp
// �@��e�Č���Ո��� UTOP_ColorUniformity.cpp
//

class CUTOP_ColorUniformityApp : public CWinApp
{
public:
	CUTOP_ColorUniformityApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorUniformityApp theApp;
