// UTOP_TvDistortion.h : UTOP_TvDistortion DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_TvDistortionApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_TvDistortion.cpp
//

class CUTOP_TvDistortionApp : public CWinApp
{
public:
	CUTOP_TvDistortionApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_TvDistortionApp theApp;
