// UTOP_OST.h : UTOP_OST DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_OSTApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_OST.cpp
//

class CUTOP_OSTApp : public CWinApp
{
public:
	CUTOP_OSTApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_OSTApp theApp;
