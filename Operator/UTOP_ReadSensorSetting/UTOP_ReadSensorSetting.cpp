// UTOP_ReadSensorSetting.cpp : ���x DLL �ĳ�ʼ����ʽ��
//

#include "stdafx.h"
#include "UTOP_ReadSensorSetting.h"

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

// CUTOP_ReadSensorSettingApp

BEGIN_MESSAGE_MAP(CUTOP_ReadSensorSettingApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_ReadSensorSettingApp ����

CUTOP_ReadSensorSettingApp::CUTOP_ReadSensorSettingApp()
{
	// TODO: �ڴ˼��뽨����ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}


// �H�е�һ�� CUTOP_ReadSensorSettingApp ���

CUTOP_ReadSensorSettingApp theApp;


// CUTOP_ReadSensorSettingApp ��ʼ�O��

BOOL CUTOP_ReadSensorSettingApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
