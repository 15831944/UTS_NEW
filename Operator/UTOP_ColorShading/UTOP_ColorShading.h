// UTOP_ColorShading.h : UTOP_ColorShading DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_ColorShadingApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_ColorShading.cpp
//

class CUTOP_ColorShadingApp : public CWinApp
{
public:
	CUTOP_ColorShadingApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorShadingApp theApp;
