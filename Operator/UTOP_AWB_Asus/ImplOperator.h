#pragma once
#include "UTSDefine.h"
#include "Algorithm_Asus.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm_ASUS;
using namespace UTS::Algorithm_ASUS::ColorShading;

#ifdef OPERATOR_EXPORTS
#define OPERATOR_API __declspec(dllexport)
#else
#define OPERATOR_API __declspec(dllimport)
#endif



namespace UTS
{
	typedef struct _awb_operator_param_
	{
		double dLTMinY;         // �װ������СYֵ
		double dLTMaxY;         // �װ�������Yֵ
		int nReCapture;         // 0��������  1�����и������С�ץͼƬ������Ķ���   
		MinMax<double> dAWBSpec_R;
		MinMax<double> dAWBSpec_B;
		RECT Rect_AWB;
	} AWB_OPERATOR_PARAM;

	typedef struct _awb_operator_result_
	{
		double dAWB_R;
		double dAWB_G;
		double dAWB_B;
	} AWB_RESULT;

	class ImplOperator : public BaseOperator
	{
	public:
		ImplOperator(void);
		~ImplOperator(void);

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
		AWB_OPERATOR_PARAM m_param;
		//------------------------------------------------------------------------------
		// ���
		AWB_RESULT m_result;
		double m_dYvalue;
		//------------------------------------------------------------------------------
	};

	extern "C"
	{
		OPERATOR_API BaseOperator* GetOperator(void);
	}
}
