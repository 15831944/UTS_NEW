#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm_Smartisan;
using namespace UTS::Algorithm_Smartisan::Shading_Smartisan;

#ifdef OPERATOR_EXPORTS
#define OPERATOR_API __declspec(dllexport)
#else
#define OPERATOR_API __declspec(dllimport)
#endif



namespace UTS
{
	typedef struct _ri_operator_param_
	{
		double dLTMinY;         // �װ������СYֵ
		double dLTMaxY;         // �װ�������Yֵ
		int nReCapture;         // 0��������  1�����и������С�ץͼƬ������Ķ���   
		//MinMax<double> dShadingSpec;
		double dShadingDeltaSpec;
		//double dShadingDeltaGoldenSpec;
		//double dShadingGolden;
	} Shading_OPERATOR_PARAM;

	class ImplOperator : public BaseOperator
	{
	public:
		ImplOperator(void);
		~ImplOperator(void);

		virtual BOOL OnReadSpec();
		virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
		virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
		virtual void OnGetRegisterList(vector<CString> &vecRegister);

	protected:
		virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

	private:
		//------------------------------------------------------------------------------
		// ����
		Shading_OPERATOR_PARAM m_param;
		//------------------------------------------------------------------------------
		// ���
		Shading_RESULT m_result;
		double m_dYvalue;
		void Shading_Y(WORD* pRaw10,int rawBayerType,double blackLvl,int nWidth,int nHeight,Shading_RESULT &result);
		void GetROIAvgYY(WORD* pRaw10,int rawBayerType,double blackLvl,int nWidth,int nHeight,const RECT& rect,	__out double &dYAvg);
		//------------------------------------------------------------------------------
	};

	extern "C"
	{
		OPERATOR_API BaseOperator* GetOperator(void);
	}
}
