#include "StdAfx.h"
#include "UTSBase.h"

namespace UTS
{
    //���캯��
    ComSeries::ComSeries(BOOL bAutoReceive)
    {
        //��ʼ���ڲ�����
        m_hReadThread = NULL;
        m_bAutoReceive = FALSE;
        m_hComm = INVALID_HANDLE_VALUE;
        m_OnSeriesRead = NULL;
        m_bOpened = 0;
    }

    //��������
    ComSeries::~ComSeries()
    {
        if (m_bOpened)
        {
            ClosePort();  //�رմ���
        }
    }

    //������뻺��
    void ComSeries::PurgeInputBuffer()
    {
        ASSERT(m_hComm !=INVALID_HANDLE_VALUE);
        PurgeComm(m_hComm, PURGE_RXCLEAR);
    }

    //����������
    void ComSeries::PurgeOutputBuffer()
    {
        ASSERT(m_hComm !=INVALID_HANDLE_VALUE);
        PurgeComm(m_hComm, PURGE_TXCLEAR);
    }

    /*
    *�������ܣ����ô��ڶ�ȡ��д�볬ʱ
    *��ڲ�����CommTimeOuts : ָ��COMMTIMEOUTS�ṹ
    *���ڲ�����(��)
    *����ֵ��TRUE:���óɹ�;FALSE:����ʧ��
    */
    BOOL ComSeries::SetSeriesTimeouts(COMMTIMEOUTS CommTimeOuts)
    {
        ASSERT(m_hComm != INVALID_HANDLE_VALUE);
        return SetCommTimeouts(m_hComm,&CommTimeOuts);
    }

    //�õ������Ƿ��
    BOOL ComSeries::GetComOpened()
    {
        return m_bOpened;
    }

