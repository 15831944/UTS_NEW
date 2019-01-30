#pragma once


// CProjectConfig �Ի���

class CProjectConfig : public CDialog
{
	DECLARE_DYNAMIC(CProjectConfig)

public:
	CProjectConfig(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProjectConfig();

// �Ի�������
	enum { IDD = IDD_ProjectDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonExportProject();

private:
    CMFCPropertyGridCtrl m_propertyGrid;
    vector<SINGLE_ITEM> m_vecAllSetting;

	BOOL ExportFromVectToFile(vector<SINGLE_ITEM> &vecSetting, CString &strFileName);
};
