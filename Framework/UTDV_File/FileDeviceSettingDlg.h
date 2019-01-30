#pragma once


// CFileDeviceSettingDlg �Ի���

class CFileDeviceSettingDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileDeviceSettingDlg)

public:
	CFileDeviceSettingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFileDeviceSettingDlg();

// �Ի�������
	enum { IDD = IDD_FileDeviceSettingDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();

private:
    CMFCPropertyGridCtrl m_propertyGrid;
    DEVICE_SETTING m_deviceSetting;

	BOOL ExportFromVectToFile(DEVICE_SETTING &deviceSetting, CString &strFileName);
public:
	afx_msg void OnBnClickedButtonExportFile();
};
