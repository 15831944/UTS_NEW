// UTOP_UVC_CheckFWVersion.h : UTOP_UVC_CheckFWVersion DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_UVC_CheckFWVersionApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_UVC_CheckFWVersion.cpp
//

class CUTOP_UVC_CheckFWVersionApp : public CWinApp
{
public:
	CUTOP_UVC_CheckFWVersionApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
extern CUTOP_UVC_CheckFWVersionApp theApp;
