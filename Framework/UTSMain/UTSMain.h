
// UTSMain.h : UTSMain Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

// CUTSMainApp:
// �йش����ʵ�֣������ UTSMain.cpp
//

class CUTSMainApp : public CWinApp
{
public:
	CUTSMainApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	DECLARE_MESSAGE_MAP()

};

extern CUTSMainApp theApp;
