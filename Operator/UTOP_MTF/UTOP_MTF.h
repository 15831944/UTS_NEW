// UTOP_MTF.h : UTOP_MTF DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_MTFApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_MTF.cpp
//

class CUTOP_MTFApp : public CWinApp
{
public:
	CUTOP_MTFApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_MTFApp theApp;
