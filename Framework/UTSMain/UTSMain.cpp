
// UTSMain.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "UTSMain.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUTSMainApp

BEGIN_MESSAGE_MAP(CUTSMainApp, CWinApp)
END_MESSAGE_MAP()


// CUTSMainApp ����

CUTSMainApp::CUTSMainApp()
{
	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Goertek.CCM.UTS"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CUTSMainApp ����

CUTSMainApp theApp;


// CUTSMainApp ��ʼ��

BOOL CUTSMainApp::InitInstance()
{
	CWinApp::InitInstance();
    
	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("UTS"));

    //------------------------------------------------------------------------------
    // �ô˺��������ڴ�й¶
    //_CrtSetBreakAlloc(705);
    //------------------------------------------------------------------------------

	// ��Ҫ���������ڣ��˴��뽫�����µĿ�ܴ���
	// ����Ȼ��������ΪӦ�ó���������ڶ���
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// ���������ؿ�ܼ�����Դ
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);

    //pFrame->MoveWindow(10, 10, 960, 720);

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	//pFrame->ShowWindow(SW_SHOW);
	//pFrame->UpdateWindow();
    
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����
	return TRUE;
}

int CUTSMainApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
    uts.log.Destroy();
	return CWinApp::ExitInstance();
}

// CUTSMainApp ��Ϣ�������




