// stdafx.h : ���ڴ˘��^�n�а����˜ʵ�ϵ�y Include �n��
// ���ǽ���ʹ�Ås����׃����
// �������� Include �n��

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ���^�ų�����ʹ�õĳɆT
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ���_���x���ֵ� CString ������ʽ

#include <afxwin.h>         // MFC �����c�˜�Ԫ��
#include <afxext.h>         // MFC �U�书��

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE e
#include <afxodlgs.h>       // MFC OLE ��Ԓ���Ke
#include <afxdisp.h>        // MFC Automation e
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC �Y�ώ�e
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO �Y�ώ�e
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC ֧Ԯ�� Internet Explorer 4 ͨ�ÿ����
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC ֧Ԯ�� Windows ͨ�ÿ����
#endif // _AFX_NO_AFXCMN_SUPPORT


