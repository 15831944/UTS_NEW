// UTOP_OC_Smartisan.h : UTOP_OC_Smartisan DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_OC_SmartisanApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_OC_Smartisan.cpp
//

class CUTOP_OC_SmartisanApp : public CWinApp
{
public:
	CUTOP_OC_SmartisanApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_OC_SmartisanApp theApp;
