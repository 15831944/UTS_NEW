// UTOP_RelShift_MTK.h : UTOP_RelShift_MTK DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_RelShift_MTKApp
// �@��e�Č���Ո��� UTOP_RelShift_MTK.cpp
//

class CUTOP_RelShift_MTKApp : public CWinApp
{
public:
	CUTOP_RelShift_MTKApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_RelShift_MTKApp theApp;
