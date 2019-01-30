// OperatorSpecDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSMain.h"
#include "OperatorSpecDlg.h"
#include "afxdialogex.h"
//xml
#import "C:\\WINDOWS\\system32\\msxml6.dll"
using namespace MSXML2;

// OperatorSpecDlg �Ի���

IMPLEMENT_DYNAMIC(COperatorSpecDlg, CDialog)

COperatorSpecDlg::COperatorSpecDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COperatorSpecDlg::IDD, pParent)
{

}

COperatorSpecDlg::~COperatorSpecDlg()
{
}

void COperatorSpecDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COperatorSpecDlg, CDialog)
    ON_BN_CLICKED(IDOK, &COperatorSpecDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &COperatorSpecDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_EXPORT_OPELIST, &COperatorSpecDlg::OnBnClickedButtonExportOpelist)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT_OPELIST, &COperatorSpecDlg::OnBnClickedButtonImportOpelist)
END_MESSAGE_MAP()


// OperatorSpecDlg ��Ϣ�������

BOOL COperatorSpecDlg::OnInitDialog()
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

    //------------------------------------------------------------------------------
    // ��DB�ж�ȡ���
    BOOL bRet = uts.dbCof.GetAllOperatorSpec(m_vecAllSpec);
    if (!bRet)
    {
        AfxMessageBox(_T("Get Operator Spec Fail."));
        return FALSE;
    }

    //------------------------------------------------------------------------------
    // �������µ�����ؼ���
    for (size_t i = 0; i < m_vecAllSpec.size(); i++)
    {
        CMFCPropertyGridProperty* pGroup = new CMFCPropertyGridProperty(m_vecAllSpec[i].strOperatorFileName);
        for (size_t j = 0; j < m_vecAllSpec[i].vecSingleSpec.size(); j++)
        {
            CMFCPropertyGridProperty * pProp = new CMFCPropertyGridProperty(
                m_vecAllSpec[i].vecSingleSpec[j].strKey,
                m_vecAllSpec[i].vecSingleSpec[j].strValue,
                m_vecAllSpec[i].vecSingleSpec[j].strComment);
            pGroup->AddSubItem(pProp);
        }
        m_propertyGrid.AddProperty(pGroup);
    }
    m_propertyGrid.ExpandAll(FALSE);    // fix ���� #5: operator spec�޸�Ϊ��ʾʱĬ�������б�������ĸ����

	// ����Merger Dialog
	if (!operatorMergerDlg.Create(IDD_OperatorMergerDlg, this))
	{
		AfxMessageBox(_T("Create Merger dialog fail!"));
		return FALSE;
	}
	


    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void COperatorSpecDlg::OnBnClickedOk()
{
    BOOL bChanged = FALSE;
    //------------------------------------------------------------------------------
    // ������ؼ������ݴ���DB
    for (int i = 0; i < m_propertyGrid.GetPropertyCount(); i++)
    {
        for (int j = 0; j < m_propertyGrid.GetProperty(i)->GetSubItemsCount(); j++)
        {
            CMFCPropertyGridProperty * pProp = m_propertyGrid.GetProperty(i)->GetSubItem(j);
            if (m_vecAllSpec[i].vecSingleSpec[j].strValue != pProp->GetValue())
            {
                bChanged = TRUE;
                m_vecAllSpec[i].vecSingleSpec[j].strValue = pProp->GetValue();
            }
        }
    }

    if (bChanged)
    {
        if (!uts.dbCof.SetAllOperatorSpec(m_vecAllSpec))
        {
            AfxMessageBox(
                _T("Set All Operator Spec Fail."),
                MB_ICONERROR);
            return;
        }
    }

    CDialog::OnOK();
}

