// UTOP_ChangeSensorSlaveAddr.h : UTOP_ChangeSensorSlaveAddr DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_ChangeSensorSlaveAddrApp
// �@��e�Č���Ո��� UTOP_ChangeSensorSlaveAddr.cpp
//

class CUTOP_ChangeSensorSlaveAddrApp : public CWinApp
{
public:
	CUTOP_ChangeSensorSlaveAddrApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ChangeSensorSlaveAddrApp theApp;