// UTOP_RelShift_Single.h : UTOP_RelShift_Single DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTOP_RelShift_SingleApp
// �@??�e��?��?��? UTOP_RelShift_Single.cpp
//

class CUTOP_RelShift_SingleApp : public CWinApp
{
public:
	CUTOP_RelShift_SingleApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_RelShift_SingleApp theApp;