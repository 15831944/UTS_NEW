
// UTSLauncher.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTSLauncherApp:
// �йش����ʵ�֣������ UTSLauncher.cpp
//

class CUTSLauncherApp : public CWinApp
{
public:
	CUTSLauncherApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CUTSLauncherApp theApp;