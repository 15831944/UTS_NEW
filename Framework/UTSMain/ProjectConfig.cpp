// ProjectConfig.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSMain.h"
#include "ProjectConfig.h"
#include "afxdialogex.h"
#include "Algorithm.h"

#pragma comment(lib, "UTSAlgorithm.lib")

using namespace UTS::Algorithm;
// CProjectConfig �Ի���

IMPLEMENT_DYNAMIC(CProjectConfig, CDialog)

CProjectConfig::CProjectConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CProjectConfig::IDD, pParent)
{

}

CProjectConfig::~CProjectConfig()
{
}

void CProjectConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProjectConfig, CDialog)
    ON_BN_CLICKED(IDOK, &CProjectConfig::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CProjectConfig::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_EXPORT_PROJECT, &CProjectConfig::OnBnClickedButtonExportProject)
END_MESSAGE_MAP()


// CProjectConfig ��Ϣ�������


BOOL CProjectConfig::OnInitDialog()
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
    BOOL bRet = uts.dbCof.GetProjectAllSetting(m_vecAllSetting);
    if (!bRet)
    {
        AfxMessageBox(_T("Get Project Setting Fail."));
        return FALSE;
    }

    //------------------------------------------------------------------------------
    // �������µ�����ؼ���
    for (size_t i = 0; i < m_vecAllSetting.size(); i++)
    {
        CMFCPropertyGridProperty * pProp = new CMFCPropertyGridProperty(
            m_vecAllSetting[i].strKey,
            m_vecAllSetting[i].strValue,
            m_vecAllSetting[i].strComment);
        m_propertyGrid.AddProperty(pProp);
    }

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CProjectConfig::OnBnClickedOk()
{
    BOOL bChanged = FALSE;
    //------------------------------------------------------------------------------
    // ������ؼ������ݴ���DB
    for (int i = 0; i < m_propertyGrid.GetPropertyCount(); i++)
    {
        if (m_vecAllSetting[i].strValue != m_propertyGrid.GetProperty(i)->GetValue())
        {
            bChanged = TRUE;
            m_vecAllSetting[i].strValue = m_propertyGrid.GetProperty(i)->GetValue();
        }
    }

    if (bChanged)
    {
        if (!uts.dbCof.SetProjectAllSetting(m_vecAllSetting))
        {
            AfxMessageBox(
                _T("Set Project All Setting Fail."),
                MB_ICONERROR);
            return;
        }
        uts.MessageRestart(_T("Config changed, to enable new settings UTS must be restarted. Restart now?"));
    }

    CDialog::OnOK();
}

void CProjectConfig::OnBnClickedCancel()
{
    BOOL bChanged = FALSE;
    //------------------------------------------------------------------------------
    // �жϸ���
    for (int i = 0; i < m_propertyGrid.GetPropertyCount(); i++)
    {
        if (m_vecAllSetting[i].strValue != m_propertyGrid.GetProperty(i)->GetValue())
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


void CProjectConfig::OnBnClickedButtonExportProject()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFileName;
	BOOL bRet = ExportFromVectToFile(m_vecAllSetting, strFileName);
	//BOOL bRet = ExportFromVectToXMLFile(m_vecAllSpec, strFileName);
	if (bRet)
	{
		AfxMessageBox(_T("Success to export ") + strFileName, MB_ICONINFORMATION | MB_OK);
	}
	else
	{
		AfxMessageBox(_T("Fail to export ") + strFileName, MB_ICONERROR | MB_OK);
	}
}

BOOL CProjectConfig::ExportFromVectToFile(vector<SINGLE_ITEM> &vecSetting, CString &strFileName)
{
	//��ʱ������ȫ��������ini�ļ��У����ڿ��Ը�ΪXML
	//��ȡ�ļ�·��
	TCHAR szFileName[MAX_PATH] = {0};
	OPENFILENAME SFN;
	memset(&SFN, 0, sizeof(OPENFILENAME));
	SFN.lStructSize = sizeof(OPENFILENAME);
	SFN.hwndOwner = GetSafeHwnd();
	SFN.lpstrFilter = _T("Project Config  File(*.ini)\0*.ini\0\0");
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

	IniFile m_projectConfigFile(strFileName);
	
	//д������
	CString strProjectConfig;	
	strProjectConfig.Format(_T("Project Config"));

	for (size_t j = 0; j < vecSetting.size(); j++)
	{
		CString strKey = vecSetting[j].strKey;
		CString strValue = vecSetting[j].strValue;
		m_projectConfigFile.INIWrite_File(strProjectConfig,strKey,strValue);
	}

	return TRUE;
}
