// UTOP_UVC_LEDTest.h : UTOP_UVC_LEDTest DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_UVC_LEDTestApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_UVC_LEDTest.cpp
//

class CUTOP_UVC_LEDTestApp : public CWinApp
{
public:
	CUTOP_UVC_LEDTestApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
extern CUTOP_UVC_LEDTestApp theApp;

