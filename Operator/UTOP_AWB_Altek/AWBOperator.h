#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::AWB;
using namespace UTS::Algorithm::AWB::AWB_Altek;

#ifdef AWB_OPERATOR_EXPORTS
#define AWB_OPERATOR_API __declspec(dllexport)
#else
#define AWB_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _awb_operator_param_
    {
        double dLTMinY;             // �װ������СYֵ
        double dLTMaxY;             // �װ�������Yֵ
        int nReCapture;             // 0��������  1�����и������С�ץͼƬ������Ķ���   
        double dThreshold;
		int nROIWidth;
        int nROIHeight;

    } AWB_OPERATOR_PARAM;

    class AWBOperator : public BaseOperator
    {
    public:
        AWBOperator(void);
        ~AWBOperator(void);

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
        AWB_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
		AWBInfo m_AWBInfo;
        double m_dYvalue;
    };

    extern "C"
    {
        AWB_OPERATOR_API BaseOperator* GetOperator(void);
    }
}

