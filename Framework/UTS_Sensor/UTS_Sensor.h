// UTS_Sensor.h : UTS_Sensor DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTS_SensorApp
// �йش���ʵ�ֵ���Ϣ������� UTS_Sensor.cpp
//

class CUTS_SensorApp : public CWinApp
{
public:
	CUTS_SensorApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
