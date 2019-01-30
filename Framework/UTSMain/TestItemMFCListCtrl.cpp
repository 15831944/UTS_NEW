// TestItemMFCListCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSMain.h"
#include "TestItemMFCListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestItemMFCListCtrl

IMPLEMENT_DYNAMIC(CTestItemMFCListCtrl, CMFCListCtrl)

CTestItemMFCListCtrl::CTestItemMFCListCtrl()
{
    m_fontItem.CreatePointFont(100, _T("������"), NULL);
}

CTestItemMFCListCtrl::~CTestItemMFCListCtrl()
{
    m_fontItem.DeleteObject();
}


BEGIN_MESSAGE_MAP(CTestItemMFCListCtrl, CMFCListCtrl)
END_MESSAGE_MAP()



// CTestItemMFCListCtrl ��Ϣ�������

COLORREF CTestItemMFCListCtrl::OnGetCellTextColor(int nRow, int nColum)
{
    return CMFCListCtrl::OnGetCellTextColor (nRow, nColum);
}

COLORREF CTestItemMFCListCtrl::OnGetCellBkColor(int nRow, int nColum)
{
    return m_RowBkColor[nRow];
    //return CMFCListCtrl::OnGetCellBkColor(nRow, nColum);
}

HFONT CTestItemMFCListCtrl::OnGetCellFont(int nRow, int nColum, DWORD dwData)
{
    return m_fontItem;
}

void CTestItemMFCListCtrl::SetRowBkColor(int nRow, COLORREF color)
{
    m_RowBkColor[nRow] = color;
}

