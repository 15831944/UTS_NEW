#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::DFOV;
using namespace UTS::Algorithm::DFOV::DFOV_Rectangle;

#ifdef FOV_OPERATOR_EXPORTS
#define FOV_OPERATOR_API __declspec(dllexport)
#else
#define FOV_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _fov_operator_param_
    {
        int nReCapture;         // 0��������  1�����и������С�ץͼƬ������Ķ���
        FOV_PARAM fovParam;
    } FOV_OPERATOR_PARAM;

    class FovOperator : public BaseOperator
    {
    public:
        FovOperator(void);
        ~FovOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnPreview(unsigned char *pBmpBuffer, int nWidth, int nHeight, UI_MARK &uiMark);
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        //------------------------------------------------------------------------------
        // ����
        FOV_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        FOV_RESULT m_result;
        //------------------------------------------------------------------------------
    };

    extern "C"
    {
        FOV_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
