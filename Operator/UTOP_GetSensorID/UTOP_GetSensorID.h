// UTOP_GetSensorID.h : UTOP_GetSensorID DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_GetSensorIDApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_GetSensorID.cpp
//

class CUTOP_GetSensorIDApp : public CWinApp
{
public:
	CUTOP_GetSensorIDApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_GetSensorIDApp theApp;
