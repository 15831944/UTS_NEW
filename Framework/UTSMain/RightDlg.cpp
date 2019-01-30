// ControlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UTSMain.h"
#include "RightDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"


const int POINT_SIZE_MESSAGE = 140;
const int POINT_SIZE_SN = 140;
const int POINT_SIZE_ERRORCODE = 140;

#define GET_HEIGHT_BY_POINT_SIZE(x) ((x) / 5)

// CControlDlg �Ի���

IMPLEMENT_DYNAMIC(CRightDlg, CDialog)

CRightDlg::CRightDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(CRightDlg::IDD, pParent)
    , m_bInitialized(FALSE)
    , m_bBlinkOn(FALSE) // fix ���� #1: ��ʾ��Ϣ��Ŀ����
{

}

CRightDlg::~CRightDlg()
{
}

void CRightDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_ITEM, m_ItemList);
}


BEGIN_MESSAGE_MAP(CRightDlg, CDialog)
    ON_WM_SIZING()
    ON_WM_MOVE()
    ON_WM_PAINT()
    ON_WM_ERASEBKGND()
    ON_WM_DESTROY()
    ON_MESSAGE(WM_BOARD_MSG, OnBoardMsg)
    ON_MESSAGE(WM_BOARD_SN, OnBoardSN)
    ON_MESSAGE(WM_BOARD_STATUS, OnBoardStatus)
    ON_MESSAGE(WM_BOARD_ERRORMSG, OnBoardErrorMsg)
    ON_MESSAGE(WM_BOARD_ITEMLIST, OnBoardItemList)
    ON_MESSAGE(WM_BOARD_ADJUST, OnBoardAdjust)
    ON_WM_TIMER()   // fix ���� #1: ��ʾ��Ϣ��Ŀ����
END_MESSAGE_MAP()

#pragma region UI Interface
LRESULT CRightDlg::OnBoardAdjust(WPARAM wparam, LPARAM lparam)
{
    AdjustWindow();
    return 0;
}

LRESULT CRightDlg::OnBoardMsg(WPARAM wparam, LPARAM lparam)
{
    m_strMsg = uts.board.m_strMsg;
    InvalidateRect(&m_rcMsg);
    return 0;
}

LRESULT CRightDlg::OnBoardSN(WPARAM wparam, LPARAM lparam)
{
    m_SN = uts.info.strSN;
    InvalidateRect(&m_rcSN);
    return 0;
}

LRESULT CRightDlg::OnBoardStatus(WPARAM wparam, LPARAM lparam)
{
    CString strResFileName;
    if (!m_image.IsNull())
    {
        m_image.Destroy();
    }
    eBoardStatus status = (eBoardStatus)wparam;
    switch (status)
    {
    case eBoardStatus::Status_Initializing:
        strResFileName = uts.info.strBinPath + _T("Res\\Initializing");
        break;
    case eBoardStatus::Status_Ready:
        strResFileName = uts.info.strBinPath + _T("Res\\Ready");
        break;
    case eBoardStatus::Status_Testing:
        strResFileName = uts.info.strBinPath + _T("Res\\TESTING");
        break;
    case eBoardStatus::Status_Stop:
        strResFileName = uts.info.strBinPath + _T("Res\\STOP");
        break;
    case eBoardStatus::Status_Pass:
        strResFileName = uts.info.strBinPath + _T("Res\\PASS");
        break;
    case eBoardStatus::Status_Fail:
        strResFileName = uts.info.strBinPath + _T("Res\\FAIL");
        break;
    case eBoardStatus::Status_UserDefine:
        strResFileName = uts.info.strBinPath + _T("Res\\") + uts.board.m_strResName;
        break;
    default:
        break;
    }

    strResFileName += _T(".PNG");
    m_image.Load(strResFileName);

    InvalidateRect(&m_rcImage);
    return 0;
}

LRESULT CRightDlg::OnBoardErrorMsg(WPARAM wparam, LPARAM lparam)
{
    m_strErrorMsg = uts.board.m_strErrorMsg;
    InvalidateRect(&m_rcErrorCode);
    return 0;
}

