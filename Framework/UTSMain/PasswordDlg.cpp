// PasswordDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSMain.h"
#include "PasswordDlg.h"
#include "afxdialogex.h"


// CPasswordDlg �Ի���

IMPLEMENT_DYNAMIC(CPasswordDlg, CDialog)

CPasswordDlg::CPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDlg::IDD, pParent)
{

}

CPasswordDlg::~CPasswordDlg()
{
}

void CPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CPasswordDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    if (m_nUserType == USERTYPE_PE)
    {
        SetWindowText(_T("Change PE password"));
    }
    else
    {
        SetWindowText(_T("Change SW password"));
    }

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CPasswordDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);

    // TODO: �ڴ˴������Ϣ����������
    GetDlgItem(IDC_EDIT_PW)->SetFocus();
}

BEGIN_MESSAGE_MAP(CPasswordDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CPasswordDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CPasswordDlg::OnBnClickedCancel)
    ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CPasswordDlg ��Ϣ�������


void CPasswordDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CString strPW, strPWCF;
    GetDlgItem(IDC_EDIT_PW)->GetWindowText(strPW);
    GetDlgItem(IDC_EDIT_PW_CF)->GetWindowText(strPWCF);

    if (strPW != strPWCF)
    {
        AfxMessageBox(_T("The confirmation password do not match."));
        return;
    }

    USES_CONVERSION;
    if (!uts.dbCof.SetUserPassword(m_nUserType, T2A(strPW)))
    {
        AfxMessageBox(_T("SetUserPassword fail."));
        return;
    }
    else
    {
        AfxMessageBox(_T("SetUserPassword success."), MB_ICONINFORMATION);
    }

    CDialog::OnOK();
}


void CPasswordDlg::OnBnClickedCancel()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CDialog::OnCancel();
}

void CPasswordDlg::SetMode(int nUserType)
{
    m_nUserType = nUserType;
}


