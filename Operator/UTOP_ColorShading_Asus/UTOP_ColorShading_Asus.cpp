// UTOP_ColorShading_Asus.cpp : ���x DLL �ĳ�ʼ����ʽ��
//

#include "stdafx.h"
#include "UTOP_ColorShading_Asus.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����@�� DLL �ǄӑB�،� MFC DLL �B�Y��
//		���N���@�� DLL �R�����κΕ�����
//		MFC �Ȳ��ĺ�ʽ��������ں�ʽһ�_�^���� AFX_MANAGE_STATE
//		�޼���
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// ��̎��������ʽ���w
//		}
//
//		�@���޼�һ��Ҫ���F��ÿһ��
//		��ʽ�У����܉���� MFC �ăȲ����@��ζ��
//		������Ǻ�ʽ�ȵĵ�һ�����ʽ
//		������������κ����׃������ǰ��
//		����������Ľ�����ʽ���ܕ��a���� MFC
//		DLL �Ȳ��ĺ��С�
//
//		Ո��� MFC ���g��ʾ 33 �� 58 �е�
//		Ԕ���Y�ϡ�
//

// CUTOP_ColorShading_AsusApp

BEGIN_MESSAGE_MAP(CUTOP_ColorShading_AsusApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_ColorShading_AsusApp ����

CUTOP_ColorShading_AsusApp::CUTOP_ColorShading_AsusApp()
{
	// TODO: �ڴ˼��뽨����ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}


// �H�е�һ�� CUTOP_ColorShading_AsusApp ���

CUTOP_ColorShading_AsusApp theApp;


// CUTOP_ColorShading_AsusApp ��ʼ�O��

BOOL CUTOP_ColorShading_AsusApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
