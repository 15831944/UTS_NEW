// UTOP_CreateMemory.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UTOP_CreateMemory.h"

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

// CUTOP_CreateMemoryApp

BEGIN_MESSAGE_MAP(CUTOP_CreateMemoryApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_CreateMemoryApp ����

CUTOP_CreateMemoryApp::CUTOP_CreateMemoryApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUTOP_CreateMemoryApp ����

CUTOP_CreateMemoryApp theApp;


// CUTOP_CreateMemoryApp ��ʼ��

BOOL CUTOP_CreateMemoryApp::InitInstance()
{
	CWinApp::InitInstance();
 
	return TRUE;
}
