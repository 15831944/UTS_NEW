// UTTL_EEAIF.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UTTL_EEAIF.h"

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

// CUTTL_EEAIFApp

BEGIN_MESSAGE_MAP(CUTTL_EEAIFApp, CWinApp)
END_MESSAGE_MAP()


// CUTTL_EEAIFApp ����

CUTTL_EEAIFApp::CUTTL_EEAIFApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUTTL_EEAIFApp ����

CUTTL_EEAIFApp theApp;


// CUTTL_EEAIFApp ��ʼ��

BOOL CUTTL_EEAIFApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
