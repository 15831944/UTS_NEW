// TestOperatorListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSMain.h"
#include "TestOperatorListDlg.h"
#include "afxdialogex.h"

typedef enum _e_list_column_index_
{
    Name = 0,
    Version,
    Datetime,
    ColomnSize,
} eListColumIndex;

// CTestOperatorListDlg �Ի���

IMPLEMENT_DYNAMIC(CTestOperatorListDlg, CDialog)

CTestOperatorListDlg::CTestOperatorListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestOperatorListDlg::IDD, pParent)
{
	
}

CTestOperatorListDlg::~CTestOperatorListDlg()
{
}

void CTestOperatorListDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_ALL_OP, m_AllOperatorList);
    DDX_Control(pDX, IDC_LIST_INIT_OP, m_InitOperatorList);
    DDX_Control(pDX, IDC_LIST_TEST_OP, m_TestOperatorList);
    DDX_Control(pDX, IDC_LIST_FINAL_OP, m_FinalOperatorList);
}

BEGIN_MESSAGE_MAP(CTestOperatorListDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CTestOperatorListDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CTestOperatorListDlg::OnBnClickedCancel)
    ON_BN_CLICKED(IDC_BUTTON_APPLY, &CTestOperatorListDlg::OnBnClickedButtonApply)
    // Filter
    ON_EN_CHANGE(IDC_EDIT_FILTER, &CTestOperatorListDlg::OnEnChangeEditFilter)
    // Select
    ON_BN_CLICKED(IDC_BUTTON_ADD_TEST, &CTestOperatorListDlg::OnBnClickedButtonAddTest)
    ON_BN_CLICKED(IDC_BUTTON_ADD_INIT, &CTestOperatorListDlg::OnBnClickedButtonAddInit)
    ON_BN_CLICKED(IDC_BUTTON_ADD_FINAL, &CTestOperatorListDlg::OnBnClickedButtonAddFinal)
    ON_BN_CLICKED(IDC_BUTTON_REFRESH_ALL, &CTestOperatorListDlg::OnBnClickedButtonRefreshAll)
    // Init
    ON_BN_CLICKED(IDC_BUTTON_UP_INDEX_INITOP, &CTestOperatorListDlg::OnBnClickedButtonUpIndexInitop)
    ON_BN_CLICKED(IDC_BUTTON_DOWN_INDEX_INITOP, &CTestOperatorListDlg::OnBnClickedButtonDownIndexInitop)
    ON_BN_CLICKED(IDC_BUTTON_DELETE_INITOP, &CTestOperatorListDlg::OnBnClickedButtonDeleteInitop)
    ON_BN_CLICKED(IDC_BUTTON_EXPORT_INITOP, &CTestOperatorListDlg::OnBnClickedButtonExportInitop)
    ON_BN_CLICKED(IDC_BUTTON_IMPORT_INITOP, &CTestOperatorListDlg::OnBnClickedButtonImportInitop)
    // Test
    ON_BN_CLICKED(IDC_BUTTON_UP_INDEX, &CTestOperatorListDlg::OnBnClickedButtonUpIndexTestop)
    ON_BN_CLICKED(IDC_BUTTON_DOWN_INDEX, &CTestOperatorListDlg::OnBnClickedButtonDownIndexTestop)
    ON_BN_CLICKED(IDC_BUTTON_DELETE, &CTestOperatorListDlg::OnBnClickedButtonDeleteTestop)
    ON_BN_CLICKED(IDC_BUTTON_EXPORT, &CTestOperatorListDlg::OnBnClickedButtonExportTestop)
    ON_BN_CLICKED(IDC_BUTTON_IMPORT, &CTestOperatorListDlg::OnBnClickedButtonImportTestop)
    // Final
    ON_BN_CLICKED(IDC_BUTTON_UP_INDEX_FINALOP, &CTestOperatorListDlg::OnBnClickedButtonUpIndexFinalop)
    ON_BN_CLICKED(IDC_BUTTON_DOWN_INDEX_FINALOP, &CTestOperatorListDlg::OnBnClickedButtonDownIndexFinalop)
    ON_BN_CLICKED(IDC_BUTTON_DELETE_FINALOP, &CTestOperatorListDlg::OnBnClickedButtonDeleteFinalop)
    ON_BN_CLICKED(IDC_BUTTON_EXPORT_FINALOP, &CTestOperatorListDlg::OnBnClickedButtonExportFinalop)
    ON_BN_CLICKED(IDC_BUTTON_IMPORT_FINALOP, &CTestOperatorListDlg::OnBnClickedButtonImportFinalop)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CTestOperatorListDlg ��Ϣ�������


