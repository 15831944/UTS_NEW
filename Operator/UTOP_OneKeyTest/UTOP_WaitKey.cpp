// UTOP_WaitKey.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UTOP_WaitKey.h"

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

// CUTOP_WaitKeyApp

BEGIN_MESSAGE_MAP(CUTOP_WaitKeyApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_WaitKeyApp ����

CUTOP_WaitKeyApp::CUTOP_WaitKeyApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUTOP_WaitKeyApp ����

CUTOP_WaitKeyApp theApp;


// CUTOP_WaitKeyApp ��ʼ��

BOOL CUTOP_WaitKeyApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
