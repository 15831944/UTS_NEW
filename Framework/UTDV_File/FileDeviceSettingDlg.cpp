// FileDeviceSettingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTDV_File.h"
#include "FileDeviceSettingDlg.h"
#include "afxdialogex.h"
#include "FileDevice.h"
#include "Algorithm.h"

using namespace UTS::Algorithm;
// CFileDeviceSettingDlg �Ի���

IMPLEMENT_DYNAMIC(CFileDeviceSettingDlg, CDialog)

CFileDeviceSettingDlg::CFileDeviceSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileDeviceSettingDlg::IDD, pParent)
{

}

CFileDeviceSettingDlg::~CFileDeviceSettingDlg()
{
}

void CFileDeviceSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFileDeviceSettingDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CFileDeviceSettingDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CFileDeviceSettingDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_EXPORT_FILE, &CFileDeviceSettingDlg::OnBnClickedButtonExportFile)
END_MESSAGE_MAP()


// CFileDeviceSettingDlg ��Ϣ�������


BOOL CFileDeviceSettingDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��

    //------------------------------------------------------------------------------
    // ��ʼ�����Կؼ�
    CRect rc;
    GetClientRect(rc);
    rc.bottom -= 40;
    m_propertyGrid.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, rc, this, (UINT)-1);
    HDITEM item; 
    item.cxy = 300; 
    item.mask = HDI_WIDTH; 
    m_propertyGrid.GetHeaderCtrl().SetItem(0, &item);
    m_propertyGrid.EnableHeaderCtrl(TRUE, _T("Key"), _T("Value"));
    m_propertyGrid.EnableDescriptionArea();
    m_propertyGrid.MarkModifiedProperties();
    m_propertyGrid.ExpandAll();

    //------------------------------------------------------------------------------
    // ��DB�ж�ȡ���
    BOOL bRet = FALSE;
    // ����device_id�������й��
    bRet = uts.dbCof.GetDeviceSetting(uts.info.nDeviceId, m_deviceSetting);
    if (!bRet)
    {
        AfxMessageBox(_T("Get Device Setting Fail."));
        return FALSE;
    }

    //------------------------------------------------------------------------------
    // �������µ�����ؼ���
    for (size_t i = 0; i < m_deviceSetting.vecSingleSetting.size(); i++)
    {
        CMFCPropertyGridProperty * pProp = new CMFCPropertyGridProperty(
            m_deviceSetting.vecSingleSetting[i].strKey,
            m_deviceSetting.vecSingleSetting[i].strValue,
            m_deviceSetting.vecSingleSetting[i].strComment);
        m_propertyGrid.AddProperty(pProp);
    }

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}


void CFileDeviceSettingDlg::OnBnClickedOk()
{
    BOOL bChanged = FALSE;
    //------------------------------------------------------------------------------
    // ����������д��DB
    for (int i = 0; i < m_propertyGrid.GetPropertyCount(); i++)
    {
        CMFCPropertyGridProperty * pProp = m_propertyGrid.GetProperty(i);
        if (m_deviceSetting.vecSingleSetting[i].strValue != pProp->GetValue())
        {
            bChanged = TRUE;
            m_deviceSetting.vecSingleSetting[i].strValue = pProp->GetValue();
        }
    }

    if (bChanged)
    {
        if (!uts.dbCof.SetDeviceSetting(m_deviceSetting))
        {
            AfxMessageBox(
                _T("Set Device Setting Fail."),
                MB_ICONERROR);
            return;
        }
        //uts.MessageRestart(_T("Config changed, to enable new settings UTS must be restarted. Restart now?"));
        BOOL bRet = ((FileDevice*)uts.flow.m_pDevice)->ReadFileRef();
        if (!bRet)
        {
            AfxMessageBox(
                _T("Reload FileRef error!"),
                MB_ICONERROR);
            return;
        }
    }

    CDialog::OnOK();
}


void CFileDeviceSettingDlg::OnBnClickedCancel()
{
    BOOL bChanged = FALSE;
    //------------------------------------------------------------------------------
    // �жϸ���
    for (int i = 0; i < m_propertyGrid.GetPropertyCount(); i++)
    {
        CMFCPropertyGridProperty * pProp = m_propertyGrid.GetProperty(i);
        if (m_deviceSetting.vecSingleSetting[i].strValue != pProp->GetValue())
        {
            bChanged = TRUE;
        }
    }

    if (bChanged)
    {
        int nRet = AfxMessageBox(
            _T("Config changed, Do you want to discard the changes?"),
            MB_YESNO | MB_ICONQUESTION);
        if (nRet == IDNO)
        {
            return;
        }
    }

    CDialog::OnCancel();
}


void CFileDeviceSettingDlg::OnBnClickedButtonExportFile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFileName;
	BOOL bRet = ExportFromVectToFile(m_deviceSetting, strFileName);
	if (bRet)
	{
		AfxMessageBox(_T("Success to export ") + strFileName, MB_ICONINFORMATION | MB_OK);
	}
	else
	{
		AfxMessageBox(_T("Fail to export ") + strFileName, MB_ICONERROR | MB_OK);
	}
}

BOOL CFileDeviceSettingDlg::ExportFromVectToFile(DEVICE_SETTING &deviceSetting, CString &strFileName)
{
	//��ʱ������ȫ��������ini�ļ��У����ڿ��Ը�ΪXML
	//��ȡ�ļ�·��
	TCHAR szFileName[MAX_PATH] = {0};
	OPENFILENAME SFN;
	memset(&SFN, 0, sizeof(OPENFILENAME));
	SFN.lStructSize = sizeof(OPENFILENAME);
	SFN.hwndOwner = GetSafeHwnd();
	SFN.lpstrFilter = _T("Device Setting  File(*.ini)\0*.ini\0\0");
	SFN.lpstrFile = szFileName;
	SFN.nMaxFile = MAX_PATH;
	if (!GetSaveFileName(&SFN))
	{
		uts.log.Error(_T("Did not select file."));
		return FALSE;
	}
	strFileName = szFileName;
	if (OSUtil::GetExtFileName(strFileName).MakeUpper() != _T("INI"))
	{
		strFileName.Append(_T(".ini"));
	}

	IniFile m_DevSettingFile(strFileName);

	//д������ BOARD_SET,HVS_HW,SENSOR_SET
	CString strDevSetting;
	strDevSetting.Format(_T("DevSetting"));

	for (size_t j = 0; j < deviceSetting.vecSingleSetting.size(); j++)
	{
		CString strKey =deviceSetting.vecSingleSetting[j].strKey;
		CString strValue = deviceSetting.vecSingleSetting[j].strValue;
		m_DevSettingFile.INIWrite_File(strDevSetting,strKey,strValue);
	}

	return TRUE;
}


