// UTOP_LightOn.h : UTOP_LightOn DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_LightOnApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_LightOn.cpp
//

class CUTOP_LightOnApp : public CWinApp
{
public:
	CUTOP_LightOnApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_LightOnApp theApp;
