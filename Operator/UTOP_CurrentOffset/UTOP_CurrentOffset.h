// UTOP_CurrentOffset.h : UTOP_CurrentOffset DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_CurrentOffsetApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_CurrentOffset.cpp
//

class CUTOP_CurrentOffsetApp : public CWinApp
{
public:
	CUTOP_CurrentOffsetApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CurrentOffsetApp theApp;
