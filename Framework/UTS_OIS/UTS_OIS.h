// UTS_OIS.h : UTS_OIS DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTS_OISApp
// �@��e�Č���Ո��� UTS_OIS.cpp
//

class CUTS_OISApp : public CWinApp
{
public:
	CUTS_OISApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTS_OISApp theApp;