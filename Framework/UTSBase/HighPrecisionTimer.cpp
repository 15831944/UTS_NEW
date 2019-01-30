#include "StdAfx.h"
#include "UTSBase.h"

namespace UTS
{
    #define RET_OK      0
    #define RET_ERROR   (-1)

    HighPrecisionTimer::HighPrecisionTimer(void)
    {
        m_llCollectStartTime = -1;
    }

    HighPrecisionTimer::~HighPrecisionTimer(void)
    {
    }

    /*************************************************************************
    ���������ơ�       SetStartTime
    ���������ܡ�       ��¼�ɼ���ʼʱ��
    ��������           ��
    ������ֵ��         0���ɹ� / -1��ʧ��
    *************************************************************************/
    int HighPrecisionTimer::SetStartTime(void)
    {
        LARGE_INTEGER litmp;
        if (FALSE == QueryPerformanceCounter(&litmp))
        {
            return RET_ERROR;
        }
        m_llCollectStartTime = litmp.QuadPart;
        return RET_OK;
    }

    /*************************************************************************
    ���������ơ�       GetPassTime
    ���������ܡ�       ��þ�����ʱ��ֵ(ms)
    ��������           ��
    ������ֵ��         double ������ʱ��ֵ(ms)
    *************************************************************************/
    double HighPrecisionTimer::GetPassTime()
    {
        if (m_llCollectStartTime < 0)
        {
            return 0;
        }

        LARGE_INTEGER litmp;
        LONGLONG qt2;
        double dft,dff,dfm;
        if (FALSE == QueryPerformanceFrequency(&litmp)) //���ʱ��Ƶ��
        {
            return RET_ERROR;
        }
        dff = (double)litmp.QuadPart;

        if (FALSE == QueryPerformanceCounter(&litmp))   //�����ֵֹ
        {
            return RET_ERROR;
        }
        qt2 = litmp.QuadPart;
        dfm = (double)(qt2 - m_llCollectStartTime);
        dft = (dfm * 1000.0) / dff;    //��þ�����ʱ��ֵ(ms)
        return dft;
    }

    void HighPrecisionTimer::EndCollectTime()
    {
        m_llCollectStartTime = -1;
    }
}
