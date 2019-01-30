#include "StdAfx.h"
#include "Algorithm.h"
#include "BaseOtp.h"
#include "CommonFunc.h"
#include "dlmalloc.h"
#include "UTS.h"

#include <direct.h>

int BaseOtp::LoadFW(void *args)
{
	int ret = OTPCALI_ERROR_NO;

	uts.board.ShowMsg(_T("LoadFW..."));              
	ret = do_LoadFW(otp_param.ois_param.FWFilePath);
	uts.board.ShowMsg(_T(" "));              // ȡ����ʾ

	return SET_ERROR(ret);
}

