// UTOP_Record.h : UTOP_Record DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_RecordApp
// �o�����O����@�аѾ\ UTOP_Record.cpp
//

class CUTOP_RecordApp : public CWinApp
{
public:
	CUTOP_RecordApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


extern CUTOP_RecordApp theApp;