BOOL CTestOperatorListDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��

    //------------------------------------------------------------------------------
    // All Operator List
    DWORD dwStyle = m_AllOperatorList.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;    //ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
    dwStyle |= LVS_EX_GRIDLINES;        //�����ߣ�ֻ������report����listctrl��
    m_AllOperatorList.SetExtendedStyle(dwStyle);   //������չ���
    // ������
    m_AllOperatorList.InsertColumn(eListColumIndex::Name, _T("Name"), LVCFMT_LEFT, 300);
    m_AllOperatorList.InsertColumn(eListColumIndex::Version, _T("Version"), LVCFMT_LEFT, 120);
    m_AllOperatorList.InsertColumn(eListColumIndex::Datetime, _T("Datetime"), LVCFMT_LEFT, 200);
    ShowAllOperatorList();

    //------------------------------------------------------------------------------
    // Initial start Operator List
    m_InitOperatorList.SetExtendedStyle(dwStyle);
    m_InitOperatorList.InsertColumn(eListColumIndex::Name, _T("Name"), LVCFMT_LEFT, 300);
    m_InitOperatorList.InsertColumn(eListColumIndex::Version, _T("Version"), LVCFMT_LEFT, 120);
    m_InitOperatorList.InsertColumn(eListColumIndex::Datetime, _T("Datetime"), LVCFMT_LEFT, 200);

    //------------------------------------------------------------------------------
    // Test Operator List
    m_TestOperatorList.SetExtendedStyle(dwStyle);
    m_TestOperatorList.InsertColumn(eListColumIndex::Name, _T("Name"), LVCFMT_LEFT, 300);
    m_TestOperatorList.InsertColumn(eListColumIndex::Version, _T("Version"), LVCFMT_LEFT, 120);
    m_TestOperatorList.InsertColumn(eListColumIndex::Datetime, _T("Datetime"), LVCFMT_LEFT, 200);

    //------------------------------------------------------------------------------
    // Final Operator List
    m_FinalOperatorList.SetExtendedStyle(dwStyle);
    m_FinalOperatorList.InsertColumn(eListColumIndex::Name, _T("Name"), LVCFMT_LEFT, 300);
    m_FinalOperatorList.InsertColumn(eListColumIndex::Version, _T("Version"), LVCFMT_LEFT, 120);
    m_FinalOperatorList.InsertColumn(eListColumIndex::Datetime, _T("Datetime"), LVCFMT_LEFT, 200);
    
    // ��ȡ���ݿ�
    ReadDBOperatorIndex();

    m_bChanged = FALSE;
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(FALSE);

	//Set scroll range
	RECT rc = {},rect_window = {};
	GetClientRect(&rc);
	GetWindowRect(&rect_window);

	SCROLLINFO si = {};
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_PAGE | SIF_POS | SIF_RANGE;
	si.nPos = si.nMin = 1;

	const SIZE sz = { rc.right - rc.left, rc.bottom - rc.top };
	si.nMax = sz.cy;
	si.nMax = rect_window.bottom - rc.bottom + GetSystemMetrics(SM_CYICON)+2*GetSystemMetrics(SM_CYDLGFRAME);
	si.nPage = 0;
	SetScrollInfo(SB_VERT, &si, FALSE);

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CTestOperatorListDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    // Ӧ�ñ��
    if (GetDlgItem(IDC_BUTTON_APPLY)->IsWindowEnabled())
    {
        OnBnClickedButtonApply();
    }
    // �б仯����ʾ����
    if (m_bChanged)
    {
        uts.MessageRestart(_T("Config changed, to enable new settings UTS must be restarted. Restart now?"));
    }
    CDialog::OnOK();
}