LRESULT CRightDlg::OnBoardItemList(WPARAM wparam, LPARAM lparam)
{
    eBoardItemList status = (eBoardItemList)wparam;
    int nItemIndex = (int)lparam;
    vector<OPERATOR_INFO>::iterator itorOp;
    switch (status)
    {
    case eBoardItemList::BIL_Init:
        m_ItemList.DeleteAllItems();
        // Operator list
        for (itorOp = uts.flow.m_vecOpList.begin(); itorOp != uts.flow.m_vecOpList.end(); itorOp++)
        {
            CString strOpName = OSUtil::GetMainFileName((*itorOp).strFileName);
            int nIndex = (*itorOp).nIndex;
            int nRow = m_ItemList.InsertItem(nIndex, strOpName);
            m_ItemList.SetRowBkColor(nIndex, COLOR_WHITE);
        }
        break;
    case eBoardItemList::BIL_SetItemPass:
        m_ItemList.SetRowBkColor(nItemIndex, COLOR_GREEN);
        break;
    case eBoardItemList::BIL_SetItemFail:
        m_ItemList.SetRowBkColor(nItemIndex, COLOR_RED);
        break;
    case eBoardItemList::BIL_SetItemTesting:
        m_ItemList.SetRowBkColor(nItemIndex, COLOR_YELLOW);
        m_ItemList.EnsureVisible(nItemIndex, FALSE);
        break;
    default:
        break;
    }
    InvalidateRect(&m_rcResult);   // fix bug #9: �װ����ʱRI/LDP/BL�������ʱ��ˢ��RI/LDPֱ�ӵ�BL
    return 0;
}
#pragma endregion

// CControlDlg ��Ϣ�������


BOOL CRightDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    m_bInitialized = TRUE;

    //------------------------------------------------------------------------------
    // create font
    m_fontMsg.CreatePointFont(POINT_SIZE_MESSAGE, _T("������"), NULL);
    m_fontSN.CreatePointFont(POINT_SIZE_SN, _T("������"), NULL);
    m_fontErrorcode.CreatePointFont(POINT_SIZE_ERRORCODE, _T("������"), NULL);

    // Test items
    DWORD dwStyle = m_ItemList.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;    //ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
    dwStyle |= LVS_EX_GRIDLINES;        //�����ߣ�ֻ������report����listctrl��
    m_ItemList.SetExtendedStyle(dwStyle);   //������չ���

    // set row height
    CImageList  m_l;   
    m_l.Create(1, GET_HEIGHT_BY_POINT_SIZE(100), TRUE | ILC_COLOR32, 1, 0);   
    m_ItemList.SetImageList(&m_l, LVSIL_SMALL);
    m_l.DeleteImageList();

    // ������
    m_ItemList.InsertColumn(0, _T("Test Item"), LVCFMT_LEFT, 170);

    SetTimer(1, 900, NULL); // fix ���� #1: ��ʾ��Ϣ��Ŀ����

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CRightDlg::OnDestroy()
{
    CDialog::OnDestroy();

    // TODO: �ڴ˴������Ϣ����������
    KillTimer(1);   // fix ���� #1: ��ʾ��Ϣ��Ŀ����
    //------------------------------------------------------------------------------
    // delete font
    m_fontMsg.DeleteObject();
    m_fontSN.DeleteObject();
    m_fontErrorcode.DeleteObject();
}

void CRightDlg::OnOK()
{
    // TODO: �ڴ����ר�ô����/����û���

    //CDialog::OnOK();
}


void CRightDlg::OnCancel()
{
    // TODO: �ڴ����ר�ô����/����û���

    //CDialog::OnCancel();
}


void CRightDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
    CDialog::OnSizing(fwSide, pRect);

    // TODO: �ڴ˴������Ϣ����������
    AdjustWindow();
}


