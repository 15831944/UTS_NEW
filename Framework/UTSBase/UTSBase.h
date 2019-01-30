#pragma once

#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4005)
#include <intsafe.h>
#include <stdint.h>
#pragma warning (pop)
#endif

//------------------------------------------------------------------------------
// �ڴ�й¶���
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//------------------------------------------------------------------------------

#include <regex>
#include <afxcontrolbars.h>
#include <atlimage.h>
#include <atlconv.h>
#include <assert.h>
#include <afxmt.h>
#include <vector>
#include <stdint.h>
using namespace std;

#pragma comment(lib, "Version.lib")

//------------------------------------------------------------------------------
// disable warning
#pragma warning (disable:4482)  // warning C4482: ʹ���˷Ǳ�׼��չ: �޶�����ʹ����ö��
#pragma warning (disable:4996)  // warning C4996: '_wfopen': This function or variable may be unsafe.

namespace UTS
{

#define PI          (3.1415926535897932384626)
#define EMPTY_STR   _T("")

#ifdef UNICODE
#define UTS_FN  __FUNCTIONW__
#else
#define UTS_FN  __FUNCTION__
#endif
    //------------------------------------------------------------------------------
    // Color
#define COLOR_WHITE             RGB(255, 255, 255)  // ��
#define COLOR_BLACK             RGB(0  , 0  , 0  )  // ��
#define COLOR_RED               RGB(255, 0  , 0  )  // ��
#define COLOR_LIME              RGB(0  , 255, 0  )  // ����
#define COLOR_BLUE              RGB(0  , 0  , 255)  // ��
#define COLOR_YELLOW            RGB(255, 255, 0  )  // ��
#define COLOR_ORANGE            RGB(255, 165, 0  )  // ��
#define COLOR_GOLD              RGB(255, 215, 0  )  // �� 
#define COLOR_SILVER            RGB(192, 192, 192)  // ����
#define COLOR_DARKGRAY          RGB(169, 169, 169)  // ���
#define COLOR_LIGHTGREY         RGB(211, 211, 211)  // ǳ��
#define COLOR_MEDIUMSEAGREEN    RGB(60 , 179, 113)  // ���еĺ�����
#define COLOR_SEAGREEN          RGB(46 , 139, 87 )  // ������
#define COLOR_GREEN             COLOR_MEDIUMSEAGREEN


