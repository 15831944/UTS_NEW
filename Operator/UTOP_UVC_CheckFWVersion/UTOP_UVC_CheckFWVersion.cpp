// UTOP_UVC_CheckFWVersion.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UTOP_UVC_CheckFWVersion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CUTOP_UVC_CheckFWVersionApp

BEGIN_MESSAGE_MAP(CUTOP_UVC_CheckFWVersionApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_UVC_CheckFWVersionApp ����

CUTOP_UVC_CheckFWVersionApp::CUTOP_UVC_CheckFWVersionApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUTOP_UVC_CheckFWVersionApp ����

CUTOP_UVC_CheckFWVersionApp theApp;


// CUTOP_UVC_CheckFWVersionApp ��ʼ��

BOOL CUTOP_UVC_CheckFWVersionApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
