#include "StdAfx.h"
#include "DspRealtek.h"



DspRealtek_5838::DspRealtek_5838(void)
{
	if(m_RvcLib.LoadRvcLib())
	{
		m_RvcLib.LoadRvcFun();
		if(m_RvcLib.m_pfnRvcLib_Initialize)
		{
			m_RvcLib.m_pfnRvcLib_Initialize(0, 1);
		}
	}
}


DspRealtek_5838::~DspRealtek_5838(void)
{
	m_RvcLib.m_pfnRvcLib_UnInitialize(1);
	m_RvcLib.FreeRvcLib();
}

HRESULT DspRealtek_5838::DspGetSensorRegister(USHORT *Value, IN int Address,BYTE flag)
{
	HRESULT hr  = S_FALSE;
	BOOL bResult = FALSE;
	BYTE byReadData = (BYTE)Value;

	bResult = m_RvcLib.m_pfnReadSensorRegister8(Address, 1, &byReadData);
	if(bResult) hr  = S_OK;

	return hr;
}

HRESULT DspRealtek_5838::DspSetSensorRegister(USHORT Value, IN int Address,BYTE flag)
{
	HRESULT hr  = S_FALSE;
	BOOL bResult = FALSE;
	BYTE byWriteData = (BYTE)Value;

	bResult = m_RvcLib.m_pfnWriteSensorRegister8(Address, 1, &byWriteData);
	if(bResult) hr  = S_OK;

	return hr;
}

HRESULT DspRealtek_5838::DspReadEEPROM(BYTE *Data, IN int StartAddress, IN int ReadLen)
{
	HRESULT hr  = S_OK;

	return hr;
}

HRESULT DspRealtek_5838::DspWriteEEPROM(BYTE *Data, IN int StartAddress, IN int WriteLen)
{
	HRESULT hr  = S_OK;

	return hr;
}

HRESULT DspRealtek_5838::DspSetLEDValue(int Value)
{
	HRESULT hr = S_OK;

	switch(Value)
	{
	case 1:
		m_RvcLib.m_pfnSetLEDMode(TRUE);
		break;
	case 2:
		m_RvcLib.m_pfnSetLEDMode(FALSE);
		break;
	default:
		hr = -1;
		break;
	}
	return hr;
}

HRESULT DspRealtek_5838::DspLoadFW_EEProm(LPBYTE lpData,int eepromsize)
{
	HRESULT hr = S_OK;
	ProgressInfo progressinfo;
	int iResult = -1;
	EEPROM_ID eepromID = SPI_SF_MX25L512;

	iResult = m_RvcLib.m_pfnEEPROMWrite(eepromID, eepromsize, lpData, DownloadProgressCB, &progressinfo);
//	iResult = m_RvcLib.m_pfnEEPROMWrite(eepromID, eepromsize, lpData, DownloadProgressCB, &progressinfo);
	if(0 == iResult)
	{
		uts.log.Debug(_T("Write Eeprom Success"));
	}else
	{
		uts.log.Error(_T("EEPROM Write Error!"));
		hr = S_FALSE;
	}
	return hr;
}

HRESULT DspRealtek_5838::DspDumpFW_EEProm(LPBYTE lpDumpData,int Dumpsize)
{
	HRESULT hr = S_OK;
	ProgressInfo progressinfo;
	int iResult = -1;
	EEPROM_ID eepromID = SPI_SF_MX25L512;

	iResult = m_RvcLib.m_pfnEEPROMRead(eepromID, 0x00, Dumpsize, lpDumpData, DownloadProgressCB, &progressinfo);


	if(0 == iResult)
	{
		uts.log.Debug(_T("Read Eeprom Success"));
	}else
	{
		uts.log.Error(_T("EEPROM Read Error!"));
		hr = S_FALSE;
	}

	return hr;
}


HRESULT DspRealtek_5838::DspWriteSN_EEProm(LPBYTE lpData,CString strSN,int eepromsize)
{
	HRESULT hr = S_OK;

	ProgressInfo progressinfo;
	int iResult = -1;
	EEPROM_ID eepromID = SPI_SF_MX25L512;

	iResult = m_RvcLib.m_pfnEEPROMWriteSN(eepromID,eepromsize, lpData, strSN, DownloadProgressCB, &progressinfo);

	if(0 == iResult)
	{
		uts.log.Debug(_T("Read Eeprom Success"));
	}else
	{
		uts.log.Error(_T("EEPROM Read Error!"));
		hr = S_FALSE;
	}

	return hr;
}



HRESULT DspRealtek_5838::DspReadSN(CString &strCurSN)
{
	HRESULT hr = S_OK;
	int bResult = -1;

	bResult = m_RvcLib.m_pfnUVCGetManufacturer(strCurSN);

	LPTSTR lpstr = strCurSN.GetBuffer();

	int iRet = 0;
	char* str = NULL;

#ifdef _UNICODE
	iRet = WideCharToMultiByte(CP_ACP, NULL, (LPCWSTR)lpstr, wcslen(lpstr), 0, NULL, NULL, NULL);
	str = new char[iRet+1];
	str[iRet] = 0;
	iRet = WideCharToMultiByte(CP_ACP, NULL, (LPCWSTR)lpstr, wcslen(lpstr), str, iRet, NULL, NULL);
	uts.log.Error(_T("Device Current SN is %s"), str);
	delete str;
#else
	uts.log.Error(_T("Device Current SN is %s"), strCurSN);
#endif

	return hr;
}