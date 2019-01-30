#pragma once
#include "capturevideo.h"


namespace UTS
{
    class CUSBFrameHandler :
        public CVdoFrameHandler
    {
    public:
        CUSBFrameHandler(void);
        ~CUSBFrameHandler(void);
        // �������������pBufferָ������ŵľ���BGR24�ĵĲɼ������lBufferSize����pBuffer����
        void VdoFrameData(double dblSampleTime, BYTE * pBuffer, long lBufferSize);

        CCaptureVideo m_cap_vdo; // ���������Ƶ�ɼ�����Ķ�����

    private:
        void SetWhiteScreen(BYTE *pBuffer, long lBufferSize);
        void SetBlackScreen(BYTE *pBuffer, long lBufferSize);
        void SetLightDefectScreen(BYTE *pBuffer, long lBufferSize);
        void SetDarkDefectScreen(BYTE *pBuffer, long lBufferSize);
    };
}
