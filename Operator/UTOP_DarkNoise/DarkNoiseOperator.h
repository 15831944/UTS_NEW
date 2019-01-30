#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::DarkNoise;
using namespace UTS::Algorithm::DarkNoise::DarkNoise_WholeImage;
using namespace UTS::Algorithm::Image;

#ifdef DARKNOISE_OPERATOR_EXPORTS
#define DARKNOISE_OPERATOR_API __declspec(dllexport)
#else
#define DARKNOISE_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _darknoise_operator_param_
    {
		RECT TestROI;
        double dDDMaxY;             // �ڰ�������Yֵ
        int nReCapture;             // 0��������  1�����и������С�ץͼƬ������Ķ���  
		MinMax<double> dNoiseSpec;
    } DARKNOISE_OPERATOR_PARAM;

    class DarkNoiseOperator : public BaseOperator
    {
    public:
        DarkNoiseOperator(void);
        ~DarkNoiseOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);
		virtual BOOL OnPreview(const TEST_BUFFER &bufferObj, int nWidth, int nHeight, UI_MARK &uiMark);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        //------------------------------------------------------------------------------
        // ����
        DARKNOISE_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        double m_dStdDevY;
        double m_dYvalue;
    };

    extern "C"
    {
        DARKNOISE_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