void COperatorSpecDlg::OnBnClickedCancel()
{
    BOOL bChanged = FALSE;
    //------------------------------------------------------------------------------
    // �жϸ���
    for (int i = 0; i < m_propertyGrid.GetPropertyCount(); i++)
    {
        for (int j = 0; j < m_propertyGrid.GetProperty(i)->GetSubItemsCount(); j++)
        {
            CMFCPropertyGridProperty * pProp = m_propertyGrid.GetProperty(i)->GetSubItem(j);
            if (m_vecAllSpec[i].vecSingleSpec[j].strValue != pProp->GetValue())
            {
                bChanged = TRUE;
            }
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



void COperatorSpecDlg::OnBnClickedButtonExportOpelist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFileName;

	BOOL bRet = ExportFromVectToXMLFile(m_vecAllSpec, strFileName);
	if (bRet)
	{
		AfxMessageBox(_T("Success to export ") + strFileName, MB_ICONINFORMATION | MB_OK);
	}
	else
	{
		AfxMessageBox(_T("Fail to export ") + strFileName, MB_ICONERROR | MB_OK);
	}
}
BOOL COperatorSpecDlg::ExportFromVectToXMLFile(vector<OPERATOR_SPEC> &OpeSpec, CString &strFileName)
{
	//��ȡ�ļ�·��
	TCHAR szFileName[MAX_PATH] = {0};
	OPENFILENAME SFN;
	memset(&SFN, 0, sizeof(OPENFILENAME));
	SFN.lStructSize = sizeof(OPENFILENAME);
	SFN.hwndOwner = GetSafeHwnd();
	SFN.lpstrFilter = _T("Operator Spec  File(*.xml)\0*.xml\0\0");
	SFN.lpstrFile = szFileName;
	SFN.nMaxFile = MAX_PATH;
	if (!GetSaveFileName(&SFN))
	{
		uts.log.Error(_T("Did not select file."));
		return FALSE;
	}
	strFileName = szFileName;
	if (OSUtil::GetExtFileName(strFileName).MakeUpper() != _T("XML"))
	{
		strFileName.Append(_T(".xml"));
	}

	::CoInitialize(NULL);  //��ʼ��COM  
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMProcessingInstructionPtr pi; 
	MSXML2::IXMLDOMElementPtr xmlRoot;  
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument60));  
	if(!SUCCEEDED(hr))  
	{  
		uts.log.Error(_T("XML Create Fail."));  
		return FALSE;  
	}  

	//���XML�ļ�ͷ  
	pi = pDoc->createProcessingInstruction("xml", "version='1.0' encoding='UTF-8'");  
	if (pi != NULL) 
	{  
		pDoc->appendChild(pi);  
		pi.Release();  
	}  
	//�������ڵ�
	pDoc->raw_createElement( (_bstr_t)(char*)"AllOperatorSpec", &xmlRoot);  
	pDoc->raw_appendChild(xmlRoot, NULL);  
	//��Ӳ���������ò���
	for (size_t i = 0; i < OpeSpec.size(); i++)
	{
		int nOperatorId = OpeSpec[i].nOperatorId;
		CString nOperatorName =  OpeSpec[i].strOperatorFileName;

		MSXML2::IXMLDOMElementPtr pOperatorElemNode; 
		pDoc->raw_createElement( (_bstr_t)(char*)"Operator", &pOperatorElemNode);
		pOperatorElemNode->setAttribute("ID",nOperatorId);  
		pOperatorElemNode->setAttribute("Name",(_variant_t)nOperatorName);  
		

		for (size_t j = 0; j < OpeSpec[i].vecSingleSpec.size(); j++)
		{
			CString strKey = OpeSpec[i].vecSingleSpec[j].strKey;
			CString strValue = OpeSpec[i].vecSingleSpec[j].strValue;
			MSXML2::IXMLDOMElementPtr pElemNode; 
			pDoc->raw_createElement( (_bstr_t)(char*)"parameter", &pElemNode);
			pElemNode->Puttext((_bstr_t)strValue); 
			pElemNode->setAttribute("key",(_variant_t)strKey);
			pOperatorElemNode->appendChild(pDoc->createTextNode("\n\t\t"));
			pOperatorElemNode->appendChild(pElemNode);
			
		}
		xmlRoot->appendChild(pDoc->createTextNode("\n\t"));
		xmlRoot->appendChild(pOperatorElemNode);
	} 
	pDoc->save((_variant_t)strFileName);  
	//����ͷ�pDocռ�е��ڴ�  
	::CoUninitialize();  //ж��COM 
	return TRUE;
}

void COperatorSpecDlg::OnBnClickedButtonImportOpelist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����XML�е�����
	if (ImportFromXMLFileToVect(m_importVecAllSpec))
	{
		//�ƶ����ڵ�ָ��λ��
		RECT rcSpecDlg = {0};
		GetWindowRect(&rcSpecDlg);

		// Merger dialog
		RECT rcMergerDlg = {0};
		operatorMergerDlg.GetWindowRect(&rcMergerDlg);
		int nRightDlgWidth = rcMergerDlg.right - rcMergerDlg.left;
		int nRightDlgHeight = rcMergerDlg.top - rcMergerDlg.bottom;
		rcMergerDlg.left = rcSpecDlg.right+10;
		rcMergerDlg.right = rcMergerDlg.left + nRightDlgWidth;
		rcMergerDlg.top = rcSpecDlg.top;
		rcMergerDlg.bottom = rcMergerDlg.top - nRightDlgHeight;
		operatorMergerDlg.MoveWindow(&rcMergerDlg);
		//�����ϲ�����
		operatorMergerDlg.AddOperatorSpecData(m_importVecAllSpec);
		operatorMergerDlg.ShowWindow(SW_SHOW);
	}
}

