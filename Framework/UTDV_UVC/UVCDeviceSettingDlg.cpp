// UVCDeviceSettingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTDV_UVC.h"
#include "UVCDeviceSettingDlg.h"
#include "afxdialogex.h"
#include "UVCDevice.h"
#include "Algorithm.h"

using namespace UTS;
using namespace UTS::Algorithm;
// CUVCDeviceSettingDlg �Ի���

IMPLEMENT_DYNAMIC(CUVCDeviceSettingDlg, CDialog)

CUVCDeviceSettingDlg::CUVCDeviceSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUVCDeviceSettingDlg::IDD, pParent)
{
	m_bInitialized = FALSE;
}

CUVCDeviceSettingDlg::~CUVCDeviceSettingDlg()
{
}

void CUVCDeviceSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUVCDeviceSettingDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CUVCDeviceSettingDlg::OnBnClickedOk)
//    ON_BN_CLICKED(IDCANCEL, &CUVCDeviceSettingDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_EXPORT_UVC, &CUVCDeviceSettingDlg::OnBnClickedButtonExportUvc)
END_MESSAGE_MAP()


// CUVCDeviceSettingDlg ��Ϣ�������


BOOL CUVCDeviceSettingDlg::OnInitDialog()
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

	//------------------------------------------------------------------------------
	// ����Register Dialog
	if (!m_registerDlg.Create(IDD_UVCDeviceRegisterDlg, this))
	{
		AfxMessageBox(_T("Create register dialog fail!"));
		return FALSE;
	}
	else
	{
		// �趨board�ĳ�ʼ���
		RECT rcRegisterDlg = {0};
		rcRegisterDlg.right = rcRegisterDlg.left + 500;
		m_registerDlg.MoveWindow(&rcRegisterDlg);
		AdjustWindow();
	}

	bRet = uts.dbCof.GetAllRegister(m_registerDlg.m_vecOldRegisterList);
	if (!bRet)
	{
		AfxMessageBox(_T("Get All Register Fail."));
		return FALSE;
	}

	for (size_t i = 0; i < m_registerDlg.m_vecOldRegisterList.size(); i++)
	{
		m_registerDlg.m_vecNewRegisterList.push_back(m_registerDlg.m_vecOldRegisterList[i]);
	}

	m_registerDlg.RefreshRegisterList(m_registerDlg.m_vecOldRegisterList);
	m_registerDlg.ShowWindow(SW_SHOW);

	m_bInitialized = TRUE;


    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CUVCDeviceSettingDlg::OnBnClickedOk()
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
    
    if (m_registerDlg.m_vecNewRegisterList.size() == m_registerDlg.m_vecOldRegisterList.size())
    {
        for (size_t i = 0; i < m_registerDlg.m_vecNewRegisterList.size(); i++)
        {
            if (m_registerDlg.m_vecNewRegisterList[i].strName != m_registerDlg.m_vecOldRegisterList[i].strName)
            {
                bChanged = TRUE;
                break;
            }
            if (m_registerDlg.m_vecNewRegisterList[i].strData != m_registerDlg.m_vecOldRegisterList[i].strData)
            {
                bChanged = TRUE;
                break;
            }
        }
    }
    else
    {
        bChanged = TRUE;
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
        if (!uts.dbCof.DeleteV5UDeviceRegister())
        {
            AfxMessageBox(
                _T("DeleteV5UDeviceRegister Fail."),
                MB_ICONERROR);
            return;
        }
        for (size_t i = 0; i < m_registerDlg.m_vecNewRegisterList.size(); i++)
        {
            if (!uts.dbCof.AddV5UDeviceRegister(
                m_registerDlg.m_vecNewRegisterList[i].strName,
                m_registerDlg.m_vecNewRegisterList[i].strData))
            {
                AfxMessageBox(
                    _T("AddV5UDeviceRegister Fail."),
                    MB_ICONERROR);
                return;
            }
        }
        //uts.MessageRestart(_T("Config changed, to enable new settings UTS must be restarted. Restart now?"));
        BOOL bRet = ((UVCDevice*)uts.flow.m_pDevice)->ReadUVCRef();
        if (!bRet)
        {
            AfxMessageBox(
                _T("Reload UVCRef error!"),
                MB_ICONERROR);
            return;
        }
    }

    CDialog::OnOK();
}

