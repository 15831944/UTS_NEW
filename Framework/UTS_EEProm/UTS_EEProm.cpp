// UTS_EEProm.cpp : ���x DLL �ĳ�ʼ����ʽ��
//

#include "stdafx.h"

#include "UTS_EEProm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����@? DLL �ǄӑB�،� MFC DLL �B�Y��
//		���N���@? DLL �R�����κΕ�����
//		MFC �Ȳ��ĺ�ʽ������?�ں�ʽһ�_�^���� AFX_MANAGE_STATE
//		�޼���
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// ��?��������ʽ���w
//		}
//
//		�@?�޼�һ��Ҫ���F��ÿһ?
//		��ʽ�У����܉���� MFC �ăȲ����@��ζ��
//		����?�Ǻ�ʽ�ȵĵ�һ??��ʽ
//		��������?���κ����?������ǰ��
//		�������?�Ľ�?��ʽ���ܕ��a���� MFC
//		DLL �Ȳ��ĺ��С�
//
//		?��? MFC ���g��ʾ 33 �� 58 �е�
//		??�Y�ϡ�
//

// CUTS_EEPromApp

BEGIN_MESSAGE_MAP(CUTS_EEPromApp, CWinApp)
END_MESSAGE_MAP()


// CUTS_EEPromApp ��?

CUTS_EEPromApp::CUTS_EEPromApp()
{
	// TODO: �ڴ˼��뽨?��ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}


// �H�е�һ? CUTS_EEPromApp ���

CUTS_EEPromApp theApp;


// CUTS_EEPromApp ��ʼ�O��

BOOL CUTS_EEPromApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