void CTestOperatorListDlg::OnBnClickedCancel()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    // �б仯����ʾ����
    if (m_bChanged)
    {
        uts.MessageRestart(_T("Config changed, to enable new settings UTS must be restarted. Restart now?"));
    }
    CDialog::OnCancel();
}

//------------------------------------------------------------------------------
// All Operator List
void CTestOperatorListDlg::OnBnClickedButtonRefreshAll()
{
    ShowAllOperatorList();
}

void CTestOperatorListDlg::OnBnClickedButtonAddInit()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    POSITION pos = m_AllOperatorList.GetFirstSelectedItemPosition();
    while (pos != nullptr)
    {
        int nSelIndex = m_AllOperatorList.GetNextSelectedItem(pos);
        CString strFileName = m_AllOperatorList.GetItemText(nSelIndex, eListColumIndex::Name);
        AddFileToListTail(m_InitOperatorList, strFileName);
    }
}

void CTestOperatorListDlg::OnBnClickedButtonAddTest()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    POSITION pos = m_AllOperatorList.GetFirstSelectedItemPosition();
    while (pos != nullptr)
    {
        int nSelIndex = m_AllOperatorList.GetNextSelectedItem(pos);
        CString strFileName = m_AllOperatorList.GetItemText(nSelIndex, eListColumIndex::Name);
        AddFileToListTail(m_TestOperatorList, strFileName);
    }
}

void CTestOperatorListDlg::OnBnClickedButtonAddFinal()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    POSITION pos = m_AllOperatorList.GetFirstSelectedItemPosition();
    while (pos != nullptr)
    {
        int nSelIndex = m_AllOperatorList.GetNextSelectedItem(pos);
        CString strFileName = m_AllOperatorList.GetItemText(nSelIndex, eListColumIndex::Name);
        AddFileToListTail(m_FinalOperatorList, strFileName);
    }
}

//------------------------------------------------------------------------------
// Initial start Operator List
void CTestOperatorListDlg::OnBnClickedButtonUpIndexInitop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ListCtrlUpIndexCurrentSel(m_InitOperatorList);
}

void CTestOperatorListDlg::OnBnClickedButtonDownIndexInitop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ListCtrlDownIndexCurrentSel(m_InitOperatorList);
}

void CTestOperatorListDlg::OnBnClickedButtonDeleteInitop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    int nSelIndex = m_InitOperatorList.GetSelectionMark();
    // ɾ��ѡ�е���
    m_InitOperatorList.DeleteItem(nSelIndex);
}

void CTestOperatorListDlg::OnBnClickedButtonExportInitop()
{
    CString strFileName;
    BOOL bRet = ExportFromListToFile(m_InitOperatorList, strFileName);
    if (bRet)
    {
        AfxMessageBox(_T("Success to export ") + strFileName, MB_ICONINFORMATION | MB_OK);
    }
    else
    {
        AfxMessageBox(_T("Fail to export ") + strFileName, MB_ICONERROR | MB_OK);
    }
}

void CTestOperatorListDlg::OnBnClickedButtonImportInitop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ImportFromFileToList(m_InitOperatorList);
}

//------------------------------------------------------------------------------
// Test Operator List
void CTestOperatorListDlg::OnBnClickedButtonUpIndexTestop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ListCtrlUpIndexCurrentSel(m_TestOperatorList);
}

void CTestOperatorListDlg::OnBnClickedButtonDownIndexTestop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ListCtrlDownIndexCurrentSel(m_TestOperatorList);
}

void CTestOperatorListDlg::OnBnClickedButtonDeleteTestop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    int nSelIndex = m_TestOperatorList.GetSelectionMark();
    // ɾ��ѡ�е���
    m_TestOperatorList.DeleteItem(nSelIndex);
}

