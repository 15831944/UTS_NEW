#pragma once


// UVCDeviceI2CDlg ��Ԓ���K

class UVCDeviceI2CDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UVCDeviceI2CDlg)

public:
	UVCDeviceI2CDlg(CWnd* pParent = NULL);   // �˜ʽ�����ʽ
	virtual ~UVCDeviceI2CDlg();

// ��Ԓ���K�Y��
	enum { IDD = IDD_FRAME_I2C };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧Ԯ

	DECLARE_MESSAGE_MAP()
};
