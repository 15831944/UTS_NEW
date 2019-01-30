#pragma once

#include "afxcmn.h"
#include "TestItemMFCListCtrl.h"

// CControlDlg �Ի���
class CMainFrame;
class CRightDlg : public CDialog
{
	DECLARE_DYNAMIC(CRightDlg)

public:
	CRightDlg(CWnd* pParent = nullptr);   // ��׼���캯��
	virtual ~CRightDlg();

// �Ի�������
	enum { IDD = IDD_ControlDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    virtual void OnCancel();
    afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
    afx_msg void OnMove(int x, int y);
    afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnDestroy();
    void AdjustWindow(void);

public:
    CMainFrame *m_pMainFrame;

private:
    BOOL m_bInitialized;

    // Message
    BOOL m_bBlinkOn;    // fix ���� #1: ��ʾ��Ϣ��Ŀ����
    CString m_strMsg;
    CRect m_rcMsg;
    CFont m_fontMsg;

    // SN
    CString m_SN;
    CRect m_rcSN;
    CFont m_fontSN;

    // Status
    CImage m_image;
    CRect m_rcImage;

    // Error code
    CString m_strErrorMsg;
    CRect m_rcErrorCode;
    CFont m_fontErrorcode;

    // Item List
    CRect m_rcResult;
    CTestItemMFCListCtrl m_ItemList;


    LRESULT OnBoardMsg(WPARAM wparam, LPARAM lparam);
    LRESULT OnBoardSN(WPARAM wparam, LPARAM lparam);
    LRESULT OnBoardStatus(WPARAM wparam, LPARAM lparam);
    LRESULT OnBoardErrorMsg(WPARAM wparam, LPARAM lparam);
    LRESULT OnBoardItemList(WPARAM wparam, LPARAM lparam);
    LRESULT OnBoardAdjust(WPARAM wparam, LPARAM lparam);
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnTimer(UINT_PTR nIDEvent);    // fix ���� #1: ��ʾ��Ϣ��Ŀ����
};
