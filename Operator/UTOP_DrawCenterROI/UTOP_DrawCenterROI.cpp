// UTOP_DrawCenterROI.cpp : ���x DLL �ĳ�ʼ����ʽ��
//

#include "stdafx.h"
#include "UTOP_DrawCenterROI.h"

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

// CUTOP_DrawCenterROIApp

BEGIN_MESSAGE_MAP(CUTOP_DrawCenterROIApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_DrawCenterROIApp ����

CUTOP_DrawCenterROIApp::CUTOP_DrawCenterROIApp()
{
	// TODO: �ڴ˼��뽨����ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}


// �H�е�һ�� CUTOP_DrawCenterROIApp ���

CUTOP_DrawCenterROIApp theApp;


// CUTOP_DrawCenterROIApp ��ʼ�O��

BOOL CUTOP_DrawCenterROIApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
