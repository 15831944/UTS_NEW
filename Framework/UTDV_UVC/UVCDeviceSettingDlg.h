#pragma once

#include "UVCDeviceRegisterDlg.h"

// CUVCDeviceSettingDlg �Ի���

class CUVCDeviceSettingDlg : public CDialog
{
	DECLARE_DYNAMIC(CUVCDeviceSettingDlg)

public:
	CUVCDeviceSettingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUVCDeviceSettingDlg();

// �Ի�������
	enum { IDD = IDD_UVCDeviceSettingDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedOk();
//    afx_msg void OnBnClickedCancel();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void AdjustWindow();
	BOOL ExportFromVectToFile(DEVICE_SETTING &deviceSetting, CString &strFileName);

private:
	BOOL m_bInitialized;
    CMFCPropertyGridCtrl m_propertyGrid;
    DEVICE_SETTING m_deviceSetting;
	UVCDeviceRegisterDlg m_registerDlg;
public:
	afx_msg void OnBnClickedButtonExportUvc();
};
