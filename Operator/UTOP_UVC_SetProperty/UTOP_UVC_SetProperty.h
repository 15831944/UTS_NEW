// UTOP_UVC_SetProperty.h : UTOP_UVC_SetProperty DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_UVC_SetPropertyApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_UVC_SetProperty.cpp
//

class CUTOP_UVC_SetPropertyApp : public CWinApp
{
public:
	CUTOP_UVC_SetPropertyApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_UVC_SetPropertyApp theApp;
