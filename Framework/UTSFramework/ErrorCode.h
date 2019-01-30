#pragma once
#include "Export.h"
#include "DBLocalConfig.h"

namespace UTS
{
    class UTS_FRAMEWORK_API ErrorCode
    {
    public:
        BOOL GetAllErrorCodeInfoFromDB();
        CString GetErrorMsg(LPCTSTR lpOperatorFileName, int nErrorcode);

        //------------------------------------------------------------------------------
        // error code define
    public:
		static const int E_PassA            = (-100);        // Pass A, �ɹ��ּ�ΪA
		static const int E_PassB            = (-101);        // Pass B, �ɹ��ּ�ΪB
		static const int E_PassC            = (-102);        // Pass C, �ɹ��ּ�ΪC
		static const int E_Fail             = (900);        // Fail, ʧ�ܡ���������
		static const int E_Pass             = (0 );          // Pass, �ɹ�
		static const int E_DefectPixel      = (312 );          // Defect Pixel,���c
		static const int E_FocusAdjustment  = (208 );          // Focus Adjustment,�{������
		static const int E_FocusCheck       = (206 );          // Focus Check,�����Ȳ���
		static const int E_Blemish          = (301 );          // Blemish,���c 
		static const int E_WhitePixel       = (309 );          // White Pixel,���c
		static const int E_Current          = (104 );          // Current,?��?��
		static const int E_RI               = (318 );          // RI,���ǲ���
		static const int E_ColorCheck       = (8 );          // Color Check,ɫ��
		static const int E_NVMDataConsist   = (509);          // NVM Data Consist,�����Д�ֵ
		static const int E_NVMWrite         = (518);          // NVM Write, ??�w?��ʧ��
		static const int E_NVMCheck         = (515);          // NVM Check,??�w�z��ʧ��
		static const int E_OC               = (316);          // OC,��W����
		static const int E_RU               = (320);          // RU,���Ⱦ����
		static const int E_CU               = (303);          // CU,?ɫ�����
		static const int E_DarkNG           = (306);          // Dark NG,����
		static const int E_Tilt             = (16);          // Tilt ,�Aб
		static const int E_Glicth           = (17);          // Glicth, ����
		static const int E_VCM              = (18);          // VCM,��Ȧ�R�_����
		static const int E_Peak             = (19);          // Peak,��?����
		static const int E_AWB              = (412);          // AWB,��ƽ��
		static const int E_ALS              = (21);          // ALS ,���
		static const int E_Temperature      = (22);          // Temperature,�ض�
		static const int E_ThermalBlemish   = (23);          // Thermal Blemish,��@�c
		static const int E_NoImage          = (619);          // No Image,�D������������
		static const int E_ColorCal         = (25);          // Color Cal,ɫ��У?
		static const int E_Ripple           = (26);          // Ripple,ˮ�y
		static const int E_AbormalImage     = (27);          // Abormal Image,?ɫ
		static const int E_DataLine         = (28);          // Data Line,�����Gʧ
		static const int E_Gray             = (29);          // Gray,���A
		static const int E_DFOV             = (30);          // DFOV,?��
		static const int E_LED              = (31);          // LED,���y?����
		static const int E_MIC              = (32);          // MIC,?���L
		static const int E_Aligment         = (33);          // Alignment,��׼�y?
		static const int E_NoiseLine        = (34);          // Noise Line,?�l
		static const int E_SNScan           = (534);          // SN Scan,����?�o������
		static const int E_Band             = (535);          // Band,��?�l����
		static const int E_Linumance        = (616);          // Linumance,Yֵ����
		static const int E_OpenShort        = (38);          // Open/Short,�_��· 
		static const int E_SNR              = (39);          // SNR ,�������s?
		static const int E_FocusDelta       = (40);          // Focus Delta ,������������
		static const int E_Separation       = (41);          // Separation , ��?�xɢ
		static const int E_InitSFR          = (42);          // Init SFR, ���ӽ���������
		static const int E_DBConnect        = (501);          // DB Connect, ���ݿ�����ʧ��
		static const int E_ReBurn           = (44);          // ģ������¼, ���������DB����
		static const int E_InfoReady        = (45);          // ģ����¼ʱ����¼��Ϣ��ȫ
		static const int E_TvDistortion     = (46);          // TvDistortion, ���䲻��
		static const int E_Rotate           = (47);          // Rotate, ��ת����
		static const int E_RelativeShift    = (48);          // RelativeShift, ���λ�Ʋ���
		static const int E_ColorLevel       = (49);          // ColorLevel, ɫ���ֲ���
		static const int E_IR_LED           = (50);          // IR_LED, IR-LED ��Ʋ���
		static const int E_AE               = (325);          // AE, AE����
		static const int E_ColorShading     = (52);          // ColorShading, ColorShading����
		static const int E_FocusDiff        = (53);          // FocusDiff, ����Ȳ��
		static const int E_ColorLevelDiff   = (54);          // ColorLevelDiff, ɫζ���
		static const int E_NVM_LSC          = (314);
		static const int E_NVM_WB           = (409);
		static const int E_NVM_Begolden     = (57);
		static const int E_AE_TimeOut       = (58);
		static const int E_ERR_Rulcommlsc   = (314);
		static const int E_ERR_MTFDelta		= (67);
		static const int E_ERR_ThroughFocus	= (68);
		static const int E_DarkNoise		= (69);
		static const int E_FixPatternNoise	= (308);
		static const int E_CheckOCBin	    = (71);
		static const int E_GetSN            = (109); 
		static const int E_DarkLine         = (150);
		static const int E_DarkCorner       = (151);
		static const int E_LineDetect       = (152);
		static const int E_ColorRatioBG     = (410); 
		static const int E_ColorRatioRG     = (411); 
		static const int E_GetSensorID      = (522); 

