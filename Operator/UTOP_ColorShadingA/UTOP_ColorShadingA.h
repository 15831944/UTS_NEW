// UTOP_ColorShadingA.h : UTOP_ColorShadingA DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_ColorShadingAApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_ColorShadingA.cpp
//

class CUTOP_ColorShadingAApp : public CWinApp
{
public:
	CUTOP_ColorShadingAApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorShadingAApp theApp;
