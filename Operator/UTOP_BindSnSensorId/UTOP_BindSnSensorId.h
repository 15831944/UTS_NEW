// UTOP_BindSnSensorId.h : UTOP_BindSnSensorId DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_BindSnSensorIdApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_BindSnSensorId.cpp
//

class CUTOP_BindSnSensorIdApp : public CWinApp
{
public:
	CUTOP_BindSnSensorIdApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_BindSnSensorIdApp theApp;
