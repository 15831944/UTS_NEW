// UTOP_ChangeSensorPower.cpp : ���x DLL �ĳ�ʼ����ʽ��
//

#include "stdafx.h"
#include "UTOP_ChangeSensorPower.h"

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

// CUTOP_ChangeSensorPowerApp

BEGIN_MESSAGE_MAP(CUTOP_ChangeSensorPowerApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_ChangeSensorPowerApp ����

CUTOP_ChangeSensorPowerApp::CUTOP_ChangeSensorPowerApp()
{
	// TODO: �ڴ˼��뽨����ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}


// �H�е�һ�� CUTOP_ChangeSensorPowerApp ���

CUTOP_ChangeSensorPowerApp theApp;


// CUTOP_ChangeSensorPowerApp ��ʼ�O��

BOOL CUTOP_ChangeSensorPowerApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