void CTestOperatorListDlg::OnBnClickedButtonExportTestop()
{
    CString strFileName;
    BOOL bRet = ExportFromListToFile(m_TestOperatorList, strFileName);
    if (bRet)
    {
        AfxMessageBox(_T("Success to export ") + strFileName, MB_ICONINFORMATION | MB_OK);
    }
    else
    {
        AfxMessageBox(_T("Fail to export ") + strFileName, MB_ICONERROR | MB_OK);
    }
}

void CTestOperatorListDlg::OnBnClickedButtonImportTestop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ImportFromFileToList(m_TestOperatorList);
}

//-------------------------------------------------------------------------
// Final Operator List
void CTestOperatorListDlg::OnBnClickedButtonUpIndexFinalop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ListCtrlUpIndexCurrentSel(m_FinalOperatorList);
}

void CTestOperatorListDlg::OnBnClickedButtonDownIndexFinalop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ListCtrlDownIndexCurrentSel(m_FinalOperatorList);
}

void CTestOperatorListDlg::OnBnClickedButtonDeleteFinalop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    int nSelIndex = m_FinalOperatorList.GetSelectionMark();
    // ɾ��ѡ�е���
    m_FinalOperatorList.DeleteItem(nSelIndex);
}

void CTestOperatorListDlg::OnBnClickedButtonExportFinalop()
{
    CString strFileName;
    BOOL bRet = ExportFromListToFile(m_FinalOperatorList, strFileName);
    if (bRet)
    {
        AfxMessageBox(_T("Success to export ") + strFileName, MB_ICONINFORMATION | MB_OK);
    }
    else
    {
        AfxMessageBox(_T("Fail to export ") + strFileName, MB_ICONERROR | MB_OK);
    }
}

void CTestOperatorListDlg::OnBnClickedButtonImportFinalop()
{
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(TRUE);
    ImportFromFileToList(m_FinalOperatorList);
}

//-------------------------------------------------------------------------
void CTestOperatorListDlg::OnBnClickedButtonApply()
{
    // ��Test Operator List�е����ݸ��µ�DB��
    UpdateDBOperatorIndex();
    GetDlgItem(IDC_BUTTON_APPLY)->EnableWindow(FALSE);
    m_bChanged = TRUE;
}

void CTestOperatorListDlg::ShowAllOperatorList(void)
{
    CString strFilter;
    GetDlgItemText(IDC_EDIT_FILTER, strFilter);

    m_AllOperatorList.DeleteAllItems();

    CStringList filelist;
    OSUtil::GetFiles(uts.info.strBinPath, filelist);
    POSITION pos = filelist.GetHeadPosition();
    while (pos != nullptr)
    {
        // �ļ���
        CString strFilename = filelist.GetNext(pos);
        CString strFileExtName = OSUtil::GetExtFileName(strFilename).MakeUpper();
        if (strFileExtName != _T("DLL"))
        {
            continue;
        }

        // �жϷ���Filter
        if (OSUtil::GetFileName(strFilename).MakeUpper().Find(strFilter.MakeUpper()) == -1)
        {
            continue;
        }

        // �ж��Ƿ���Operator
        if (!OSUtil::IsDllExportFunction(strFilename, "GetOperator"))
        {
            continue;
        }
        AddFileToListTail(m_AllOperatorList, OSUtil::GetFileName(strFilename));
    }
    InitDBOperator();
}

void CTestOperatorListDlg::InitDBOperator(void)
{
    for (int i = 0; i < m_AllOperatorList.GetItemCount(); i++)
    {
        CString strFileName = m_AllOperatorList.GetItemText(i, eListColumIndex::Name);
        BOOL bExist = FALSE;
        int nOperatorId = 0;
        if (uts.dbCof.IsOperatorExist(strFileName, bExist, nOperatorId))
        {
            if (!bExist)
            {
                uts.dbCof.AddOperator(strFileName);
            }
        }
    }
}

