// UTOP_CorrectionPD.h : UTOP_CorrectionPD DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_CorrectionPDApp
// �@��e�Č���Ո��� UTOP_CorrectionPD.cpp
//

class CUTOP_CorrectionPDApp : public CWinApp
{
public:
	CUTOP_CorrectionPDApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CorrectionPDApp theApp;