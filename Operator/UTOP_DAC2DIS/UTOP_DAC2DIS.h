// UTOP_DAC2DIS.h : UTOP_DAC2DIS DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_DAC2DISApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_DAC2DIS.cpp
//

class CUTOP_DAC2DISApp : public CWinApp
{
public:
	CUTOP_DAC2DISApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_DAC2DISApp theApp;
