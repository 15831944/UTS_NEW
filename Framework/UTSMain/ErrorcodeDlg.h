#pragma once


// CErrorcodeDlg �Ի���

class CErrorcodeDlg : public CDialog
{
	DECLARE_DYNAMIC(CErrorcodeDlg)

public:
	CErrorcodeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CErrorcodeDlg();

// �Ի�������
	enum { IDD = IDD_ErrorCodeDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();

private:
    CMFCPropertyGridCtrl m_propertyGrid;
};
