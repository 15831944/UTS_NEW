// UTOP_VCMMove.h : UTOP_VCMMove DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_VCMMoveApp
// �@��e�Č���Ո��� UTOP_VCMMove.cpp
//

class CUTOP_VCMMoveApp : public CWinApp
{
public:
	CUTOP_VCMMoveApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_VCMMoveApp theApp;