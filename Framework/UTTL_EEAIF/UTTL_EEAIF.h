// UTTL_EEAIF.h : UTTL_EEAIF DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTTL_EEAIFApp
// �йش���ʵ�ֵ���Ϣ������� UTTL_EEAIF.cpp
//

class CUTTL_EEAIFApp : public CWinApp
{
public:
	CUTTL_EEAIFApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTTL_EEAIFApp theApp;
