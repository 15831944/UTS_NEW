// UTDV_UVC.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UTDV_UVC.h"

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

// CUTDV_UVCApp

BEGIN_MESSAGE_MAP(CUTDV_UVCApp, CWinApp)
END_MESSAGE_MAP()


// CUTDV_UVCApp ����

CUTDV_UVCApp::CUTDV_UVCApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUTDV_UVCApp ����

CUTDV_UVCApp theApp;


// CUTDV_UVCApp ��ʼ��

BOOL CUTDV_UVCApp::InitInstance()
{
	CWinApp::InitInstance();
    //COM Library Intialization
    if (FAILED(CoInitialize(NULL))) /*, COINIT_APARTMENTTHREADED)))*/
    {
        return FALSE;
    }
	return TRUE;
}


int CUTDV_UVCApp::ExitInstance()
{
    // TODO: �ڴ����ר�ô����/����û���
    CoUninitialize();
    return CWinApp::ExitInstance();
}
