// UTOP_SFC_CommitTestData.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UTOP_SFC_CommitTestData.h"

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

// CUTOP_SFC_CommitTestDataApp

BEGIN_MESSAGE_MAP(CUTOP_SFC_CommitTestDataApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_SFC_CommitTestDataApp ����

CUTOP_SFC_CommitTestDataApp::CUTOP_SFC_CommitTestDataApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUTOP_SFC_CommitTestDataApp ����

CUTOP_SFC_CommitTestDataApp theApp;


// CUTOP_SFC_CommitTestDataApp ��ʼ��

BOOL CUTOP_SFC_CommitTestDataApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
