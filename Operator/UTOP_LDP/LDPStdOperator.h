#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::DefectPixel::DefectPixelStd;

#ifdef LDP_STD_OPERATOR_EXPORTS
#define LDP_STD_OPERATOR_API __declspec(dllexport)
#else
#define LDP_STD_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _ldp_operator_param_
    {
        double dLTMinY;             // �װ������СYֵ
        double dLTMaxY;             // �װ�������Yֵ
        int nReCapture;             // 0��������  1�����и������С�ץͼƬ������Ķ���   
        double dThreshold;
        SIZE sizeROI;
        int nSingleSpec;
        int nDoubleSpec;
        int nMultipleSpec;
        int nDefectPixel3ChannelEn;
    } LDP_OPERATOR_PARAM;

    class LDPStdOperator : public BaseOperator
    {
    public:
        LDPStdOperator(void);
        ~LDPStdOperator(void);

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
		void DrawLocationBuffer(unsigned char *pBmpBuffer);
		void SaveLocationBufer(unsigned char *pBMPBuffer);
        //------------------------------------------------------------------------------
        // ����
        LDP_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        H4ISPDefectInfo m_defectInfo;
        AA_TwoDPoint m_DefPointTable[DEFECT_COUNT_MAX];
        double m_dYvalue;
    };

    extern "C"
    {
        LDP_STD_OPERATOR_API BaseOperator* GetOperator(void);
    }
}

