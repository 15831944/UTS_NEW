// UTS_VCM.h : UTS_VCM DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTS_VCMApp
// �йش���ʵ�ֵ���Ϣ������� UTS_VCM.cpp
//

class CUTS_VCMApp : public CWinApp
{
public:
	CUTS_VCMApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
