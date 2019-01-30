#include "StdAfx.h"
#include "Algorithm.h"
#include <stdlib.h>

namespace UTS
{
    namespace Algorithm
    {
        namespace Math
        {
            // ����ƽ�������ľ���
            double GetDistance2D(
                double x1, double y1,
                double x2, double y2)
            {
                return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
            }

            // ����ռ������ľ���
            double GetDistance3D(
                double x1, double y1, double z1,
                double x2, double y2, double z2)
            {
                return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) );
            }

            // ������εĵ��ĸ���(��ʱ�봫���ĸ��������)
            void GetLastPointOfRectangle(
                const POINT &ptA,
                const POINT &ptB,
                const POINT &ptC,
                POINT &ptD)
            {
                ptD.x = ptA.x + ptC.x - ptB.x;
                ptD.y = ptA.y + ptC.y - ptB.y;
            }

            // ���㷽��
            double Variance(double f[], int size)
            {
                assert(NULL != f);
                assert(size > 0);

                int i = 0;
                double average = 0;
                double s = 0;
                for (i = 0; i < size; i++)
                {
                    average += f[i]; 
                }

                average /= size;

                for (i = 0; i < size; i++)
                {
                    s += (f[i] - average) * (f[i] - average);
                }

                s = s / size;

                return s;
            }

            // �����׼��
            double StandardDeviation(double f[], int size)
            {
                return sqrt(Variance(f, size));
            }

            // ����4�Ե���ɵ�ֱ�ߣ��󽻵�
            void GetCrossPoint(
                int x0, int y0,   // ��1��ֱ���ϵĵ�1����
                int x1, int y1,   // ��1��ֱ���ϵĵ�2����
                int x2, int y2,   // ��2��ֱ���ϵĵ�1����
                int x3, int y3,   // ��2��ֱ���ϵĵ�2����
                LONG &x, LONG &y)
            {
                if (x0 == x1) x0++; // ��ֹ����
                if (x2 == x3) x2++; // ��ֹ����
                double k1 = (double)(y0 - y1) / (double)(x0 - x1);
                double k2 = (double)(y2 - y3) / (double)(x2 - x3);
                double b1 = y0 - k1 * x0;
                double b2 = y2 - k2 * x2;
                if (k1 == k2) k1++; // ��ֹ����
                x = DOUBLE2INT((b2 - b1) / (k1 - k2));
                y = DOUBLE2INT(b1 - k1 * (b1 - b2) / (k1 - k2));
            }

            // ��������ȡ��rect
            void GetRectByCenter(const POINT& ptCenter, const SIZE& sizeROI, RECT &rcReturn)
            {
                rcReturn.left   = ptCenter.x - sizeROI.cx / 2;
                rcReturn.right  = ptCenter.x + sizeROI.cx / 2;
                rcReturn.top    = ptCenter.y - sizeROI.cy / 2;
                rcReturn.bottom = ptCenter.y + sizeROI.cy / 2;
            }

            // ����������ʼ��
            void FindStartXValue(
                int nSameDataCount,
                int nTotalDataCount,
                int *pXValue,
                double* pYValue,
                int &nStartXValue)
            {
                assert(nSameDataCount > 0);
                assert(nTotalDataCount >= nSameDataCount);
                assert(nullptr != pXValue);
                assert(nullptr != pYValue);

                // 1 : ����
                // -1: �½�
                int nDirection = -1;
                int nStartIndex = 0;
                for (int i = 1; i < nTotalDataCount; i++)
                {
                    if (pYValue[i] >= pYValue[i - 1])
                    {
                        if (nDirection > 0) // ��������
                        {
                            if (i - nStartIndex >= nSameDataCount)
                            {
                                break;
                            }
                        }
                        else // �½�������
                        {
                            nStartIndex = i - 1;
                            nDirection = 1;
                        }
                    }
                    else
                    {
                        if (nDirection < 0) // �����½�
                        {
                            if (i - nStartIndex >= nSameDataCount)
                            {
                                break;
                            }
                        }
                        else // �������½�
                        {
                            nStartIndex = i - 1;
                            nDirection = -1;
                        }
                    }
                }
                nStartXValue = pXValue[nStartIndex];
            }

			short Change2Complement(short value)
			{
				return (~value + 1);
			//	short temp = 0;

				//temp = ~value + 1;
			//	temp = short(pow( 2.0, 16.0 ) - value);

			//	return temp;
			}

        }   // namespace Math
    }   // namespace Algorithm
}   // namespace UTS