    /*
    *�������ܣ��򿪴���
    *��ڲ�����pPortOwner    :ʹ�ô˴�����Ĵ�����
    portNo        :���ں�
    baud            :������
    parity        :��żУ��
    databits        :����λ
    stopbits        :ֹͣλ
    *���ڲ�����(��)
    *����ֵ��TRUE:�ɹ��򿪴���;FALSE:�򿪴���ʧ��
    */
    BOOL ComSeries::OpenPort(void * pOwner,
        int lenInput,   /*���뻺��*/
        int lenOutput,  /*�������*/
        int portNo,     /*���ں�*/
        int baud,       /*������*/
        int parity,     /*��żУ��*/
        int databits,   /*����λ*/
        int stopbits    /*ֹͣλ*/
        )
    {
        DCB commParam;
        TCHAR szPort[15];    

        ASSERT(pOwner!=NULL);
        m_pOwner = pOwner;

        // �Ѿ��򿪵Ļ���ֱ�ӷ���
        if (m_hComm != INVALID_HANDLE_VALUE)
        {
            return TRUE;
        }

        //���ô�����
        wsprintf(szPort, L"//./COM%d", portNo);

        //�򿪴���
        m_hComm = CreateFile(
            szPort,
            GENERIC_READ | GENERIC_WRITE,    //�������д
            0,                               //��ռ��ʽ������ģʽ��
            NULL,
            OPEN_EXISTING,                   //�򿪶����Ǵ�����������ʽ��
            0,
            NULL 
            );

        if (m_hComm == INVALID_HANDLE_VALUE)
        {
            // ��Ч���,���ء�        
            TRACE(_T("CreateFile ������Ч���\n"));
            return FALSE;

        }

        // �õ��򿪴��ڵĵ�ǰ���Բ������޸ĺ����������ô��ڡ�
        if (!GetCommState(m_hComm,&commParam))
        {        
            //�رմ���
            CloseHandle (m_hComm);
            m_hComm = INVALID_HANDLE_VALUE;
            return FALSE;
        }

        //���ô��ڲ���
        commParam.BaudRate = baud;                    // ���ò�����
        commParam.fBinary = TRUE;                    // ���ö�����ģʽ���˴���������TRUE
        commParam.fParity = TRUE;                    // ֧����żУ��
        commParam.ByteSize = databits;                // ����λ,��Χ:4-8 
        commParam.Parity = parity;                // У��ģʽ
        commParam.StopBits = stopbits;                // ֹͣλ

        commParam.fOutxCtsFlow = FALSE;                // No CTS output flow control 
        commParam.fOutxDsrFlow = FALSE;                // No DSR output flow control 
        commParam.fDtrControl = DTR_CONTROL_ENABLE; 
        // DTR flow control type 
        commParam.fDsrSensitivity = FALSE;            // DSR sensitivity 
        commParam.fTXContinueOnXoff = TRUE;            // XOFF continues Tx 
        commParam.fOutX = FALSE;                    // No XON/XOFF out flow control 
        commParam.fInX = FALSE;                        // No XON/XOFF in flow control 
        commParam.fErrorChar = FALSE;                // Disable error replacement 
        commParam.fNull = FALSE;                    // Disable null stripping 
        commParam.fRtsControl = RTS_CONTROL_ENABLE; 
        // RTS flow control 
        commParam.fAbortOnError = FALSE;            // �����ڷ������󣬲�����ֹ���ڶ�д

        //���ô��ڲ���
        if (!SetCommState(m_hComm, &commParam))
        {
            TRACE(_T("SetCommState error"));    
            //�رմ���
            CloseHandle (m_hComm);
            m_hComm = INVALID_HANDLE_VALUE;        
            return FALSE;
        }

        //���ô��ڶ�дʱ��
        COMMTIMEOUTS CommTimeOuts;
        GetCommTimeouts (m_hComm, &CommTimeOuts);
        CommTimeOuts.ReadIntervalTimeout = MAXDWORD; 
        CommTimeOuts.ReadTotalTimeoutMultiplier = 0; 
        CommTimeOuts.ReadTotalTimeoutConstant = 0;    
        CommTimeOuts.WriteTotalTimeoutMultiplier = 10; 
        CommTimeOuts.WriteTotalTimeoutConstant = 1000; 
        if(!SetCommTimeouts( m_hComm, &CommTimeOuts ))
        {
            TRACE( _T("SetCommTimeouts ���ش���") );
            CloseHandle (m_hComm);  //�رմ���
            m_hComm = INVALID_HANDLE_VALUE;
            return FALSE;
        }

        //ָ���˿ڼ����¼���
        SetCommMask (m_hComm, EV_RXCHAR);
        //���䴮���豸������
        SetupComm(m_hComm,lenInput,lenOutput);
        //��ʼ���������е���Ϣ
        PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);


        if(m_bAutoReceive)
        {	
            CString strEvent;
            strEvent.Format(L"Com_ReadCloseEvent%d",portNo);
            m_hReadCloseEvent = CreateEvent(NULL,TRUE,FALSE,strEvent);
            //�������ڶ����ݼ����߳�
            m_hReadThread = CreateThread(NULL,0,ReadThreadFunc,this,0,&m_dwReadThreadID);
        }

