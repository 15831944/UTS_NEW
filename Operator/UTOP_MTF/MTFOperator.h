#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::MTF;
using namespace UTS::Algorithm::MTF::MtfStd;

#ifdef MTF_OPERATOR_EXPORTS
#define MTF_OPERATOR_API __declspec(dllexport)
#else
#define MTF_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _fov_operator_param_
    {
        int nReCapture;         // 0��������  1�����и������С�ץͼƬ������Ķ���
        MTF_PARAM mtfParam;
        vector<double> vecFieldSpec;
		vector<double> vecFieldDeltaSpec;
    } MTF_OPERATOR_PARAM;

    class MTFOperator : public BaseOperator
    {
    public:
        MTFOperator(void);
        ~MTFOperator(void);

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
        MTF_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        MTF_RESULT m_result;
        //------------------------------------------------------------------------------
    };

    extern "C"
    {
        MTF_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
