// UTSFramework.h : UTSFramework DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTSFrameworkApp
// �йش���ʵ�ֵ���Ϣ������� UTSFramework.cpp
//

class CUTSFrameworkApp : public CWinApp
{
public:
	CUTSFrameworkApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
