// UTOP_DrawCenterROI.h : UTOP_DrawCenterROI DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_DrawCenterROIApp
// �@��e�Č���Ո��� UTOP_DrawCenterROI.cpp
//

class CUTOP_DrawCenterROIApp : public CWinApp
{
public:
	CUTOP_DrawCenterROIApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_DrawCenterROIApp theApp;