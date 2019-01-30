#include "StdAfx.h"
#include "ImplOperator.h"
#include "UTOP_Empty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace UTS
{
    ImplOperator::ImplOperator(void)
    {
        OPERATOR_INIT;
    }

    ImplOperator::~ImplOperator(void)
    {
    }

    BOOL ImplOperator::OnTest(BOOL *pbIsRunning, int *pnErrorCode)
    {
        *pnErrorCode = uts.errorcode.E_Pass;

        // ����Errorcode���ý��
        m_bResult = (*pnErrorCode == uts.errorcode.E_Pass);

        return m_bResult;
    }

    //------------------------------------------------------------------------------
    BaseOperator* GetOperator(void)
    {
        return (new ImplOperator);
    }
    //------------------------------------------------------------------------------
}