    //------------------------------------------------------------------------------
    // Macro Function
#define OFFSET_VALUE(src, k, b)         ((double)((double)(src) * (double)(k) + (double)(b)))
#define ROUND(a)                        (((a) >= (0.0f)) ? (int((a)+0.5f)):(int((a)-0.5f)))
#define DOUBLE2LONG(a)                  (((a) >= (0.0f)) ? (long((a)+0.5f)):(long((a)-0.5f)))
#define DOUBLE2INT(a)                   ROUND(a)
#define RELEASE_ARRAY(a)                (((a)!=0) ? (delete[] (a),(a) = 0):((a)=0))
#define RELEASE_POINTER(a)              (((a)!=0) ? (delete (a),(a) = 0):((a)=0))
#define SWAP(type, a, b)                {type temp;temp=(a);(a)=(b);(b)=temp;}
#define FLOAT_ZERO_THRESHOLD            (0.000001)
#define GET_VALUE_IN_RANGE(a, min, max) (((a) >= (max))?(max):(((a) <= (min))?(min):(a)))
#define Angle2Radian(angle)             ((angle) * PI / 180.0)
#define Radian2Angle(radian)            ((radian) * 180.0 / PI)
#define YVALUE(b, g, r)                 (0.299 * (r) + 0.587 * (g) + 0.114 * (b))
#define PIXEL_R(x, y, w, h)             ((((h)-(y)-1)*(w)+(x)) * 3 + 2)
#define PIXEL_G(x, y, w, h)             ((((h)-(y)-1)*(w)+(x)) * 3 + 1)
#define PIXEL_B(x, y, w, h)             ((((h)-(y)-1)*(w)+(x)) * 3 + 0)
#define MAKESURE_NOT_ZERO(a)            ((abs(a) < FLOAT_ZERO_THRESHOLD) ? FLOAT_ZERO_THRESHOLD : (a))

#ifndef GET_BITS
#define GET_BITS(field,offset,mask)     (((field) >> (offset)) & (mask))
#endif

#ifndef GET_BIT
#define GET_BIT(field,offset)           (GET_BITS(field,offset,0x1))
#endif

#ifndef IS_IN_RANGE
#define IS_IN_RANGE(a, mina, maxa)      ((mina) <= (a) && (a) <= (maxa))
#endif

#ifndef UTSMAX
#define UTSMAX(a,b)                     (((a) > (b)) ? (a) : (b))
#endif

#ifndef UTSMIN
#define UTSMIN(a,b)                     (((a) < (b)) ? (a) : (b))
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array)               (sizeof(array) / sizeof(*array))
#endif

    //------------------------------------------------------------------------------
    // Common Functions
    // "aaa, bbb, ccc" => Vector("aaa", "bbb", "ccc")
    void SplitString(LPCTSTR lpString, vector<CString> &vecString, LPCTSTR lpSplitMark = _T(","), BOOL bTrimResult = TRUE);
    // "1, 2, 3" => Vector(1, 2, 3)
    void SplitInt(LPCTSTR lpString, vector<int> &vecInt);
    // "0.1, 0.2, 0.3" => Vector(0.1, 0.2, 0.3)
    void SplitDouble(LPCTSTR lpString, vector<double> &vecDouble);
    // "=" * 4 => "===="
    CString GetTimesString(LPCTSTR lpString, unsigned int unTimes = 1);
    //------------------------------------------------------------------------------

    // Class
    template <typename T>
    class MinMax
    {
    public:
        T min;
        T max;
        inline bool IsCover(T x) { return IS_IN_RANGE(x, min, max); }
    };

    //------------------------------------------------------------------------------
    // ����ϵͳ����
    class OSUtil
    {
    public:
        static CString GetParentDir(LPCTSTR lpCurrentDir);
        static CString GetNoBSPath(LPCTSTR lpInputDir);
        static CString GetBSPath(LPCTSTR lpInputDir);
        static CString GetFileName(LPCTSTR lpPathFileName);
        static CString GetMainFileName(LPCTSTR lpFileName);
        static CString GetExtFileName(LPCTSTR lpFileName);
        static BOOL IsFileExist(LPCTSTR lpFileName);
        static BOOL IsDirExist(LPCTSTR lpDirName);
        static void CreateMultipleDirectory(LPCTSTR lpPath);
        static BOOL DirReplace(LPCTSTR lpInputDir, LPCTSTR lpSrcStr, LPCTSTR lpDestStr);
        static void GetFiles(LPCTSTR lpDir, CStringList &list);
        static void GetDirectorys(LPCTSTR lpDir, CStringList &list);
        static void MessageBoxLastError();
        static void ExcuteCommand(LPCTSTR lpCommand, BOOL bWaitSyncEnd = TRUE);
        static void ZipFile(LPCTSTR lpDestFileName, LPCTSTR lpSourceFileName);
        static BOOL GetFileVersion(LPCTSTR strFilePath, CString &strVersion);
        static BOOL GetFileTimeStr(LPCTSTR lpFilePathName, CString &strCreateTime, CString &strAccessTime, CString &strWriteTime);
        static void OpenFolderWindow(LPCTSTR lpDir);
        static BOOL IsDllExportFunction(LPCTSTR lpDllFile, LPCSTR lpFunctionName);
        static void ErrorExit(LPTSTR lpszFunction);
        static BOOL FindProcess(LPCTSTR lpProcessName);
        static long GetFileSize(LPCTSTR lpFileName);
    private:
        OSUtil(void);
        ~OSUtil(void);
    };

    //------------------------------------------------------------------------------
    // �߾��ȼ�ʱ��
    class HighPrecisionTimer
    {
    public:
        HighPrecisionTimer(void);
        ~HighPrecisionTimer(void);

        // ��¼�ɼ���ʼʱ��
        int SetStartTime(void);
        // ��þ�����ʱ��ֵ(ms)
        double GetPassTime();
        // ��ֹ�ɼ�ʱ��
        void EndCollectTime();

    private:
        LONGLONG m_llCollectStartTime;
    };

    //------------------------------------------------------------------------------
    // �ļ���־
    typedef enum _e_log_level_
    {
        LogLevel_Error = 0,
        LogLevel_Warning,
        LogLevel_Info,
        LogLevel_Debug
    } eLogLevel;

    class FileLog
    {
    public:
        FileLog();
        ~FileLog();

        BOOL Init(LPCTSTR lpFileName, int nLevel = LogLevel_Debug);
        void DebugLog(LPCTSTR lpFormat, ...);
        void InfoLog(LPCTSTR lpFormat, ...);
        void WarningLog(LPCTSTR lpFormat, ...);
        void ErrorLog(LPCTSTR lpFormat, ...);

    private:
        int m_nLevel;
        CString m_strLogFileName;
        CFile m_file;
        void FileLog::OutputLog(eLogLevel type, LPCTSTR lpText);
    };

    //------------------------------------------------------------------------------
    // �����
    class Random
    {
    public:
        Random();
        ~Random();

        double GetRandomDouble();               // ����0-1֮��������
        int GetRandomInt(int nMax = RAND_MAX);  // ����0-nMax֮��������
    };

    //------------------------------------------------------------------------------
    // ����FPS
    class FPSCounter
    {
    public:
        FPSCounter();
        ~FPSCounter();
        double GetFPS(void);

    private:
        double dFPS;
        BOOL fps_first;
        LARGE_INTEGER start_time;
        LARGE_INTEGER end_time;
        LARGE_INTEGER freq;
        __int16	display_count;
    };

    //------------------------------------------------------------------------------
    // CColorListBox window
    typedef struct _LISTBOX_COLOR_
    {
        CString strText;
        COLORREF fgColor;
        COLORREF bgColor;
        _LISTBOX_COLOR_()
        {
            strText.Empty();
            fgColor = COLOR_BLACK;
            bgColor = COLOR_WHITE;
        }
    } LISTBOX_COLOR, *PLISTBOX_COLOR;

    class CColorListBox : public CListBox
    {
        // Construction
    public:
        CColorListBox();

        // Attributes
    public:
        void AppendString(LPCTSTR lpszText, COLORREF fgColor, COLORREF bgColor);
        // Operations
    public:

        // Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CColorListBox)
    public:
        virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
        virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
        virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
        //}}AFX_VIRTUAL

        // Implementation
    public:
        virtual ~CColorListBox();

        // Generated message map functions
    protected:
        //{{AFX_MSG(CColorListBox)
        afx_msg void OnDestroy();
        //}}AFX_MSG

        DECLARE_MESSAGE_MAP()
    };

    //------------------------------------------------------------------------------
    class Resolution
    {
    public:
        void SetOldResolution(int nWidth, int nHeight);
        void SetNewResolution(int nWidth, int nHeight);
        int GetNewX(int nOldX);
        int GetNewY(int nOldY);
        int GetOldX(int nNewX);
        int GetOldY(int nNewY);
        int GetNewXByOldRatio(int nNewY);
        int GetNewYByOldRatio(int nNewX);
        int GetOldXByNewRatio(int nOldY);
        int GetOldYByNewRatio(int nOldX);

    private:
        int nOldX;
        int nOldY;
        int nNewX;
        int nNewY;
        double dScaleX_Old_New; // oldx / newx
        double dScaleY_Old_New; // oldy / newy
        double dOldRatioX_Y;    // oldx / oldy
        double dNewRatioX_Y;    // newx / newy
    };

    //-------------------------------------------------------------------------
    // ���ڲ�����װ
    typedef struct _ComSeriesParam_
    {
        int nlenInput;  /*���뻺��*/
        int nlenOutput; /*�������*/
        int nportNo;    /*���ں�*/
        int nbaud;      /*������*/
        int nparity;    /*��żУ��*/
        int ndatabits;  /*����λ*/
        int nstopbits;  /*ֹͣλ*/
    } COM_SERIES_PARAM;
    // ���崮�ڽ������ݺ�������
    typedef void (CALLBACK* ONSERIESREAD)(CWnd*,BYTE* buf,int bufLen);
    // ����ͨѶ��
    class ComSeries
    {
    public:
        ComSeries(BOOL bAutoReceive=TRUE);
        ~ComSeries(void);
    public:
        //������뻺��
        void PurgeInputBuffer();
        //����������
        void PurgeOutputBuffer();
        //���ô��ڶ�ȡ��д�볬ʱ
        BOOL SetSeriesTimeouts(COMMTIMEOUTS CommTimeOuts);
        //�򿪴���
        BOOL OpenPort(void* pOwner,     /*ָ��ָ��*/
            int lenInput,              /*���뻺��*/
            int lenOutput,             /*�������*/
            int portNo = 1,            /*���ں�*/
            int baud = 9600,           /*������*/
            int parity = NOPARITY,     /*��żУ��*/
            int databits = 8,          /*����λ*/
            int stopbits = ONESTOPBIT  /*ֹͣλ*/
            );
        //�رմ���
        void ClosePort();
        //ͬ����ȡ����
        int ReadSyncPort(BYTE* buf, DWORD bufLen, int nRetry=10);

		int ReadSyncPort(char* buf, DWORD bufLen, int nRetry=10);

        //ͬ��д������
        BOOL WriteSyncPort(const BYTE *buf, DWORD bufLen);

		BOOL WriteSyncPort(const char *buf , DWORD bufLen);

        //�õ������Ƿ��
        BOOL GetComOpened();
    private:
        //���ڶ��̺߳���
        static DWORD WINAPI ReadThreadFunc(LPVOID lparam);
    private:
        //�رն��߳�
        void CloseReadThread();
    private:
        //�����Ƿ��Զ���������
        BOOL m_bAutoReceive;
        //�Ѵ򿪵Ĵ��ھ��
        HANDLE m_hComm;
        //���߳̾��
        HANDLE m_hReadThread;
        //���߳�ID��ʶ
        DWORD m_dwReadThreadID;
        //���߳��˳��¼�
        HANDLE m_hReadCloseEvent;
        //�����Ƿ��Ѵ�
        BOOL m_bOpened; 
        //ָ��������ָ��
        void *m_pOwner; 
    public:
        ONSERIESREAD m_OnSeriesRead; //���ڶ�ȡ�ص�����
    };
}


