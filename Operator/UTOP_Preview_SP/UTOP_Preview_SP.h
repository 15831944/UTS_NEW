// UTOP_Preview_SP.h : UTOP_Preview_SP DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_Preview_SPApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_Preview_SP.cpp
//

class CUTOP_Preview_SPApp : public CWinApp
{
public:
	CUTOP_Preview_SPApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_Preview_SPApp theApp;
