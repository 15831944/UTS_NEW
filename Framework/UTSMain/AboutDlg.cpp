// AboutDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSMain.h"
#include "AboutDlg.h"
#include "afxdialogex.h"


// CAboutDlg �Ի���

IMPLEMENT_DYNAMIC(CAboutDlg, CDialog)

CAboutDlg::CAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutDlg::IDD, pParent)
{

}

CAboutDlg::~CAboutDlg()
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_VERSION, m_versionList);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CAboutDlg::OnBnClickedCancel)
    ON_WM_SIZING()
END_MESSAGE_MAP()


// CAboutDlg ��Ϣ�������


BOOL CAboutDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��

    // UTS version
    CString strFilename = OSUtil::GetBSPath(uts.info.strBinPath) + _T("UTSMain.exe");
    CString strFileVersion;
    OSUtil::GetFileVersion(strFilename, strFileVersion);
    vector<int> vecVersion;
    strFileVersion.Replace(_T("."), _T(","));
    SplitInt(strFileVersion, vecVersion);
    if (vecVersion.size() > 0)
    {
        strFileVersion.Format(_T("V%d.%d"), vecVersion[0], vecVersion[1]);
    }
    SetDlgItemText(IDC_STATIC_VERSION, strFileVersion);


    DWORD dwStyle = m_versionList.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;    //ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
    dwStyle |= LVS_EX_GRIDLINES;        //�����ߣ�ֻ������report����listctrl��
    m_versionList.SetExtendedStyle(dwStyle);   //������չ���
    // ������
    m_versionList.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 350);
    m_versionList.InsertColumn(1, _T("Version"), LVCFMT_LEFT, 100);
    m_versionList.InsertColumn(2, _T("Datetime"), LVCFMT_LEFT, 200);

    ShowFileVersion();

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CAboutDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    //CDialog::OnOK();
}


void CAboutDlg::OnBnClickedCancel()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CDialog::OnCancel();
}

void CAboutDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
    CDialog::OnSizing(fwSide, pRect);

    // TODO: �ڴ˴������Ϣ����������
    AdjustWindow();
}

void CAboutDlg::AdjustWindow(void)
{
    RECT rcClient = {0};
    GetClientRect(&rcClient);
    m_versionList.MoveWindow(&rcClient);
}

void CAboutDlg::ShowFileVersion(void)
{
    CStringList filelist;
    OSUtil::GetFiles(uts.info.strBinPath, filelist);
    POSITION pos = filelist.GetHeadPosition();
    while (pos != nullptr)
    {
        // �ļ���
        CString strFilename = filelist.GetNext(pos);
        if (OSUtil::GetFileName(strFilename).Left(2).CompareNoCase(_T("UT")) != 0)
        {
            continue;
        }
        CString strFileExtName = OSUtil::GetExtFileName(strFilename).MakeUpper();
        if (strFileExtName != _T("DLL") && strFileExtName != _T("EXE"))
        {
            continue;
        }
        int nRow = m_versionList.InsertItem(0, OSUtil::GetFileName(strFilename));
        // �汾
        CString strFileVersion;
        OSUtil::GetFileVersion(strFilename, strFileVersion);
        m_versionList.SetItemText(nRow, 1, strFileVersion);
        // ����
        CString strCreateTime;
        CString strAccessTime;
        CString strWriteTime;
        OSUtil::GetFileTimeStr(strFilename, strCreateTime, strAccessTime, strWriteTime);
        m_versionList.SetItemText(nRow, 2, strWriteTime);
    }
}

