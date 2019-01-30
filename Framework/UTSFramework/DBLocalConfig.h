#pragma once
#include "UTSDefine.h"
#include "Export.h"

namespace DDM { class Database; }

namespace UTS
{
    typedef struct _single_errorcode_info_
    {
        int nReturnValue;
        CString strErrorCode;
        int nReserveInt;
        CString strReserveStr;
    } SINGLE_ERRORCODE_INFO;

    typedef struct _operator_errorcode_
    {
        int nOperatorId;
        CString strOperatorFileName;
        vector<SINGLE_ERRORCODE_INFO> vecSingleErrorcodeInfo;
    } OPERATOR_ERRORCODE;

    typedef struct _single_item_
    {
        CString strKey;
        CString strValue;
        CString strComment;
    } SINGLE_ITEM;

    typedef struct _operator_spec_
    {
        int nOperatorId;
        CString strOperatorFileName;
        vector<SINGLE_ITEM> vecSingleSpec;
    } OPERATOR_SPEC;

    typedef struct _device_spec_
    {
        int nDeviceId;
        CString strDeviceFileName;
        vector<SINGLE_ITEM> vecSingleSetting;
    } DEVICE_SETTING;

    typedef struct _register_item_
    {
        CString strName;
        CString strData;
    } REGISTER_ITEM;

    class UTS_FRAMEWORK_API DBLocalConfig
    {
    public:
        DBLocalConfig(void);
        ~DBLocalConfig(void);
        // ��ʼ��
        BOOL Initialize();
        // �ж�Operator�Ƿ���ڣ�ͬʱȡ��Operator Id
        BOOL IsOperatorExist(LPCTSTR lpOperatorFilename, BOOL &bExist, int &nOperatorId);
        // ���һ��Operator������
        BOOL AddOperator(LPCTSTR lpOperatorFilename);
        // ����Init Operator��˳��
        BOOL SetOperatorIndexInit(const vector<CString> &vecInitOperator);
        // ����Test Operator��˳��
        BOOL SetOperatorIndexTest(const vector<CString> &vecTestOperator);
        // ����Final Operator��˳��
        BOOL SetOperatorIndexFinal(const vector<CString> &vecFinalOperator);
        // ȡ��Init Operator��˳��
        BOOL GetInitOperatorList(vector<CString> &vecInitOperator);
        // ȡ��Test Operator��˳��
        BOOL GetTestOperatorList(vector<CString> &vecTestOperator);
        // ȡ��Final Operator��˳��
        BOOL GetFinalOperatorList(vector<CString> &vecFinalOperator);
        // ȡ��Operator�ĵ������(����CString, double, int)
        BOOL GetOperatorSingleSpec(LPCTSTR lpOperatorFilename, LPCTSTR lpKey, CString &strValue, LPCTSTR lpDefault, LPCTSTR lpComment);
        BOOL GetOperatorSingleSpec(LPCTSTR lpOperatorFilename, LPCTSTR lpKey, double &dValue, double dDefault, LPCTSTR lpComment);
        BOOL GetOperatorSingleSpec(LPCTSTR lpOperatorFilename, LPCTSTR lpKey, int &nValue, int nDefault, LPCTSTR lpComment);
        // ȡ������Operator�Ĺ��
        BOOL GetAllOperatorSpec(vector<OPERATOR_SPEC> &vecAllSpec);
        // ��������Operator�Ĺ��
        BOOL SetAllOperatorSpec(const vector<OPERATOR_SPEC> &vecAllSpec);
        // ȡ�õ���Operator�Ĺ��
        BOOL GetOperatorSpec(int nOperatorId, OPERATOR_SPEC &stOperatorSpec);
        // ȡ��Project�ĵ����趨(����CString, double, int)
        BOOL GetProjectSingleSetting(LPCTSTR lpKey, CString &strValue, LPCTSTR lpDefault, LPCTSTR lpComment);
        BOOL GetProjectSingleSetting(LPCTSTR lpKey, double &dValue, double dDefault, LPCTSTR lpComment);
        BOOL GetProjectSingleSetting(LPCTSTR lpKey, int &nValue, int nDefault, LPCTSTR lpComment);
        // ȡ��Project�������趨
        BOOL GetProjectAllSetting(vector<SINGLE_ITEM> &vecAllSetting);
        // ����Project�������趨
        BOOL SetProjectAllSetting(const vector<SINGLE_ITEM> &vecAllSetting);
        // ȡ��ErrorCode�������趨
        BOOL GetErrorcodeAllSetting(vector<OPERATOR_ERRORCODE> &vecAllSetting);
        // ����ErrorCode�������趨
        BOOL SetErrorcodeAllSetting(const vector<OPERATOR_ERRORCODE> &vecAllSetting);
        // �ж�Device�Ƿ���ڣ�ͬʱȡ��Device Id
        BOOL IsDeviceExist(LPCTSTR lpDeviceFilename, BOOL &bExist, int &nDeviceId);
        // ׷��Device
        BOOL AddDevice(LPCTSTR lpDeviceFilename);
        // ȡ��Device�ĵ����趨(����CString, double, int)
        BOOL GetDeviceSingleSetting(LPCTSTR lpDeviceFilename, LPCTSTR lpKey, CString &strValue, LPCTSTR lpDefault, LPCTSTR lpComment);
        BOOL GetDeviceSingleSetting(LPCTSTR lpDeviceFilename, LPCTSTR lpKey, double &dValue, double dDefault, LPCTSTR lpComment);
        BOOL GetDeviceSingleSetting(LPCTSTR lpDeviceFilename, LPCTSTR lpKey, int &nValue, int nDefault, LPCTSTR lpComment);
        // ȡ��Device���ļ���
        BOOL GetDeviceFilename(int nDeviceId, CString &strDeviceFilename);
        // ȡ��ָ����Device�趨
        BOOL GetDeviceSetting(int nDeviceId, DEVICE_SETTING &m_deviceSetting);
        // ����ָ����Device�趨
        BOOL SetDeviceSetting(const DEVICE_SETTING &m_deviceSetting);
        // ɾ������V5UDeviceRegister
        BOOL DeleteV5UDeviceRegister();
		// ɾ��һ��V5UDeviceRegister
		BOOL DeleteV5UDeviceRegister(LPCTSTR lpRegisterName);
        // ׷��һ��V5UDeviceRegister
        BOOL AddV5UDeviceRegister(LPCTSTR lpRegisterName, LPCTSTR lpRegisterData);
        // ȡ������Register
        BOOL GetAllRegister(vector<REGISTER_ITEM> &vecRegister);
        // ȡ���û�����
        BOOL GetUserPassword(int nUserType, CStringA &strPassword);
        // �����û�����
        BOOL SetUserPassword(int nUserType, LPCSTR lpPassword);
    private:
        DDM::Database *db;
    };
}