void CTestOperatorListDlg::ReadDBOperatorIndex(void)
{
    // Init Operator
    vector<CString> vecInitOperatorList;
    if (!uts.dbCof.GetInitOperatorList(vecInitOperatorList))
    {
        CString strMsg = _T("Get init operator list error.");
        uts.log.Error(strMsg);
        AfxMessageBox(strMsg);
    }
    for (int i = vecInitOperatorList.size() - 1; i >= 0; i--)
    {
        AddFileToListHead(m_InitOperatorList, vecInitOperatorList[i]);
    }

    // Test Operator
    vector<CString> vecTestOperatorList;
    if (!uts.dbCof.GetTestOperatorList(vecTestOperatorList))
    {
        CString strMsg = _T("Get test operator list error.");
        uts.log.Error(strMsg);
        AfxMessageBox(strMsg);
    }
    for (int i = vecTestOperatorList.size() - 1; i >= 0; i--)
    {
        AddFileToListHead(m_TestOperatorList, vecTestOperatorList[i]);
    }

    // Final Operator
    vector<CString> vecFinalOperatorList;
    if (!uts.dbCof.GetFinalOperatorList(vecFinalOperatorList))
    {
        CString strMsg = _T("Get Final operator list error.");
        uts.log.Error(strMsg);
        AfxMessageBox(strMsg);
    }
    for (int i = vecFinalOperatorList.size() - 1; i >= 0; i--)
    {
        AddFileToListHead(m_FinalOperatorList, vecFinalOperatorList[i]);
    }
}

void CTestOperatorListDlg::UpdateDBOperatorIndex(void)
{
    CString strOperatorName;
    // Init Operator
    vector<CString> vecInitOperatorList;
    for (int i = 0; i < m_InitOperatorList.GetItemCount(); i++)
    {
        strOperatorName = m_InitOperatorList.GetItemText(i, eListColumIndex::Name);
        uts.log.Debug(_T("Init Operator[%d] = %s"), i, strOperatorName);
        vecInitOperatorList.push_back(strOperatorName);
    }
    uts.dbCof.SetOperatorIndexInit(vecInitOperatorList);

    // Test Operator
    vector<CString> vecTestOperatorList;
    for (int i = 0; i < m_TestOperatorList.GetItemCount(); i++)
    {
        strOperatorName = m_TestOperatorList.GetItemText(i, eListColumIndex::Name);
        uts.log.Debug(_T("Test Operator[%d] = %s"), i, strOperatorName);
        vecTestOperatorList.push_back(strOperatorName);
    }
    uts.dbCof.SetOperatorIndexTest(vecTestOperatorList);

    // Final Operator
    vector<CString> vecFinalOperatorList;
    for (int i = 0; i < m_FinalOperatorList.GetItemCount(); i++)
    {
        strOperatorName = m_FinalOperatorList.GetItemText(i, eListColumIndex::Name);
        uts.log.Debug(_T("Final Operator[%d] = %s"), i, strOperatorName);
        vecFinalOperatorList.push_back(strOperatorName);
    }
    uts.dbCof.SetOperatorIndexFinal(vecFinalOperatorList);
}

void CTestOperatorListDlg::AddFileToListHead(CListCtrl &list, LPCTSTR lpFileName)
{
    int nRow = list.InsertItem(eListColumIndex::Name, OSUtil::GetFileName(lpFileName));
    CString strPathFile = uts.info.strBinPath + OSUtil::GetFileName(lpFileName);
    // �汾
    CString strFileVersion;
    OSUtil::GetFileVersion(strPathFile, strFileVersion);
    list.SetItemText(nRow, eListColumIndex::Version, strFileVersion);
    // ����
    CString strCreateTime;
    CString strAccessTime;
    CString strWriteTime;
    OSUtil::GetFileTimeStr(strPathFile, strCreateTime, strAccessTime, strWriteTime);
    list.SetItemText(nRow, eListColumIndex::Datetime, strWriteTime);
    list.SetSelectionMark(nRow);
}

