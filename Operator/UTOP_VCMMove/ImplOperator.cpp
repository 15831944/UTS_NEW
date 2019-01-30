#include "StdAfx.h"
#include "ImplOperator.h"
#include "UTOP_VCMMove.h"
#include "VCM.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib, "UTS_VCM.lib")

namespace UTS
{
	ImplOperator::ImplOperator(void)
	{
		OPERATOR_INIT;
	}

	ImplOperator::~ImplOperator(void)
	{
	}

	BOOL ImplOperator::OnReadSpec()
	{
		CString strSection = OSUtil::GetFileName(m_strModuleFile);
		uts.dbCof.GetOperatorSingleSpec(strSection, _T("nReCapture"), m_param.nReCapture, 1, _T("0: Do nothing / 1: Set register, capture image, save image"));
		uts.dbCof.GetOperatorSingleSpec(strSection, _T("nVCMDAC"), m_param.nVCMDAC, 512, _T("VCM Move DAC"));

		OnPreviewStart();

		return TRUE;
	}

	BOOL ImplOperator::OnTest(BOOL *pbIsRunning, int *pnErrorCode)
	{
		//------------------------------------------------------------------------------
		// ��ʼ��
		m_TimeCounter.SetStartTime();
		m_pDevice->GetBufferInfo(m_bufferInfo);

		//------------------------------------------------------------------------------
		// ��ʼ�����
		*pnErrorCode = uts.errorcode.E_Pass;
		//------------------------------------------------------------------------------
		// ץͼ
		if (m_param.nReCapture != 0)
		{
			// �����趨Sensor����
			CString strRegName = m_strOperatorName;
			if (!m_pDevice->WriteValue(eDeviceWriteValueType::DWVT_WRITE_SENSOR_REGISTER,
				strRegName.GetBuffer(), strRegName.GetLength() * sizeof(TCHAR)))
			{
				uts.log.Error(_T("Device WriteValue DWVT_REGISTER_SET [%s] Error."), strRegName);
				*pnErrorCode = uts.errorcode.E_Fail;
				goto end;
			}

			// ץͼ
			if (!m_pDevice->Recapture(
				m_bufferObj,
				uts.info.nLTDD_DummyFrame,
				uts.info.nLTDD_AvgFrame))
			{
				uts.log.Error(_T("Recapture error. "));
				*pnErrorCode = uts.errorcode.E_NoImage;
				goto end;
			}
		}
		else
		{
			// ʹ���ϴε�ץͼ
			m_pDevice->GetCapturedBuffer(m_bufferObj);
		}

		// ��ͼ
		m_pDevice->DisplayImage(m_bufferObj.pBmpBuffer);

		//------------------------------------------------------------------------------
		// ����
		//DLLSetVCM_Initial(m_pDevice, uts.info.nVCMType,NULL);
		DLLSetVCM_Move(m_pDevice, uts.info.nVCMType, m_param.nVCMDAC);
		uts.log.Debug(_T("Move2Dac[%d]"), m_param.nVCMDAC);
		//------------------------------------------------------------------------------
		// �жϹ��


	

end:
		// ����Errorcode���ý��
		m_bResult = (*pnErrorCode == uts.errorcode.E_Pass);

		//------------------------------------------------------------------------------
		

		//------------------------------------------------------------------------------
		// ���������ļ�
		SaveData();

		return m_bResult;
	}

	void ImplOperator::OnPreviewStart()
	{
		uts.log.Debug(_T("SetVCMMOVE PreviewStart"));
	
		//DLLSetVCM_Initial(m_pDevice, uts.info.nVCMType,NULL);
	}


	void ImplOperator::OnGetErrorReturnValueList(vector<int> &vecReturnValue)
	{
		vecReturnValue.clear();
		vecReturnValue.push_back(uts.errorcode.E_Fail);
		vecReturnValue.push_back(uts.errorcode.E_NoImage);
	}

	void ImplOperator::OnGetRegisterList(vector<CString> &vecRegister)
	{
		vecRegister.clear();
	}

	void ImplOperator::GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter)
	{

	}

	//------------------------------------------------------------------------------
	BaseOperator* GetOperator(void)
	{
		return (new ImplOperator);
	}
	//------------------------------------------------------------------------------
}
