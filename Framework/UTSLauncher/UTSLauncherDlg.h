
// UTSLauncherDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CUTSLauncherDlg �Ի���
class CUTSLauncherDlg : public CDialogEx
{
// ����
public:
	CUTSLauncherDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_UTSLAUNCHER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
    int m_nUserType;

public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedButtonLogin();
    afx_msg void OnBnClickedRadioOp();
    afx_msg void OnBnClickedRadioPe();
    afx_msg void OnBnClickedRadioSw();
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
