// UTOP_Play.h : UTOP_Play DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_PlayApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_Play.cpp
//

class CUTOP_PlayApp : public CWinApp
{
public:
	CUTOP_PlayApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_PlayApp theApp;
