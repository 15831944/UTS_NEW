// UTOP_MTF_Ref.h : UTOP_MTF_Ref DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_MTF_RefApp
// �@��e�Č���Ո��� UTOP_MTF_Ref.cpp
//

class CUTOP_MTF_RefApp : public CWinApp
{
public:
	CUTOP_MTF_RefApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
extern CUTOP_MTF_RefApp theApp;