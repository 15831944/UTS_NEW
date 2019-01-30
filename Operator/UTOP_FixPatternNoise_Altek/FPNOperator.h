#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::FixPatternNoise::FixPatternNoise_WD;

#ifdef FPN_OPERATOR_EXPORTS
#define FPN_OPERATOR_API __declspec(dllexport)
#else
#define FPN_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _fpn_operator_param_
    {
        double dLTMinY;             // �װ������СYֵ
        double dLTMaxY;             // �װ�������Yֵ
        int nReCapture;             // 0��������  1�����и������С�ץͼƬ������Ķ���   
        double dThreshold;
    } FPN_OPERATOR_PARAM;

    class FPNOperator : public BaseOperator
    {
    public:
        FPNOperator(void);
        ~FPNOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        //------------------------------------------------------------------------------
        // �ڲ�����
        void SaveLocationData(LPCTSTR lpOperatorName);
        //------------------------------------------------------------------------------
        // ����
        FPN_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        FPNInfo m_defectInfo;
        double m_dYvalue;
    };

    extern "C"
    {
        FPN_OPERATOR_API BaseOperator* GetOperator(void);
    }
}

