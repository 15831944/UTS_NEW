
// ChildView.cpp : CChildView ���ʵ��
//

#include "stdafx.h"
#include "UTSMain.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildView ��Ϣ�������

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOWTEXT), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	
	// TODO: �ڴ˴������Ϣ����������
    //RECT rcClient;
    //GetClientRect(&rcClient);
    //dc.FillSolidRect(rcClient.left, rcClient.top,
    //    rcClient.right - rcClient.left,
    //    rcClient.bottom - rcClient.top,
    //    COLOR_BLACK);
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
}



BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    return CWnd::OnEraseBkgnd(pDC);
}
