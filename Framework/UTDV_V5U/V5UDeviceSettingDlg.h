#pragma once
#include "V5UDeviceRegisterDlg.h"
#include "afxwin.h"

// CV5UDeviceSettingDlg �Ի���

class CV5UDeviceSettingDlg : public CDialog
{
	DECLARE_DYNAMIC(CV5UDeviceSettingDlg)

public:
	CV5UDeviceSettingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CV5UDeviceSettingDlg();

// �Ի�������
	enum { IDD = IDD_V5UDeviceSettingDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    virtual BOOL OnInitDialog();

private:
    CButton m_registerButton;
    CMFCPropertyGridCtrl m_propertyGrid;
    CV5UDeviceRegisterDlg m_registerDlg;
    DEVICE_SETTING m_deviceSetting;
    BOOL m_bInitialized;
    void AdjustWindow();

	BOOL ExportFromVectToFile(DEVICE_SETTING &deviceSetting, CString &strFileName);

public:
    afx_msg void OnBnClickedButtonImport();
    afx_msg void OnBnClickedRadioRegister();
    afx_msg void OnMove(int x, int y);
    afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButtonExportV5u();
};