//void CUVCDeviceSettingDlg::OnBnClickedCancel()
//{
//    BOOL bChanged = FALSE;
//    //------------------------------------------------------------------------------
//    // �жϸ���
//    for (int i = 0; i < m_propertyGrid.GetPropertyCount(); i++)
//    {
//        CMFCPropertyGridProperty * pProp = m_propertyGrid.GetProperty(i);
//        if (m_deviceSetting.vecSingleSetting[i].strValue != pProp->GetValue())
//        {
//            bChanged = TRUE;
//        }
//    }
//
//    if (m_registerDlg.m_vecNewRegisterList.size() == m_registerDlg.m_vecOldRegisterList.size())
//    {
//        for (size_t i = 0; i < m_registerDlg.m_vecNewRegisterList.size(); i++)
//        {
//            if (m_registerDlg.m_vecNewRegisterList[i].strName != m_registerDlg.m_vecOldRegisterList[i].strName)
//            {
//                bChanged = TRUE;
//                break;
//            }
//            if (m_registerDlg.m_vecNewRegisterList[i].strData != m_registerDlg.m_vecOldRegisterList[i].strData)
//            {
//                bChanged = TRUE;
//                break;
//            }
//        }
//    }
//    else
//    {
//        bChanged = TRUE;
//    }
//
//    if (bChanged)
//    {
//        int nRet = AfxMessageBox(
//            _T("Config changed, Do you want to discard the changes?"),
//            MB_YESNO | MB_ICONQUESTION);
//        if (nRet == IDNO)
//        {
//            return;
//        }
//    }
//
//    CDialog::OnCancel();
//}

void CUVCDeviceSettingDlg::AdjustWindow()
{
	RECT rcSettingDlg = {0};
	GetWindowRect(&rcSettingDlg);

	//------------------------------------------------------------------------------
	// Register dialog
	RECT rcRegisterDlg = {0};
	m_registerDlg.GetWindowRect(&rcRegisterDlg);
	int nRightDlgWidth = rcRegisterDlg.right - rcRegisterDlg.left;
	rcRegisterDlg.left = rcSettingDlg.right;
	rcRegisterDlg.right = rcRegisterDlg.left + nRightDlgWidth;
	rcRegisterDlg.top = rcSettingDlg.top;
	rcRegisterDlg.bottom = rcSettingDlg.bottom;

	m_registerDlg.MoveWindow(&rcRegisterDlg);

}

void CUVCDeviceSettingDlg::OnMove(int x, int y)
{
	CDialog::OnMove(x, y);

	// TODO: �ڴ˴������Ϣ����������
	if (m_bInitialized)
	{
		AdjustWindow();
	}
}

void CUVCDeviceSettingDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (m_bInitialized)
	{
		AdjustWindow();
	}
}

void CUVCDeviceSettingDlg::OnBnClickedButtonExportUvc()
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

BOOL CUVCDeviceSettingDlg::ExportFromVectToFile(DEVICE_SETTING &deviceSetting, CString &strFileName)
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

	//��������ļ�����
	FILE *fp = nullptr;
	errno_t nError = _tfopen_s(&fp, strFileName, _T("w"));
	if (nError != 0)
	{
		uts.log.Error(_T("Open file %s error."), strFileName);
		return FALSE;
	}
	fclose(fp);



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

	//д��Register������
	fp = nullptr;
	nError = _tfopen_s(&fp, strFileName, _T("a"));
	if (nError != 0)
	{
		uts.log.Error(_T("Open file %s error."), strFileName);
		return FALSE;
	}

	for (vector<REGISTER_ITEM>::iterator itor = m_registerDlg.m_vecOldRegisterList.begin(); itor != m_registerDlg.m_vecOldRegisterList.end(); itor++)
	{
		REGISTER_ITEM item;
		CString strName = itor->strName;
		CString strData = itor->strData;
		_ftprintf_s(fp, _T("\n\n"));
		_ftprintf_s(fp, _T("%s\n"), strName);
		if (!strData.IsEmpty())
		{
			_ftprintf_s(fp, _T("%s\n"), strData);
		}

		_ftprintf_s(fp, _T("[END]\n"));

	}
	fclose(fp);
	return TRUE;
}


