// UTOP_SwitchDevice.h : UTOP_SwitchDevice DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_SwitchDeviceApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_SwitchDevice.cpp
//

class CUTOP_SwitchDeviceApp : public CWinApp
{
public:
	CUTOP_SwitchDeviceApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_SwitchDeviceApp theApp;
