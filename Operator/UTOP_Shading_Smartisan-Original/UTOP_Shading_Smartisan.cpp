// UTOP_Shading_Smartisan.cpp : ���x DLL �ĳ�ʼ����ʽ��
//

#include "stdafx.h"
#include "UTOP_Shading_Smartisan.h"

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

// CUTOP_Shading_SmartisanApp

BEGIN_MESSAGE_MAP(CUTOP_Shading_SmartisanApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_Shading_SmartisanApp ����

CUTOP_Shading_SmartisanApp::CUTOP_Shading_SmartisanApp()
{
	// TODO: �ڴ˼��뽨����ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}


// �H�е�һ�� CUTOP_Shading_SmartisanApp ���

CUTOP_Shading_SmartisanApp theApp;


// CUTOP_Shading_SmartisanApp ��ʼ�O��

BOOL CUTOP_Shading_SmartisanApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
