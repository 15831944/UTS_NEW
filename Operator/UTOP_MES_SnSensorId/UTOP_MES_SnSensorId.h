// UTOP_MES_SnSensorId.h : UTOP_MES_SnSensorId DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_MES_SnSensorIdApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_MES_SnSensorId.cpp
//

class CUTOP_MES_SnSensorIdApp : public CWinApp
{
public:
	CUTOP_MES_SnSensorIdApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_MES_SnSensorIdApp theApp;
