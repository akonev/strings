#include "ph_string.h"


void ph_string::calc_cof(float cent_x, float cent_y){

	cof_1 = cent_y/cent_x;

	float det = l - cent_x;
	cof_3[0] = l*cent_y/det;
	cof_3[1] = -cent_y/det;

	float **A, *X;
	X = new float [3];

	A = new float *[3];
	for(int i=0; i < 3; i++)
		A[i] = new float [3];
	X[0] = cent_y;
	A[0][0] = cent_x*cent_x; A[0][1] = cent_x; A[0][2] = 1;
	X[1] = cof_1 *(cent_x - dx_func1);
	A[1][0] = (cent_x - dx_func1)*(cent_x - dx_func1); A[1][1] = (cent_x - dx_func1); A[1][2] = 1;
	X[2] = cof_3[0] + cof_3[1]*(cent_x + dx_func1);
	A[2][0] = (cent_x + dx_func1)*(cent_x + dx_func1); A[2][1] = (cent_x + dx_func1); A[2][2] = 1;

	SLA_solution(A, X, 3);
	for(int i = 0; i < 3 ; i++)
		cof_2[i] = X[2-i];

	for (int i = 0; i < 3; i++)
		delete []A[i];
	delete []A;
	delete []X;
}

float ph_string::init_conditions_func(float x){
	float f = 0 ;
	if(x <= x_c - dx_func1){
		f = cof_1*x;
		return f;
	}
	if( x > x_c - dx_func1 && x < x_c + dx_func1){
		f = cof_2[0] + cof_2[1]*x + cof_2[2]*x*x;
		return f;
	}
	if( x >= x_c + dx_func1){
		f = cof_3[0] + cof_3[1]*x;
		return f;
	}
	return 0.0f;
}
