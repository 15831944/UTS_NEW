// UTOP_RelShift_SFR_Single.h : UTOP_RelShift_SFR_Single DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_RelShift_SFR_SingleApp
// �o�����O����@�аѾ\ UTOP_RelShift_SFR_Single.cpp
//

class CUTOP_RelShift_SFR_SingleApp : public CWinApp
{
public:
	CUTOP_RelShift_SFR_SingleApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_RelShift_SFR_SingleApp theApp;