#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::Image;
using namespace UTS::Algorithm::Blemish;
using namespace UTS::Algorithm::Blemish::Blemish_Circle;

#ifdef BLEMISH_CIRCLE_OPERATOR_EXPORTS
#define BLEMISH_CIRCLE_OPERATOR_API __declspec(dllexport)
#else
#define BLEMISH_CIRCLE_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _blemish_operator_param_
    {
        double dLTMinY;         // �װ������СYֵ
        double dLTMaxY;         // �װ�������Yֵ
        int nReCapture;         // 0��������  1�����и������С�ץͼƬ������Ķ���
        int nShowROI;           // 0: Disable  1: Enable
        BlemishCircleParam blemishParam;
		int naverageNum;
    } BLEMISH_OPERATOR_PARAM;

    class BlemishCircleOperator : public BaseOperator
    {
    public:
        BlemishCircleOperator(void);
        ~BlemishCircleOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        //------------------------------------------------------------------------------
        // ����
        BLEMISH_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        double m_dYvalue;
        vector<Circle> m_result;
        //------------------------------------------------------------------------------
    };

    extern "C"
    {
        BLEMISH_CIRCLE_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
