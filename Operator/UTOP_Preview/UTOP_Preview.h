// UTOP_Preview.h : UTOP_Preview DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_PreviewApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_Preview.cpp
//

class CUTOP_PreviewApp : public CWinApp
{
public:
	CUTOP_PreviewApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_PreviewApp theApp;
