// UTOP_MES_SnSensorId.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UTOP_MES_SnSensorId.h"

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

// CUTOP_MES_SnSensorIdApp

BEGIN_MESSAGE_MAP(CUTOP_MES_SnSensorIdApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_MES_SnSensorIdApp ����

CUTOP_MES_SnSensorIdApp::CUTOP_MES_SnSensorIdApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUTOP_MES_SnSensorIdApp ����

CUTOP_MES_SnSensorIdApp theApp;


// CUTOP_MES_SnSensorIdApp ��ʼ��

BOOL CUTOP_MES_SnSensorIdApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