void CTestOperatorListDlg::AddFileToListTail(CListCtrl &list, LPCTSTR lpFileName)
{
    list.ShowWindow(SW_HIDE);

    int nCount = list.GetItemCount();
    int nRow = list.InsertItem(nCount, OSUtil::GetFileName(lpFileName));
    CString strPathFile = uts.info.strBinPath + OSUtil::GetFileName(lpFileName);
    // �汾
    CString strFileVersion;
    OSUtil::GetFileVersion(strPathFile, strFileVersion);
    list.SetItemText(nRow, eListColumIndex::Version, strFileVersion);
    // ����
    CString strCreateTime;
    CString strAccessTime;
    CString strWriteTime;
    OSUtil::GetFileTimeStr(strPathFile, strCreateTime, strAccessTime, strWriteTime);
    list.SetItemText(nRow, eListColumIndex::Datetime, strWriteTime);
    list.SetSelectionMark(nRow);

    list.ShowWindow(SW_SHOW);
}

void CTestOperatorListDlg::ListCtrlUpIndexCurrentSel(CListCtrl &list)
{
    int nSelIndex = list.GetSelectionMark();
    if (nSelIndex > 0)
    {
        // ����ѡ�е���
        CString strArrCol[eListColumIndex::ColomnSize];
        for (int i = 0; i < eListColumIndex::ColomnSize; i++)
        {
            strArrCol[i] = list.GetItemText(nSelIndex, i);
        }
        // ɾ��ѡ�е���
        list.DeleteItem(nSelIndex);
        // �����ƶ�����
        list.InsertItem(nSelIndex - 1, EMPTY_STR);
        for (int i = 0; i < eListColumIndex::ColomnSize; i++)
        {
            list.SetItemText(nSelIndex - 1, i, strArrCol[i]);
        }
        list.SetSelectionMark(nSelIndex - 1);
    }
}

void CTestOperatorListDlg::ListCtrlDownIndexCurrentSel(CListCtrl &list)
{
    int nSelIndex = list.GetSelectionMark();
    if (nSelIndex < list.GetItemCount() - 1)
    {
        // ����ѡ�е���
        CString strArrCol[eListColumIndex::ColomnSize];
        for (int i = 0; i < eListColumIndex::ColomnSize; i++)
        {
            strArrCol[i] = list.GetItemText(nSelIndex, i);
        }
        // ɾ��ѡ�е���
        list.DeleteItem(nSelIndex);
        // �����ƶ�����
        list.InsertItem(nSelIndex + 1, EMPTY_STR);
        for (int i = 0; i < eListColumIndex::ColomnSize; i++)
        {
            list.SetItemText(nSelIndex + 1, i, strArrCol[i]);
        }
        list.SetSelectionMark(nSelIndex + 1);
    }
}

BOOL CTestOperatorListDlg::ImportFromFileToList(CListCtrl &list)
{
    //------------------------------------------------------------------------------
    // ����ѡ�񵥸��ļ��ĶԻ���
    TCHAR szFileName[MAX_PATH] = {0};
    OPENFILENAME SFN;
    memset(&SFN, 0, sizeof(OPENFILENAME));
    SFN.lStructSize = sizeof(OPENFILENAME);
    SFN.hwndOwner = GetSafeHwnd();
    SFN.lpstrFilter = _T("Operator List File(*.opl)\0*.opl\0\0");
    SFN.lpstrFile = szFileName;
    SFN.nMaxFile = MAX_PATH;
    SFN.Flags = OFN_FILEMUSTEXIST;
    if (!GetOpenFileName(&SFN))
    {
        uts.log.Error(_T("Did not select file."));
        return FALSE;
    }
    FILE *fp = nullptr;
    errno_t nError = _tfopen_s(&fp, szFileName, _T("r"));
    if (nError != 0)
    {
        uts.log.Error(_T("Open file %s error."), szFileName);
        return FALSE;
    }
    // Set pointer to beginning of file:
    fseek(fp, 0L, SEEK_SET);

    if (!list.DeleteAllItems())
    {
        uts.log.Error(_T("m_InitOperatorList.DeleteAllItems error."));
        return FALSE;
    }
    TCHAR szOperatorName[MAX_PATH] = {0};
    while (EOF != _ftscanf(fp, _T("%s"), szOperatorName))
    {
        AddFileToListTail(list, szOperatorName);
    };
    fclose(fp);

    return TRUE;
}

