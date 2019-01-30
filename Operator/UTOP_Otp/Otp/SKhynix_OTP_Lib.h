// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// SKHYNIX_OTP_LIB_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#ifndef _SKHYNIX_OPT_LIB_
#define _SKHYNIX_OPT_LIB_

#ifdef SKHYNIX_OTP_LIB_EXPORTS
#define SKHYNIX_OTP_LIB_API __declspec(dllexport)
#else
#define SKHYNIX_OTP_LIB_API __declspec(dllimport)
#endif

typedef struct LSC_RATIO{
	int		R;
	int		Gr;
	int		Gb;
	int		B;
}LSC_RATIO, *PLSC_RATIO;

typedef struct WB{
	int		Roi_Width;
	int		Roi_Height;
	int		StrX;
	int		StrY;
	int		EndX;
	int		EndY;
	float	WB_Ratio_RGr;
	float	WB_Ratio_BGb;
	float	WB_Ratio_GbGr;
}WB, *PWB;

typedef struct _IMG_INFO{
	int		Width;
	int		Height;
	LPWORD	bRawBuf;
	LSC_RATIO Ratio;//LSC Ration Control
	WB		 WB;	//WB Inform
}IMG_INFO, *PIMG_INFO;

INT32 SKhynix_OTP_Calibration(PIMG_INFO pImg, LPWORD LscPara);

 

#endif