		static const int E_XCal_Fail           = (200);        //  [8/14/2017 Cindy] XCalibration error code
		static const int E_XCal_Roll           = (201); 
		static const int E_XCal_Pitch          = (202); 
		static const int E_XCal_Yaw            = (203); 
		static const int E_XCal_Tilt           = (204); 
		static const int E_XCal_OCShift_X1     = (205); 
		static const int E_XCal_OCShift_Y1     = (206); 
		static const int E_XCal_OCShift_X2     = (207); 
		static const int E_XCal_OCShift_Y2     = (208); 
		static const int E_XCal_OCShift_TotalX = (209); 
		static const int E_XCal_OCShift_TotalY = (210); 
		static const int E_XCal_Tx             = (211); 

		static const int E_SFC_CheckRoute      = (531); 
		static const int E_SFC_CommitData      = (532); 

		static const int E_DIT_Shading            = (651);
		static const int E_DIT_ColorShading       = (652);
		static const int E_DIT_ColorRatio         = (653);
		static const int E_DIT_LU_Particle        = (654);
		static const int E_DIT_DeadPixel          = (655);
		static const int E_DIT_Blemish            = (656);
		static const int E_DIT_LightUniformity    = (657);
		static const int E_DIT_LensTilt           = (658);
		static const int E_DIT_HotPixel           = (659);
		static const int E_DIT_LU_LineDetect      = (660);
		static const int E_DIT_SFR_INF            = (661);
		static const int E_DIT_SFR_MUP            = (662);
		static const int E_DIT_SFR                = (663);
		static const int E_DIT_SFR_Circle         = (664);
		static const int E_DIT_Y_Check            = (665);
		static const int E_DIT_AF_Data_Check      = (666);
		static const int E_DIT_AFHorCaliCheck_INF = (667);
		static const int E_DIT_AFHorCaliCheck_MID = (668);
		static const int E_DIT_AFHorCaliCheck_MUP = (669);
		static const int E_DIT_PDAFCaliCheck      = (670);
		static const int E_DIT_OIS_H7cm_MID       = (671);
		static const int E_DIT_OIS_H14cm_MUP      = (672);
		static const int E_DIT_CheckDongle        = (673);
		static const int E_DIT_SetSN              = (674);

    public:
        vector<OPERATOR_ERRORCODE> m_vecAllSetting;
    };
}
