// UTOP_AECTest.cpp : �w�q DLL ����l�Ʊ`���C
//

#include "stdafx.h"
#include "UTOP_AECTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: �p�G�o�� DLL �O�ʺA�a�� MFC DLL �s���A
//		����q�o�� DLL �ץX������|�I�s
//		MFC �������禡�A�������b�禡�@�}�Y�[�W AFX_MANAGE_STATE
//		�����C
//
//		�Ҧp:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// ���B�����`�禡�D��
//		}
//
//		�o�ӥ����@�w�n�X�{�b�C�@��
//		�禡���A�~����I�s MFC �������C�o�N����
//		�������O�禡�����Ĥ@�ӳ��z��
//		�A�Ʀܥ����b���󪫥��ܼƫŧi�e��
//		�A�]�����̪��غc�禡�i��|���͹� MFC
//		DLL �������I�s�C
//
//		�аѾ\ MFC �޳N���� 33 �M 58 ����
//		�ԲӸ�ơC
//

// CUTOP_AECTestApp

BEGIN_MESSAGE_MAP(CUTOP_AECTestApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_AECTestApp �غc

CUTOP_AECTestApp::CUTOP_AECTestApp()
{
	// TODO: �b���[�J�غc�{���X�A
	// �N�Ҧ����n����l�]�w�[�J InitInstance ��
}


// �Ȧ����@�� CUTOP_AECTestApp ����

CUTOP_AECTestApp theApp;


// CUTOP_AECTestApp ��l�]�w

BOOL CUTOP_AECTestApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}