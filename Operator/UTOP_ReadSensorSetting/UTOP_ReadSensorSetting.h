// UTOP_ReadSensorSetting.h : UTOP_ReadSensorSetting DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_ReadSensorSettingApp
// �@��e�Č���Ո��� UTOP_ReadSensorSetting.cpp
//

class CUTOP_ReadSensorSettingApp : public CWinApp
{
public:
	CUTOP_ReadSensorSettingApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ReadSensorSettingApp theApp;