void CRightDlg::OnMove(int x, int y)
{
    CDialog::OnMove(x, y);

    // TODO: �ڴ˴������Ϣ����������
    if (m_bInitialized)
    {
        AdjustWindow();
    }
}

void CRightDlg::AdjustWindow(void)
{
    const int MARGIN = 5;
    LONG lLastBottom = 0;
    RECT rcClient = {0};
    GetClientRect(&rcClient);

    // Msg
    m_rcMsg.left = rcClient.left + MARGIN;
    m_rcMsg.right = rcClient.right - MARGIN;
    m_rcMsg.top = rcClient.top + MARGIN * 2;
    lLastBottom = m_rcMsg.bottom = m_rcMsg.top + GET_HEIGHT_BY_POINT_SIZE(POINT_SIZE_MESSAGE);

    // SN
    m_rcSN.left = rcClient.left + MARGIN;
    m_rcSN.right = rcClient.right - MARGIN;
    m_rcSN.top = lLastBottom + MARGIN;
    lLastBottom = m_rcSN.bottom = m_rcSN.top + GET_HEIGHT_BY_POINT_SIZE(POINT_SIZE_SN);

    // Status image
    m_rcImage.left = rcClient.left + MARGIN * 2;
    m_rcImage.right = rcClient.right - MARGIN * 2;
    m_rcImage.top = lLastBottom + MARGIN;
    lLastBottom = m_rcImage.bottom = m_rcImage.top + 150 * m_rcImage.Width() / 500;

    // Error code
    m_rcErrorCode.left = rcClient.left + MARGIN;
    m_rcErrorCode.right = rcClient.right - MARGIN;
    m_rcErrorCode.top = lLastBottom + MARGIN;
    lLastBottom = m_rcErrorCode.bottom = m_rcErrorCode.top + GET_HEIGHT_BY_POINT_SIZE(POINT_SIZE_ERRORCODE);

    // Result
    m_rcResult.left = rcClient.left + MARGIN;
    m_rcResult.right = rcClient.right - MARGIN;
    m_rcResult.top = lLastBottom + MARGIN;
    m_rcResult.bottom = rcClient.bottom - MARGIN;

    GetDlgItem(IDC_LIST_ITEM)->MoveWindow(&m_rcResult);
    Invalidate(TRUE);
}

void CRightDlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: �ڴ˴������Ϣ����������

    CMemDC memdc(dc, this);
    CDC& drawDC = memdc.GetDC();

    //------------------------------------------------------------------------------
    // ���õ�ɫ
    RECT rcClient = {0};
    GetClientRect(&rcClient);
    drawDC.FillSolidRect(&rcClient, COLOR_WHITE);

    drawDC.SetTextAlign(TA_CENTER);
    CFont *poldFont = nullptr;
    //------------------------------------------------------------------------------
    // Message
    //-------------------------------------------------------------------------
    // fix ���� #1: ��ʾ��Ϣ��Ŀ����
    CPen *pOldPen = (CPen*)drawDC.SelectStockObject(BLACK_PEN);
    CBrush brushMsg;
    if (m_strMsg.GetLength() == 0 || !uts.info.nMsgBlinkEn)
    {
        brushMsg.CreateSolidBrush(COLOR_WHITE);
    }
    else if (m_bBlinkOn)
    {
        brushMsg.CreateSolidBrush(COLOR_YELLOW);
    }
    else
    {
        brushMsg.CreateSolidBrush(COLOR_BLUE);
    }
    CBrush *pOldBrush = drawDC.SelectObject(&brushMsg);
    drawDC.Rectangle(&m_rcMsg);
    drawDC.SelectObject(pOldBrush);
    brushMsg.DeleteObject();
    drawDC.SelectObject(pOldPen);
    poldFont = drawDC.SelectObject(&m_fontMsg);
    if (m_strMsg.GetLength() == 0 || !uts.info.nMsgBlinkEn)
    {
        drawDC.SetBkColor(COLOR_WHITE);
    }
    else if (m_bBlinkOn)
    {
        drawDC.SetTextColor(COLOR_BLUE);
        drawDC.SetBkColor(COLOR_YELLOW);
    }
    else
    {
        drawDC.SetTextColor(COLOR_YELLOW);
        drawDC.SetBkColor(COLOR_BLUE);
    }
    drawDC.ExtTextOut(m_rcMsg.left + m_rcMsg.Width() / 2, m_rcMsg.top + 2, 0, 0,
        m_strMsg,
        m_strMsg.GetLength(),
        NULL);
    drawDC.SelectObject(poldFont);
    drawDC.SetBkColor(COLOR_WHITE);
    //-------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    // SN
    drawDC.Rectangle(&m_rcSN);
    poldFont = drawDC.SelectObject(&m_fontSN);
    drawDC.SetTextColor(COLOR_BLACK);
    drawDC.ExtTextOut(m_rcSN.left + m_rcSN.Width() / 2, m_rcSN.top + 2, 0, 0,
        m_SN,
        m_SN.GetLength(),
        NULL);
    drawDC.SelectObject(poldFont);
    //------------------------------------------------------------------------------
    // Error code
    drawDC.Rectangle(&m_rcErrorCode);
    poldFont = drawDC.SelectObject(&m_fontErrorcode);
    drawDC.SetTextColor(COLOR_RED);
    drawDC.ExtTextOut(m_rcErrorCode.left + m_rcErrorCode.Width() / 2, m_rcErrorCode.top + 2, 0, 0,
        m_strErrorMsg,
        m_strErrorMsg.GetLength(),
        NULL);
    drawDC.SetTextAlign(TA_LEFT);
    drawDC.SelectObject(poldFont);

    if (!m_image.IsNull())
    {
        m_image.Draw(
            drawDC.m_hDC,
            m_rcImage.left,
            m_rcImage.top,
            m_rcImage.Width(),
            m_rcImage.Height(),
            0, 0, 500, 150);
    }

    // ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}

BOOL CRightDlg::OnEraseBkgnd(CDC* pDC)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    return FALSE;   // ��ֹ��˸
    //return CDialog::OnEraseBkgnd(pDC);
}

BOOL CRightDlg::PreTranslateMessage(MSG* pMsg)
{
    // TODO: �ڴ����ר�ô����/����û���
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_RETURN)
        {
            uts.keyboard.OnKeyReturn();
        }
        else if (pMsg->wParam == VK_SPACE)
        {
            uts.keyboard.OnKeySpace();
        }
        else if (pMsg->wParam >= 0x30 && pMsg->wParam <= 0x39)  // 0-9
        {
            uts.keyboard.OnKeyChar(pMsg->wParam);
        }
        else if (pMsg->wParam >= 0x41 && pMsg->wParam <= 0x5A)  // A-Z
        {
            uts.keyboard.OnKeyChar(pMsg->wParam);
        }
		else if (pMsg->wParam == 0xbd || pMsg->wParam == 0x2d)  // "-"
		{
			uts.keyboard.OnKeyChar(0x2d);
		}
        //-------------------------------------------------------------------------
        // fix ���� #7: С���̲�������
        else if (pMsg->wParam >= VK_NUMPAD0 && pMsg->wParam <= VK_NUMPAD9)  // С����0-9
        {
            uts.keyboard.OnKeyChar(pMsg->wParam - 0x30);
        }
        //-------------------------------------------------------------------------
        //------------------------------------------------------------------------------
        // fix bug #6: SN�������ɾ�����߸���
        else if (pMsg->wParam == VK_BACK)
        {
            uts.keyboard.OnKeyBackspace();
        }
        //------------------------------------------------------------------------------
    }

    return CDialog::PreTranslateMessage(pMsg);
}

//-------------------------------------------------------------------------
// fix ���� #1: ��ʾ��Ϣ��Ŀ����
void CRightDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    if (nIDEvent == 1)
    {
        m_bBlinkOn = !m_bBlinkOn;
        InvalidateRect(&m_rcMsg);
    }
    CDialog::OnTimer(nIDEvent);
}
//-------------------------------------------------------------------------