BOOL COperatorSpecDlg::ImportFromXMLFileToVect(vector<OPERATOR_SPEC> &allOpeSpec)
{
	//��ȡ�ļ�·��
	TCHAR szFileName[MAX_PATH] = {0};
	OPENFILENAME SFN;
	memset(&SFN, 0, sizeof(OPENFILENAME));
	SFN.lStructSize = sizeof(OPENFILENAME);
	SFN.hwndOwner = GetSafeHwnd();
	SFN.lpstrFilter = _T("Operator Spec File(*.xml)\0*.xml\0\0");
	SFN.lpstrFile = szFileName;
	SFN.nMaxFile = MAX_PATH;
	SFN.Flags = OFN_FILEMUSTEXIST;
	if (!GetOpenFileName(&SFN))
	{
		uts.log.Error(_T("Did not select file."));
		return FALSE;
	}

	//����XML�ļ�
	::CoInitialize(NULL);  //��ʼ��COM   
	MSXML2::IXMLDOMDocumentPtr pDoc;  //����һ��xml�ĵ�ָ��  
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument60));  //ʵ�����ĵ�ָ��  
	if(!SUCCEEDED(hr))  
	{  
		uts.log.Error(_T("XML Create Fail."));  
		return FALSE;   
	}  
	VARIANT_BOOL loadrs = pDoc->load(szFileName);  //����xml�ĵ�  
	if( -1 != loadrs )
	{
		uts.log.Error(_T("XML Load Fail."));  
		return FALSE;
	}
	
	MSXML2::IXMLDOMElementPtr pElemNode;  //����һ��Ԫ��(Element)ָ��  

	// �����в�����ΪCity�Ľڵ�," // "��ʾ������һ�����  
	pElemNode = (MSXML2::IXMLDOMElementPtr)(pDoc->selectSingleNode("//AllOperatorSpec"));  //��ȡԪ�ص���Ϣ  

	MSXML2::IXMLDOMNamedNodeMapPtr pAttrs = NULL;   
	MSXML2::IXMLDOMNodeListPtr nodeList = NULL;  
	MSXML2::IXMLDOMNodePtr pAttrItem = NULL;  

	pElemNode->get_childNodes(&nodeList);  //��ȡ�ӽڵ�  

	allOpeSpec.clear();
	long nCount, iCount,index=0;  
	MSXML2::IXMLDOMElementPtr pCurNode,pChildCurNode;  

	nodeList->get_length(&iCount); 
	//���ݴ���allOpeSpec��
	for(int i = 0; i < iCount; i++ )   
	{  
		pCurNode = nodeList->nextNode();  
		CString strOperatorID = pCurNode->getAttribute("ID");
		CString strOperatorName = pCurNode->getAttribute("Name");

		OPERATOR_SPEC opSpec = {0};
		opSpec.nOperatorId = _ttoi(strOperatorID);
		opSpec.strOperatorFileName = strOperatorName;

		MSXML2::IXMLDOMNodeListPtr ChildnodeList = NULL;  
		pCurNode->get_childNodes(&ChildnodeList);  
		ChildnodeList->get_length(&nCount);  
		for(int j=0; j < nCount; j++ )  
		{  
			pChildCurNode = ChildnodeList->nextNode();  
			CString strKey = pChildCurNode->getAttribute("key");  
			CString strValue = (wchar_t*)(_bstr_t)pChildCurNode->Gettext();

			SINGLE_ITEM stSingleSpec = {0};
			stSingleSpec.strKey = strKey;
			stSingleSpec.strValue = strValue;
			stSingleSpec.strComment = _T("");

			opSpec.vecSingleSpec.push_back(stSingleSpec);

		}
		allOpeSpec.push_back(opSpec);
	}  
	::CoUninitialize();  //ж��COM  


	return TRUE;
}

BOOL COperatorSpecDlg::doMergerOp(vector<CString> &operatorList,map<CString,vector<SINGLE_ITEM>> &OperatorAndItemMap)
{
	//�ж��Ƿ�Ϊ��
	if (0 == operatorList.size())
	{
		return TRUE;
	}

	//ִ�кϲ�����
	for (int k = 0; k < operatorList.size(); k++)
	{
		CString operatorName = operatorList.at(k);

		for (int i = 0; i < m_propertyGrid.GetPropertyCount(); i++)
		{
			if (operatorName == m_propertyGrid.GetProperty(i)->GetName())
			{
				//��ѯ��Ҫ��OperatorName
				map<CString,vector<SINGLE_ITEM>>::iterator iter;
				vector<SINGLE_ITEM> vecSingleSpec;
				
				iter = OperatorAndItemMap.find(operatorName);  
				if(iter != OperatorAndItemMap.end())  
				{  
					vecSingleSpec = iter->second;  
				}
				else
				{
					return FALSE;
				}
				for (int j = 0; j < m_propertyGrid.GetProperty(i)->GetSubItemsCount(); j++)
				{
					//�޸Ķ�Ӧ��key��Value
					CMFCPropertyGridProperty * pProp = m_propertyGrid.GetProperty(i)->GetSubItem(j);

					for (vector<SINGLE_ITEM>::iterator infoIter = vecSingleSpec.begin(); infoIter != vecSingleSpec.end(); infoIter++)
					{
						if (infoIter->strKey == pProp->GetName())
						{
							pProp->SetValue(infoIter->strValue);
						}
					}	
				}
			}
		}
	}
	
	return TRUE;
}