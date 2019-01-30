#pragma once
#include "Export.h"

// ListLogDlg �Ի���

namespace UTS
{
    class CListLogDlg : public CDialog
    {
        DECLARE_DYNAMIC(CListLogDlg)

    public:
        CListLogDlg(CWnd* pParent = NULL);   // ��׼���캯��
        virtual ~CListLogDlg();
        virtual BOOL OnInitDialog();
        // �Ի�������
        enum { IDD = IDD_LISTLOG };

    protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

        DECLARE_MESSAGE_MAP()
    public:
        afx_msg void OnBnClickedOk();
        afx_msg void OnBnClickedCancel();
        afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
        afx_msg LRESULT OnListLog(WPARAM wparam, LPARAM lparam);

    private:
        int m_nMaxLogCount;
        CColorListBox m_listbox;
        void AdjustWindow(void);
    public:
        void SetMaxLogCount(int nCount);
    };
}
