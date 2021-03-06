/*=======================================================================
		Accuracy Test Sample code for LC898124
                                             	by Rex.Tang
                                                2016.03.27
========================================================================*/
#ifndef __OISACCURACY_H__
#define __OISACCURACY_H__

#ifdef	__OISACCURACY__
	#define	__OISACCURACY_HEADER__
#else
	#define	__OISACCURACY_HEADER__		extern
#endif

// Checking radius
//#define		RADIUS 		75							// 75um

// Parameter define
//#define		DEGSTEP		3							// Degree of one step (3?)
//#define		ACCURACY	3.0F						// Accuracy (�}3.0um)
//#define		WAIT_MSEC	10							// Each step wait time(msec)


/* Raw data buffers */	
//Dual_Axis_t xy_raw_data[360/DEGSTEP + 1];
// __OISACCURACY_HEADER__	Dual_Axis_t	xy_raw_data[360/3 + 1];
// __OISACCURACY_HEADER__	float		xMaxAcc, yMaxAcc;
// __OISACCURACY_HEADER__	float		xLimit, yLimit;



//__OISACCURACY_HEADER__	unsigned short HallCheck(float ACCURACY, unsigned short RADIUS, unsigned short DEGSTEP, unsigned short WAIT_MSEC1, unsigned short WAIT_MSEC2, unsigned short WAIT_MSEC3);

#endif	//__OISACCURACY_H__