BOOL CTestOperatorListDlg::ExportFromListToFile(CListCtrl &list, CString &strFileName)
{
    //------------------------------------------------------------------------------
    // ����ѡ�񵥸��ļ��ĶԻ���
    TCHAR szFileName[MAX_PATH] = {0};
    OPENFILENAME SFN;
    memset(&SFN, 0, sizeof(OPENFILENAME));
    SFN.lStructSize = sizeof(OPENFILENAME);
    SFN.hwndOwner = GetSafeHwnd();
    SFN.lpstrFilter = _T("Operator List File(*.opl)\0*.opl\0\0");
    SFN.lpstrFile = szFileName;
    SFN.nMaxFile = MAX_PATH;
    if (!GetSaveFileName(&SFN))
    {
        uts.log.Error(_T("Did not select file."));
        return FALSE;
    }
    strFileName = szFileName;
    if (OSUtil::GetExtFileName(strFileName).MakeUpper() != _T("OPL"))
    {
        strFileName.Append(_T(".opl"));
    }
    FILE *fp = nullptr;
    errno_t nError = _tfopen_s(&fp, strFileName, _T("w"));
    if (nError != 0)
    {
        uts.log.Error(_T("Open file %s error."), strFileName);
        return FALSE;
    }
    for (int i = 0; i < list.GetItemCount(); i++)
    {
        CString strFile = list.GetItemText(i, eListColumIndex::Name);
        _ftprintf_s(fp, _T("%s\n"), strFile);
    }
    fclose(fp);
    return TRUE;
}

void CTestOperatorListDlg::OnEnChangeEditFilter()
{
    // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
    // ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
    // ���������� CRichEditCtrl().SetEventMask()��
    // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    ShowAllOperatorList();
}


void CTestOperatorListDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	
	//GetScrollPos
	SCROLLINFO si = {};
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_PAGE | SIF_POS | SIF_RANGE | SIF_TRACKPOS;
	GetScrollInfo(SB_VERT, &si);

	const int minPos = si.nMin;
	const int maxPos = si.nMax - (si.nPage - 1);

	int result = -1;

	switch(nSBCode)
	{
	case SB_LINEUP /*SB_LINELEFT*/:
		result = max(si.nPos - 1, minPos);
		break;

	case SB_LINEDOWN /*SB_LINERIGHT*/:
		result = min(si.nPos + 1, maxPos);
		break;

	case SB_PAGEUP /*SB_PAGELEFT*/:
		result = max(si.nPos - (int)si.nPage, minPos);
		break;

	case SB_PAGEDOWN /*SB_PAGERIGHT*/:
		result = min(si.nPos + (int)si.nPage, maxPos);
		break;

	case SB_THUMBPOSITION:
		// do nothing
		break;

	case SB_THUMBTRACK:
		result = si.nTrackPos;
		break;

	case SB_TOP /*SB_LEFT*/:
		result = minPos;
		break;

	case SB_BOTTOM /*SB_RIGHT*/:
		result = maxPos;
		break;

	case SB_ENDSCROLL:
		// do nothing
		break;
	}

	if(result < 0)
		return;
	SetScrollPos(SB_VERT, result, TRUE);

	static int s_prevx = 1;
	static int s_prevy = 1;

	int cx = 0;
	int cy = 0;

	int& delta = (pScrollBar == SB_HORZ ? cy : cx);
	int& prev = (pScrollBar == SB_HORZ ? s_prevy : s_prevx);

	delta = prev - nPos;
	prev = nPos;

	if(cx || cy)
	{
		ScrollWindow(cx, cy, NULL, NULL);
	}

	uts.log.Debug(_T("Scroll pos :%d"), result);

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CTestOperatorListDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
