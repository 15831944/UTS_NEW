// UTOP_OC_Raw.cpp : �w�q DLL ����l�Ʊ`���C
//

#include "stdafx.h"
#include "UTOP_OC_Raw.h"

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

// CUTOP_OC_RawApp

BEGIN_MESSAGE_MAP(CUTOP_OC_RawApp, CWinApp)
END_MESSAGE_MAP()


// CUTOP_OC_RawApp �غc

CUTOP_OC_RawApp::CUTOP_OC_RawApp()
{
	// TODO: �b���[�J�غc�{���X�A
	// �N�Ҧ����n����l�]�w�[�J InitInstance ��
}


// �Ȧ����@�� CUTOP_OC_RawApp ����

CUTOP_OC_RawApp theApp;


// CUTOP_OC_RawApp ��l�]�w

BOOL CUTOP_OC_RawApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
