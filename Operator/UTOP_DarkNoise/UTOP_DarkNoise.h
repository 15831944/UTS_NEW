// UTOP_DarkNoise.h : UTOP_DarkNoise DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_DarkNoiseApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_DarkNoise.cpp
//

class CUTOP_DarkNoiseApp : public CWinApp
{
public:
	CUTOP_DarkNoiseApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_DarkNoiseApp theApp;
