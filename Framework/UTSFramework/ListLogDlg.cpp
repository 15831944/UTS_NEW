// ListLogDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListLogDlg.h"


// ListLogDlg �Ի���

namespace UTS
{
    IMPLEMENT_DYNAMIC(CListLogDlg, CDialog)

        CListLogDlg::CListLogDlg(CWnd* pParent /*=NULL*/)
        : CDialog(CListLogDlg::IDD, pParent)
    {
    }

    CListLogDlg::~CListLogDlg()
    {
    }

    void CListLogDlg::DoDataExchange(CDataExchange* pDX)
    {
        CDialog::DoDataExchange(pDX);
        DDX_Control(pDX, IDC_LIST1, m_listbox);
    }


    BEGIN_MESSAGE_MAP(CListLogDlg, CDialog)
        ON_BN_CLICKED(IDOK, &CListLogDlg::OnBnClickedOk)
        ON_BN_CLICKED(IDCANCEL, &CListLogDlg::OnBnClickedCancel)
        ON_WM_SIZING()
        ON_MESSAGE(WM_LISTLOG, &CListLogDlg::OnListLog)
    END_MESSAGE_MAP()


    // ListLogDlg ��Ϣ�������

    BOOL CListLogDlg::OnInitDialog()
    {
        CDialog::OnInitDialog();

        // TODO:  �ڴ���Ӷ���ĳ�ʼ��

        return TRUE;  // return TRUE unless you set the focus to a control
        // �쳣: OCX ����ҳӦ���� FALSE
    }


    void CListLogDlg::OnBnClickedOk()
    {
        // TODO: �ڴ���ӿؼ�֪ͨ����������
        //CDialog::OnOK();
    }


    void CListLogDlg::OnBnClickedCancel()
    {
        // TODO: �ڴ���ӿؼ�֪ͨ����������
        //CDialog::OnCancel();
        ShowWindow(SW_HIDE);
    }


    void CListLogDlg::OnSizing(UINT fwSide, LPRECT pRect)
    {
        CDialog::OnSizing(fwSide, pRect);

        // TODO: �ڴ˴������Ϣ����������
        AdjustWindow();
    }

    void CListLogDlg::AdjustWindow(void)
    {
        RECT rcClient = {0};
        GetClientRect(&rcClient);
        m_listbox.MoveWindow(&rcClient);
        m_listbox.Invalidate(TRUE);
    }


    LRESULT CListLogDlg::OnListLog(WPARAM wparam, LPARAM lparam)
    {
        int nIndex = (int)wparam;
        CString strMsg = uts.log.m_LogList[nIndex];
        int nCount = m_listbox.GetCount();
        if (nCount >= m_nMaxLogCount)
        {
            m_listbox.DeleteString(0);
        }
        //m_listbox.AddString(strMsg);
        COLORREF bgColor = (COLORREF)lparam;
        m_listbox.AppendString(strMsg, COLOR_BLACK, bgColor);
        m_listbox.SetCurSel(nCount);
        return 0;
    }

    void CListLogDlg::SetMaxLogCount(int nCount)
    {
        m_nMaxLogCount = nCount;
    }
}
