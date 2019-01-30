// OperatorMergerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSMain.h"
#include "OperatorMergerDlg.h"
#include "afxdialogex.h"
#include "OperatorSpecDlg.h"
#include "CheckHeadCtrl.h"

// COperatorMergerDlg �Ի���

IMPLEMENT_DYNAMIC(COperatorMergerDlg, CDialog)

COperatorMergerDlg::COperatorMergerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COperatorMergerDlg::IDD, pParent)
{

}

COperatorMergerDlg::~COperatorMergerDlg()
{
}

void COperatorMergerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_OPERATOR_SPEC, m_OperatorNameList);
	DDX_Control(pDX, IDC_LIST_OPERATOR_INFO, m_OperatorInfoList);
}


BEGIN_MESSAGE_MAP(COperatorMergerDlg, CDialog)
	ON_BN_CLICKED(IDOK, &COperatorMergerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &COperatorMergerDlg::OnBnClickedCancel)
	ON_NOTIFY(NM_CLICK, IDC_LIST_OPERATOR_SPEC, &COperatorMergerDlg::OnNMClickListOperatorSpec)
END_MESSAGE_MAP()


// COperatorMergerDlg ��Ϣ�������
BOOL COperatorMergerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	// ��ʼ�����Կؼ�
	
	// All Operator List
	DWORD dwStyle = m_OperatorNameList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;    //ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	dwStyle |= LVS_EX_GRIDLINES;        //�����ߣ�ֻ������report����listctrl��
	m_OperatorNameList.SetExtendedStyle(dwStyle| LVS_EX_CHECKBOXES);   //������չ���
	// ������
	m_OperatorNameList.InsertColumn(0, _T("Operator Name"), LVCFMT_LEFT, 200);
	m_OperatorNameList.Init();

	//------------------------------------------------------------------------------
	// Initial start Operator List
	m_OperatorInfoList.SetExtendedStyle(dwStyle);
	m_OperatorInfoList.InsertColumn(0, _T("Key"), LVCFMT_LEFT, 200);
	m_OperatorInfoList.InsertColumn(1, _T("Value"), LVCFMT_LEFT, 200);
	
	return TRUE;
}

BOOL COperatorMergerDlg::AddOperatorSpecData(vector<OPERATOR_SPEC> &allOpeSpec)
{
	m_OperatorNameList.DeleteAllItems();
	m_OperatorInfoList.DeleteAllItems();

	m_OperatorNameList.ShowWindow(SW_HIDE);
	for (size_t i = 0; i < allOpeSpec.size(); i++)
	{
		m_OperatorNameList.InsertItem(i, allOpeSpec[i].strOperatorFileName);
		OperatorAndItemMap.insert(make_pair(allOpeSpec[i].strOperatorFileName,allOpeSpec[i].vecSingleSpec));
	}
	m_OperatorNameList.ShowWindow(SW_SHOW);
	return TRUE;
}

void COperatorMergerDlg::OnBnClickedOk()
{
	//��ȡOperator��CheckBoxѡ�е���Ϣ
	MergerOpName.clear();

	for(int i=0; i<m_OperatorNameList.GetItemCount(); i++ )
	{
		if(m_OperatorNameList.GetCheck(i))
		{
			MergerOpName.push_back(m_OperatorNameList.GetItemText(i,0));
		}
	}

	//���ø����ڽ������ݺϲ�
	COperatorSpecDlg *pDlg = (COperatorSpecDlg*)this->GetParent();
	pDlg->doMergerOp(MergerOpName,OperatorAndItemMap);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}


void COperatorMergerDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}


void COperatorMergerDlg::OnNMClickListOperatorSpec(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ȡѡ�е�Operator Name
	int iSelectRow = -1;
	if(pNMItemActivate != NULL)
	{
		if(pNMItemActivate->iItem != -1)
			iSelectRow = pNMItemActivate->iItem;
		else 
			return;
	}
	CString operatorName= m_OperatorNameList.GetItemText(iSelectRow,0);
	//��ʾ������Ϣ
	m_OperatorInfoList.DeleteAllItems();

	map<CString,vector<SINGLE_ITEM>>::iterator iter;
	vector<SINGLE_ITEM> vecSingleSpec;
	iter = OperatorAndItemMap.find(operatorName);  
	if(iter != OperatorAndItemMap.end())  
	{  
		vecSingleSpec = iter->second;  
	}  

	m_OperatorInfoList.ShowWindow(SW_HIDE);
	for (size_t i = 0; i < vecSingleSpec.size(); i++)
	{
		m_OperatorInfoList.InsertItem(i,vecSingleSpec[i].strKey);
		m_OperatorInfoList.SetItemText(i,1,vecSingleSpec[i].strValue);
	}
	m_OperatorInfoList.ShowWindow(SW_SHOW);
}


