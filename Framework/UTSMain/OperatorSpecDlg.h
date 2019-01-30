#pragma once
#include "OperatorMergerDlg.h"
#include "afxwin.h"
// OperatorSpecDlg �Ի���

class COperatorSpecDlg : public CDialog
{
	DECLARE_DYNAMIC(COperatorSpecDlg)

public:
	COperatorSpecDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COperatorSpecDlg();

// �Ի�������
	enum { IDD = IDD_OperatorSpecDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonExportOpelist();
	afx_msg void OnBnClickedButtonImportOpelist();

	BOOL doMergerOp(vector<CString> &operatorList, map<CString,vector<SINGLE_ITEM>> &OperatorAndItemMap);
private:
    CMFCPropertyGridCtrl m_propertyGrid;
	COperatorMergerDlg operatorMergerDlg;
    vector<OPERATOR_SPEC> m_vecAllSpec;
	vector<OPERATOR_SPEC> m_importVecAllSpec;

	BOOL ExportFromVectToXMLFile(vector<OPERATOR_SPEC> &OpeSpec, CString &strFileName);
	BOOL ImportFromXMLFileToVect(vector<OPERATOR_SPEC> &allOpeSpec);

};
