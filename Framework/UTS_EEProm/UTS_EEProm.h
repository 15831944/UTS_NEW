// UTS_EEProm.h : UTS_EEProm DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��?


// CUTS_EEPromApp
// �@??�e��?��?��? UTS_EEProm.cpp
//

class CUTS_EEPromApp : public CWinApp
{
public:
	CUTS_EEPromApp();

// ��?
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