        TRACE(_T("���ڴ򿪳ɹ�"));
        m_bOpened = TRUE;
        return TRUE;
    }

    /*
    *�������ܣ��رմ���
    *��ڲ�����(��)
    *���ڲ�����(��)
    *����ֵ��(��)
    */
    void ComSeries::ClosePort()
    {    
        //��ʾ���ڻ�û�д�
        if (m_hComm == INVALID_HANDLE_VALUE)
        {
            return ;
        }

        if(m_bAutoReceive)
        {
            //�رն��߳�
            CloseReadThread();
        }

        //�رմ���
        CloseHandle(m_hComm);

        if(m_bAutoReceive)
        {
            //�ر��¼�
            CloseHandle(m_hReadCloseEvent);
        }

        m_hComm = INVALID_HANDLE_VALUE;
        m_bOpened = FALSE;
    }

    //���ڶ��̺߳���
    DWORD ComSeries::ReadThreadFunc(LPVOID lparam)
    {
        ComSeries *ceSeries = (ComSeries*)lparam;

        DWORD    evtMask;
        BYTE * readBuf = NULL;//��ȡ���ֽ�
        DWORD actualReadLen=0;//ʵ�ʶ�ȡ���ֽ���
        DWORD willReadLen;

        DWORD dwReadErrors;
        COMSTAT    cmState;

        // ��ջ��壬����鴮���Ƿ�򿪡�
        ASSERT(ceSeries->m_hComm !=INVALID_HANDLE_VALUE); 

        //��մ���
        PurgeComm(ceSeries->m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR );

        SetCommMask (ceSeries->m_hComm, EV_RXCHAR | EV_CTS | EV_DSR );
        while (TRUE)
        {       
            if (WaitCommEvent(ceSeries->m_hComm,&evtMask,0))
            {            
                SetCommMask (ceSeries->m_hComm, EV_RXCHAR | EV_CTS | EV_DSR );
                //��ʾ�����յ��ַ�        
                if (evtMask & EV_RXCHAR) 
                {
                    ClearCommError(ceSeries->m_hComm,&dwReadErrors,&cmState);
                    willReadLen = cmState.cbInQue ;
                    if (willReadLen <= 0)
                    {
                        continue;
                    }

                    //�����ڴ�
                    readBuf = new BYTE[willReadLen];
                    ZeroMemory(readBuf,willReadLen);
                    //��ȡ��������
                    ReadFile(ceSeries->m_hComm, readBuf, willReadLen, &actualReadLen,0);

                    //�����ȡ�����ݴ��ڣ�
                    if (actualReadLen>0)
                    {
                        //������ȡ�ص�����
                        if (ceSeries->m_OnSeriesRead)
                        {
                            ceSeries->m_OnSeriesRead((CWnd*)ceSeries->m_pOwner,readBuf,actualReadLen);
                        }
                    }

                    //�ͷ��ڴ�
                    delete[] readBuf;
                    readBuf = NULL;
                }
            }
            //����յ����߳��˳��źţ����˳��߳�
            if (WaitForSingleObject(ceSeries->m_hReadCloseEvent,500) == WAIT_OBJECT_0)
            {
                break;
            }
        }


        return 0;
    }

    //�رն��߳�
    void ComSeries::CloseReadThread()
    {
        SetEvent(m_hReadCloseEvent);
        //���������¼���Ч��Ч
        SetCommMask(m_hComm, 0);
        //������н�Ҫ��������
        PurgeComm( m_hComm, PURGE_RXCLEAR );
        if (m_bAutoReceive)
        {
            if (m_hReadThread != NULL)
            {
                //�ȴ��룬������߳�û���˳�����ǿ���˳�
                DWORD dwState = 0;
                for (int i = 0; i < 5; i++)
                {
                    Sleep(100);	
                    GetExitCodeThread(m_hReadThread, &dwState);
                    if (dwState == STILL_ACTIVE)
                    {
                        if (i == 4)
                        {
                            TerminateThread(m_hReadThread,0);
                        }
                    }
                    else
                    {
                        break;
                    }
                }

                CloseHandle(m_hReadThread);
                m_hReadThread = NULL;

                //if (WaitForSingleObject(m_hReadThread,4000) == WAIT_TIMEOUT)
                //{
                // TerminateThread(m_hReadThread,0);
                //   }
                //   m_hReadThread = NULL;
            }
        }
    }

    /*
    *�������ܣ��Ӵ��ڶ�ȡ����
    *��ڲ�����buf ������ȡ���ݻ�����
    bufLen : ����ȡ����������
    *���ڲ�����(��)
    *����ֵ��TRUE:���óɹ�;FALSE:����ʧ��
    */
    int ComSeries::ReadSyncPort(BYTE* buf, DWORD bufLen, int nRetry)
    {
        DWORD dwNumBytesRead;
        DWORD dwHaveNumRead =0 ; //�Ѿ��������

        ASSERT(m_hComm !=INVALID_HANDLE_VALUE);
        int nTried=0;

        while(TRUE)
        {
            //��ȡ��������
            if (ReadFile(m_hComm,               //���ھ��
                buf+dwHaveNumRead,              //��ȡ���ݻ�����
                bufLen-dwHaveNumRead,           //���ݻ�������С
                &dwNumBytesRead,                //(out)����ִ�гɹ���ʵ���ڴ��ڶ��ĸ���
                NULL))                          //�˴���������NULL
            {
                dwHaveNumRead = dwHaveNumRead + dwNumBytesRead;

                //������
                if(0 == dwHaveNumRead) return 0;
                //��ȡ���
                if(dwHaveNumRead == bufLen) return (int)bufLen;

                if(nTried == nRetry) return (int)dwHaveNumRead;

                //ʧ������
                nTried++;
                Sleep(10);
            }
            else return -1;
        }
    }

	int ComSeries::ReadSyncPort(char* buf, DWORD bufLen, int nRetry)
	{
		DWORD dwNumBytesRead;
		DWORD dwHaveNumRead =0 ; //�Ѿ��������

		ASSERT(m_hComm !=INVALID_HANDLE_VALUE);
		int nTried=0;

		while(TRUE)
		{
			//��ȡ��������
			if (ReadFile(m_hComm,               //���ھ��
				buf+dwHaveNumRead,              //��ȡ���ݻ�����
				bufLen-dwHaveNumRead,           //���ݻ�������С
				&dwNumBytesRead,                //(out)����ִ�гɹ���ʵ���ڴ��ڶ��ĸ���
				NULL))                          //�˴���������NULL
			{
				dwHaveNumRead = dwHaveNumRead + dwNumBytesRead;

				//������
				if(0 == dwHaveNumRead) return 0;
				//��ȡ���
				if(dwHaveNumRead == bufLen) return (int)bufLen;

				if(nTried == nRetry) return (int)dwHaveNumRead;

				//ʧ������
				nTried++;
				Sleep(10);
			}
			else return -1;
		}
	}

    /*
    *�������ܣ�������д������
    *��ڲ�����buf ����д�����ݻ�����
    bufLen : ��д�뻺��������
    *���ڲ�����(��)
    *����ֵ��TRUE:���óɹ�;FALSE:����ʧ��
    */
    BOOL ComSeries::WriteSyncPort(const BYTE*buf , DWORD bufLen)
    {
        DWORD dwNumBytesWritten;
        DWORD dwHaveNumWritten =0 ; //�Ѿ�д�����

        ASSERT(m_hComm != INVALID_HANDLE_VALUE);
        int nReTry=0;

        while(TRUE)
        {
            if (WriteFile (m_hComm,             //���ھ��
                buf+dwHaveNumWritten,           //д�����ݻ�����
                bufLen-dwHaveNumWritten,        //���ݻ�������С
                &dwNumBytesWritten,             //(out)����ִ�гɹ���ʵ���򴮿�д�ĸ���    
                NULL))                          //�˴���������NULL
            {
                dwHaveNumWritten = dwHaveNumWritten + dwNumBytesWritten;
                //д�����
                if(dwHaveNumWritten == bufLen) break;

                //ʧ������
                if(10==nReTry) return FALSE;
                else nReTry++;

                Sleep(10);
            }
            else return FALSE;
        }

        return TRUE;        
    }

	BOOL ComSeries::WriteSyncPort(const char *buf , DWORD bufLen)
	{
		DWORD dwNumBytesWritten;
		DWORD dwHaveNumWritten =0 ; //�Ѿ�д�����
		
		ASSERT(m_hComm != INVALID_HANDLE_VALUE);
		int nReTry=0;

		while(TRUE)
		{
			if (WriteFile (m_hComm,             //���ھ��
				buf+dwHaveNumWritten,           //д�����ݻ�����
				bufLen-dwHaveNumWritten,        //���ݻ�������С
				&dwNumBytesWritten,             //(out)����ִ�гɹ���ʵ���򴮿�д�ĸ���    
				NULL))                          //�˴���������NULL
			{
				dwHaveNumWritten = dwHaveNumWritten + dwNumBytesWritten;
				//д�����
				if(dwHaveNumWritten == bufLen) break;

				//ʧ������
				if(10==nReTry) return FALSE;
				else nReTry++;

				Sleep(10);
			}
			else return FALSE;
		}

		return TRUE;        
	}

}
