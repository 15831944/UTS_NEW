// UTDV_File.h : UTDV_File DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTDV_FileApp
// �йش���ʵ�ֵ���Ϣ������� UTDV_File.cpp
//

class CUTDV_FileApp : public CWinApp
{
public:
	CUTDV_FileApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTDV_FileApp theApp;
