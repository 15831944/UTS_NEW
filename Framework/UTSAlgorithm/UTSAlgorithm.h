// UTSAlgorithm.h : UTSAlgorithm DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTSAlgorithmApp
// �йش���ʵ�ֵ���Ϣ������� UTSAlgorithm.cpp
//

class CUTSAlgorithmApp : public CWinApp
{
public:
	CUTSAlgorithmApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
