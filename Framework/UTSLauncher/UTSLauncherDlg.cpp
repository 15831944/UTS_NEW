
// UTSLauncherDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSLauncher.h"
#include "UTSLauncherDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUTSLauncherDlg �Ի���




CUTSLauncherDlg::CUTSLauncherDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUTSLauncherDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUTSLauncherDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUTSLauncherDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDOK, &CUTSLauncherDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CUTSLauncherDlg::OnBnClickedCancel)
    ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CUTSLauncherDlg::OnBnClickedButtonLogin)
    ON_BN_CLICKED(IDC_RADIO_OP, &CUTSLauncherDlg::OnBnClickedRadioOp)
    ON_BN_CLICKED(IDC_RADIO_PE, &CUTSLauncherDlg::OnBnClickedRadioPe)
    ON_BN_CLICKED(IDC_RADIO_SW, &CUTSLauncherDlg::OnBnClickedRadioSw)
    ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CUTSLauncherDlg ��Ϣ�������

BOOL CUTSLauncherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    CheckRadioButton(IDC_RADIO_OP, IDC_RADIO_SW, IDC_RADIO_OP);

    CString strTitle;
#ifdef DEBUG
    strTitle = _T("UTSLauncher(Debug)");
#else
    strTitle = _T("UTSLauncher");
#endif
    SetWindowText(strTitle);
    if (!uts.dbCof.Initialize())
    {
        AfxMessageBox(_T("Load DB Error."));
    }

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void CUTSLauncherDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialogEx::OnShowWindow(bShow, nStatus);

    // TODO: �ڴ˴������Ϣ����������
    OnBnClickedRadioOp();
}


// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CUTSLauncherDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CUTSLauncherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUTSLauncherDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    //CDialogEx::OnOK();
    OnBnClickedButtonLogin();
}


void CUTSLauncherDlg::OnBnClickedCancel()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CDialogEx::OnCancel();
}

void CUTSLauncherDlg::OnBnClickedRadioOp()
{
    m_nUserType = USERTYPE_OPERATOR;
    GetDlgItem(IDC_EDIT_ID)->SetWindowText(EMPTY_STR);
    GetDlgItem(IDC_EDIT_PW)->SetWindowText(EMPTY_STR);
    GetDlgItem(IDC_EDIT_ID)->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_PW)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_ID)->SetFocus();
}


void CUTSLauncherDlg::OnBnClickedRadioPe()
{
    m_nUserType = USERTYPE_PE;
    GetDlgItem(IDC_EDIT_ID)->SetWindowText(EMPTY_STR);
    GetDlgItem(IDC_EDIT_PW)->SetWindowText(EMPTY_STR);
    GetDlgItem(IDC_EDIT_ID)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_PW)->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_PW)->SetFocus();
}


void CUTSLauncherDlg::OnBnClickedRadioSw()
{
    m_nUserType = USERTYPE_SOFTWARE;
    GetDlgItem(IDC_EDIT_ID)->SetWindowText(EMPTY_STR);
    GetDlgItem(IDC_EDIT_PW)->SetWindowText(EMPTY_STR);
    GetDlgItem(IDC_EDIT_ID)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_PW)->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_PW)->SetFocus();
}

void CUTSLauncherDlg::OnBnClickedButtonLogin()
{
    CString strID, strPW;
    GetDlgItem(IDC_EDIT_ID)->GetWindowText(strID);
    GetDlgItem(IDC_EDIT_PW)->GetWindowText(strPW);

    if (m_nUserType == USERTYPE_OPERATOR)
    {
        if (strID.GetLength() != 8)
        {
            AfxMessageBox(_T("ID error, correct format is 8 number."));
            return;
        }
    }

    CStringA strDBPW;
    BOOL bRet = uts.dbCof.GetUserPassword(m_nUserType, strDBPW);
	//OutputDebugStringA(strDBPW.GetString()); 
    if (!bRet)
    {
        AfxMessageBox(_T("GetUserPassword from DB error."));
        return;
    }
    USES_CONVERSION;
    CString strDBPW_CONV = A2T(strDBPW);
    if (strDBPW_CONV == strPW)
    {
        CString strCmd;
        strCmd.AppendFormat(
            _T("%s%s |%d|%s|%s"),
            uts.info.strBinPath,
            _T("UTSMain.exe"),
            m_nUserType,
            strID,
            strPW);
        OSUtil::ExcuteCommand(strCmd, FALSE);
        OnBnClickedCancel();
    }
    else
    {
        AfxMessageBox(_T("Password error."));
        GetDlgItem(IDC_EDIT_PW)->SetWindowText(EMPTY_STR);
        GetDlgItem(IDC_EDIT_PW)->SetFocus();
        return;
    }
}

