// MulitLineListBox.cpp : implementation file
//
#include "stdafx.h"
#include "UTSBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorListBox

namespace UTS
{
    CColorListBox::CColorListBox()
    {
    }

    CColorListBox::~CColorListBox()
    {
    }


    BEGIN_MESSAGE_MAP(CColorListBox, CListBox)
        //{{AFX_MSG_MAP(CColorListBox)
        ON_WM_DESTROY()
        //}}AFX_MSG_MAP
    END_MESSAGE_MAP()

    /////////////////////////////////////////////////////////////////////////////
    // CColorListBox message handlers
    void CColorListBox::AppendString(LPCTSTR lpszText, COLORREF fgColor, COLORREF bgColor)
    {
        LISTBOX_COLOR* pInfo = new LISTBOX_COLOR;

        pInfo->strText.Format(_T("%s"), lpszText);
        pInfo->fgColor = fgColor; 
        pInfo->bgColor = bgColor;

        SetItemDataPtr(AddString(pInfo->strText), pInfo);
    }

    void CColorListBox::DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct)
    {
        ASSERT(lpDeleteItemStruct->CtlType == ODT_LISTBOX);

        LISTBOX_COLOR* pList = (LISTBOX_COLOR*)(lpDeleteItemStruct->itemData);
        RELEASE_POINTER(pList);
    }
    void CColorListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
    {
        // TODO: Add your code to determine the size of specified item
        ASSERT(lpMeasureItemStruct->CtlType == ODT_LISTBOX);

        CString strText(_T(""));
        GetText(lpMeasureItemStruct->itemID, strText);
        ASSERT(TRUE != strText.IsEmpty());

        CRect rect;
        GetItemRect(lpMeasureItemStruct->itemID, &rect);

        CDC* pDC = GetDC(); 
        lpMeasureItemStruct->itemHeight = pDC->DrawText(strText, -1, rect, DT_WORDBREAK | DT_CALCRECT); 
        ReleaseDC(pDC);
    }

    void CColorListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
    {
        // TODO: Add your code to draw the specified item
        ASSERT(lpDrawItemStruct->CtlType == ODT_LISTBOX);

        LISTBOX_COLOR* pListBox = (LISTBOX_COLOR*)GetItemDataPtr(lpDrawItemStruct->itemID);
        ASSERT(NULL != pListBox);

        CDC dc;

        dc.Attach(lpDrawItemStruct->hDC);

        // Save these value to restore them when done drawing.
        COLORREF crOldTextColor = dc.GetTextColor();
        COLORREF crOldBkColor = dc.GetBkColor();

        // If this item is selected, set the background color 
        // and the text color to appropriate values. Also, erase
        // rect by filling it with the background color.
        if ((lpDrawItemStruct->itemAction | ODA_SELECT) &&
            (lpDrawItemStruct->itemState & ODS_SELECTED))
        {
            dc.SetTextColor(pListBox->bgColor);
            dc.SetBkColor(pListBox->fgColor);
            dc.FillSolidRect(&lpDrawItemStruct->rcItem, pListBox->fgColor);
        }
        else
        {
            dc.SetTextColor(pListBox->fgColor);
            dc.SetBkColor(pListBox->bgColor);
            dc.FillSolidRect(&lpDrawItemStruct->rcItem, pListBox->bgColor);
        }

        lpDrawItemStruct->rcItem.left += 5;
        // Draw the text.

        dc.DrawText(pListBox->strText, pListBox->strText.GetLength(), &lpDrawItemStruct->rcItem, DT_LEFT);

        // Reset the background color and the text color back to their
        // original values.
        dc.SetTextColor(crOldTextColor);
        dc.SetBkColor(crOldBkColor);

        dc.Detach();	
    }


    void CColorListBox::OnDestroy() 
    {
        CListBox::OnDestroy();
        // TODO: Add your message handler code here	

        // 最后的时候，会对每一个列表中的数据，调用DeleteItem，这里Delete，反而会出错
        //int nCount = GetCount();
        //for (int i = 0; i < nCount; i++)
        //{
        //    LISTBOX_COLOR* pList = (LISTBOX_COLOR*)GetItemDataPtr(i);
        //    RELEASE_POINTER(pList);
        //}
    }
}