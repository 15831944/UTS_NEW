// UTOP_LightOff.h : UTOP_LightOff DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_LightOffApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_LightOff.cpp
//

class CUTOP_LightOffApp : public CWinApp
{
public:
	CUTOP_LightOffApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_LightOffApp theApp;
