// UTOP_SFC_CheckRoute.h : UTOP_SFC_CheckRoute DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_SFC_CheckRouteApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_SFC_CheckRoute.cpp
//

class CUTOP_SFC_CheckRouteApp : public CWinApp
{
public:
	CUTOP_SFC_CheckRouteApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_SFC_CheckRouteApp theApp;
