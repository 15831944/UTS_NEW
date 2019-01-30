#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"
#include "CommonFunc.h"
#include "StackQueue.h"

using namespace UTS::Algorithm::Image;
using namespace UTS::Algorithm::SFR::SfrCalc;
using namespace UTS::Algorithm::SFR::SfrPlus;
using namespace UTS::Algorithm::SFRBlock;

#ifdef RESOLUTION_OPERATOR_EXPORTS
#define RESOLUTION_OPERATOR_API __declspec(dllexport)
#else
#define RESOLUTION_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    //-------------------------------------------------------------------------
    typedef struct _whitepatch_info_
    {
        SIZE sizeDisFromCT;
        int nROISize;
    } WHITEPATCH_INFO;

    typedef struct _single_sfr_roi_info_
    {
		int nSfrType;       // 0:Real, 1:AllAverage, 2: MidAverage
		int nSfrStackCount;

        int nIndex;             // ������
        double dROIField;       // ROI���ĵ������ӳ�
        double dROIAngle;       // ROI���ĵ�ļ�����Ƕ�(0-359.9999)
        CString strROIName;     // ROI��
    } SINGLE_SFR_ROI_INFO;

    typedef struct _single_field_info_
    {
        //int nIndex;             // ������
        //int nEnable;            // ����
        double dHiSpec;         // HiFrq���
        double dHiDeltaSpec;    // HiFrq������
        vector<int> vecSfrIndex;// sfr�б�
    } SINGLE_FIELD_INFO;

    typedef struct _sfr_info_
    {
        int nSfrType;       // 0:Real, 1:AllAverage, 2: MidAverage
        int nSfrStackCount;
        SIZE sizeSFR_ROI;
        double dFrqNum[SFR_Frq_SIZES];
        double dSFRScore;

        int nSfrRoiCount;
        vector<SINGLE_SFR_ROI_INFO> vecSfrRoi; // sfr roi �б�
        int nFieldCount;                    // �����ӳ�����
        vector<SINGLE_FIELD_INFO> vecField; // �ӳ��б�
    } SFR_INFO;

    typedef struct _sfr_plus_operator_param_
    {
        int nFixRoiEn;
        int nManualThroughFocusEn;
        int nManualThroughFocusFrameCount;
        WHITEPATCH_INFO whitePatch;
        SFR_INFO sfr;
		SIZE DetectSFRROI;
    } SFR_PLUS_OPERATOR_PARAM;

    //-------------------------------------------------------------------------
    // ���
    typedef struct _single_field_result_
    {
        double dMinSfr[SFR_Frq_SIZES];
        double dAvgSfr[SFR_Frq_SIZES];
        double dSfrDelta[SFR_Frq_SIZES];
    } SINGLE_FIELD_RESULT;

    typedef struct _sfr_plus_operator_result_
    {
        SFRPLUS_RESULT stSfrResult;
        vector<SINGLE_FIELD_RESULT> vecFieldResult;
        //double dYvalue;
        double dCenterYavg;
        BOOL bIsCenterYExp;
        RECT rcWhitePatch;
    } SFR_PLUS_OPERATOR_RESULT;

    class ResolutionOperator : public BaseOperator
    {
    public:
        ResolutionOperator(void);
        ~ResolutionOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnPreview(unsigned char *pBmpBuffer, int nWidth, int nHeight, UI_MARK &uiMark);
		virtual void OnPreviewStart();
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);
    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        CSfrPlus m_SfrPlus;
        CSfrStackQueue m_SfrQueue;
		BOOL m_bEnableStack;
        //------------------------------------------------------------------------------
        // ����
        SFR_PLUS_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        SFR_PLUS_OPERATOR_RESULT m_result;
        //------------------------------------------------------------------------------

        void SaveThroughFocus(LPCTSTR lpOperatorName);
        BOOL DoImageSFRTest(int *pnErrorCode);
    };

    extern "C"
    {
        RESOLUTION_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
