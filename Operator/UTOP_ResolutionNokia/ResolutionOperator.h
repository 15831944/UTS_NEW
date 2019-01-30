#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"
#include "StackQueue.h"
#include "CommonFunc.h"

using namespace UTS::Algorithm::Image;
using namespace UTS::Algorithm::CrossHair;
using namespace UTS::Algorithm::SFR::SfrCalc;
using namespace UTS::Algorithm::SFR::SfrPlus;
using namespace UTS::Algorithm::PreFocus;
using namespace UTS::Algorithm::ThroughFocus;

#ifdef RESOLUTION_OPERATOR_EXPORTS
#define RESOLUTION_OPERATOR_API __declspec(dllexport)
#else
#define RESOLUTION_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    #define Max_VCM_DAC		1024

    //-------------------------------------------------------------------------
    // ����
    typedef struct _vcm_param_
    {
        int nVCM_ThroughDriveEn;
        int nVCM_ThroughROIIndex;
        int nVCM_StepTime;
        int nVCM_FinalDelayTime;
        int nVCM_GetDelayTime;
        int nVCM_DACMin;
        int nVCM_DACMax;
        int nVCM_DACStep;
        int nVCM_ReverseThroughEn;
        int nVCM_MeasureCurrentEn;
        int nVCM_CurrentPIN;
        int nVCM_NotMovingThreshold;
        int nVCM_PreThroughEn;
        int nVCM_PreThroughDivideCount;
        int nVCM_PreThroughStepTime;
        double dVCM_PreThroughDownPersent;
        double dVCM_PreThroughPeakMin;
        int nGlitch_DetectEn;
        int nGlitch_SmoothEn;
        int nGlitch_Threshold;
    } VCM_PARAM;

    typedef struct _crosshair_info_
    {
        SIZE sizeDisFromCT;
        int nROISize;
        double dCodeVariation;
        double dField; // ��λʮ�ֽ��������ӳ�
    } CROSSHAIR_INFO;

    typedef struct _whitepatch_info_
    {
        SIZE sizeDisFromCT;
        int nROISize;
    } WHITEPATCH_INFO;

    typedef struct _weight_info_
    {
        int nHiEnable;
        double dHiSpec;
        double dHiDiffSpec;
    } WEIGHT_INFO;

    typedef struct _divide_spec_
    {
        int nEnable;
        int nFieldIndex; 
        int nSpecA;
        int nSpecB;
        int nSpecC;
    } DIVIDE_SPEC;

    typedef struct _single_sfr_roi_info_
    {
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
        double dWeight;         // Ȩ��
        double dDeltaWeight;    // ����Ȩ��
        vector<int> vecSfrIndex;// sfr�б�
    } SINGLE_FIELD_INFO;

	typedef enum _e_sfr_frq_
	{
		SFR_DELTA_LTRB = 0,
		SFR_DELTA_RTLB,	
		SFR_DELTA_SIZES
	} eSfrFrq;

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
        CROSSHAIR_INFO crosshair;
        WHITEPATCH_INFO whitePatch;
        WEIGHT_INFO weight;
        DIVIDE_SPEC divideSpec;
        SFR_INFO sfr;
        VCM_PARAM vcm;

		//Commit DAC to DB
		int nAF_Commit_Type;
		int nStartCurrent_En;
    } SFR_PLUS_OPERATOR_PARAM;

    //-------------------------------------------------------------------------
    // ���
    typedef struct _single_field_result_
    {
        double dMinSfr[SFR_Frq_SIZES];
        double dAvgSfr[SFR_Frq_SIZES];
        double dSfrDelta[SFR_DELTA_SIZES];
    } SINGLE_FIELD_RESULT;

    typedef struct _sfr_plus_operator_result_
    {
        SFRPLUS_RESULT stSfrResult;
        vector<SINGLE_FIELD_RESULT> vecFieldResult;
        //double dYvalue;
        double dCenterYavg;
        BOOL bIsCenterYExp;
        RECT rcWhitePatch;
        double dWeightSfr[SFR_Frq_SIZES];
        double dWeightMax[SFR_Frq_SIZES];
        double dWeightDiff[SFR_Frq_SIZES];
        double dThroughVCMCurrent[Max_VCM_DAC];
        double dSFRHiThroughValue[SFR_PLUS_MAX_ROI][Max_VCM_DAC];
        double dCTSFRHiSmoothValue[Max_VCM_DAC];
        double dWeightThroughValue[Max_VCM_DAC];
        BOOL bIsVCMMove;            // VCM�Ƿ�Move
        BOOL bHaveGlitch;           // ����Glitch���
        int nGlitchDac;             // Glitchλ��
        double dMaxGlitch;          // ���Glitchֵ
        int nThroughPeakDac;        // ��ֵλ��
        double dThroughHiSFRMax;    // ThroughFocus���SFR
        double dThroughHiSFRMin;    // ThroughFocus��СSFR
		int nStart_current;
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

        void SetVcmMove(int nVCM_CurrentDAC);
        BOOL DoStepSfr(
            __in ThroughFocus_Std::eThroughfocusPhase ePhase,
            __in int nCurrentDac,
            __out double &dKeySfr);

		BOOL CommitDAC(int _DAC);
		int Update_start_current(void);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        CSfrPlus m_SfrPlus;
        BOOL m_bEnableStack;
        HighPrecisionTimer m_ThroughFocusTimeCount;
        double m_ThroughFocusTime;
        //------------------------------------------------------------------------------
        // ����
        SFR_PLUS_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        SFR_PLUS_OPERATOR_RESULT m_result;
        //------------------------------------------------------------------------------

        void SaveThroughFocus(LPCTSTR lpOperatorName);
        BOOL DoImageSFRTest(int *pnErrorCode);
        double GetCurrentValue();
        double GetDacValue(int nDac);
        BOOL DoThroughFocus(BOOL *pbIsRunning);
    };

    extern ResolutionOperator *pThis;
    void CallbackLogOut(__in LPCTSTR lpLogText);
    void CallbackSetVcmMove(__in int nCurrentDac);
    BOOL CallbackDoStepSfr(
        __in ThroughFocus_Std::eThroughfocusPhase ePhase,
        __in int nCurrentDac,
        __out double &dKeySfr);

    extern "C"
    {
        RESOLUTION_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
