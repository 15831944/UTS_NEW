// UTOP_Microphone.h : UTOP_Microphone DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_MicrophoneApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_Microphone.cpp
//

class CUTOP_MicrophoneApp : public CWinApp
{
public:
	CUTOP_MicrophoneApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_MicrophoneApp theApp;
