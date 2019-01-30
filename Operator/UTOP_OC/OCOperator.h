#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm::OC::OC_Std;

#ifdef OC_STD_OPERATOR_EXPORTS
#define OC_STD_OPERATOR_API __declspec(dllexport)
#else
#define OC_STD_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _oc_operator_param_
    {
        double dLTMinY;         // �װ������СYֵ
        double dLTMaxY;         // �װ�������Yֵ
        int nReCapture;         // 0��������  1�����и������С�ץͼƬ������Ķ���
        int nXPixelCountSpec;
		int nYPixelCountSpec;
        double nPixelSize;
		int nCommit_En;
		int nBank_En;
		int nBank0PixelsSpec;
    } OC_OPERATOR_PARAM;

    class OCOperator : public BaseOperator
    {
    public:
        OCOperator(void);
        ~OCOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);
		
		BOOL  is_otp_data_locked(int module_id);
		BOOL is_otp_programed(int module_id);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        //------------------------------------------------------------------------------
        // ����
        OC_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
		double m_dYvalue;
		double m_OffsetX;
		double m_OffsetY;
		double m_OffsetMaxY_X;
		double m_OffsetMaxY_Y;
		POINT m_ptOcCenter;
		POINT m_ptOcCenterMaxY;
		unsigned char m_Bank;
        //------------------------------------------------------------------------------
    };

    extern "C"
    {
        OC_STD_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
