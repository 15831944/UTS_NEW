#pragma once
#include "Export.h"

namespace UTS
{
    class UTS_FRAMEWORK_API Keyboard
    {
        /*
    public:
        // ͬ���ȴ�SN
        void WaitSyncSN(HINSTANCE hInstance, BOOL *pbIsRunning);

        // �첽�ȴ�VirtualKey
        void WaitAsyncVirtualKeyBegin(HINSTANCE hInstance, BOOL *pbIsRunning, DWORD dwVirtualKey);
        void WaitAsyncVirtualKeyEnd(void);

    private:
        void WaitSync(HINSTANCE hInstance, BOOL *pbIsRunning, HOOKPROC hookproc);
        */

    public:
        Keyboard();
        ~Keyboard();

        void BeginListen();
        void EndListen();

        void OnKeyReturn();
        BOOL IsReturnPress();
        void WaitReturn(BOOL *pbIsRunning);

        void OnKeySpace();
        BOOL IsSpacePress();
        void WaitSpace(BOOL *pbIsRunning);

        void OnKeyChar(BYTE vkCode);
        void OnKeyBackspace();  // fix bug #6: SN�������ɾ�����߸���

    private:
        BOOL m_bListening;      // ���ڼ�������
        BOOL m_bReturnPress;    // �س�������
        BOOL m_bSpacePress;     // �ո������
        BOOL m_bWaitingReturn;  // ���ڵȴ��س���
    };
}
