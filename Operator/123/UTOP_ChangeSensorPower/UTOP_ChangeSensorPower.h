// UTOP_ChangeSensorPower.h : UTOP_ChangeSensorPower DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTOP_ChangeSensorPowerApp
// �@??�e��?��?��? UTOP_ChangeSensorPower.cpp
//

class CUTOP_ChangeSensorPowerApp : public CWinApp
{
public:
	CUTOP_ChangeSensorPowerApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ChangeSensorPowerApp theApp;