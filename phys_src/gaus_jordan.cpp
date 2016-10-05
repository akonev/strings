#include "gaus_jordan.h"

void SLA_solution(float **A, float *x, int n){
	trianglematrix1(A,x,n);
	trianglematrix2(A,x,n);
	int i;
#pragma omp for private(i) schedule(dynamic,4)
	for (i = 0; i < n ; i++){
		x[i]=x[i]/A[i][i];
	}
}



void trianglematrix1(float **A, float *x, int n){
	int i,j, ch_n = 10, k;
	for(i=0;i<n;i++){
		transf1(A,x,i,n);
#pragma omp parallel default(shared)
		{
#pragma omp for private(j,k) schedule(dynamic,ch_n)
			for(j = i+1; j < n ;j++)
			{
				if(A[j][i]!=0)
				{
					for(k=i+1;k<n;k++)
					{
						A[j][k] = A[j][k]*A[i][i] - A[i][k]*A[j][i];
					}
					x[j] = x[j]*A[i][i] - x[i]*A[j][i];
					A[j][i] = A[j][i]*A[i][i] - A[i][i]*A[j][i];
				}


			}
		}
	}
}

void trianglematrix2(float **A, float *x, int n){
	int i,j, ch_n = 10,k;
	for(i=n-1;i>=0;i--){
		transf2(A,x,i,n);
#pragma omp parallel default(shared)
		{
#pragma omp for private(j,k) schedule(dynamic,ch_n)
			for(j = i-1 ; j >= 0 ;j--){
				if(A[j][i]!=0){
					for(k=i-1;k>=0;k--){
						A[j][k] = A[j][k]*A[i][i] - A[i][k]*A[j][i];
					}
					x[j] = x[j]*A[i][i] - x[i]*A[j][i];
					A[j][i] = A[j][i]*A[i][i] - A[i][i]*A[j][i];
				}
			}
		}
	}
}


void transf1(float **A, float *x, int i, int n){
	float c;
	int j,k,f=0;
	if(A[i][i]==0){
		for(j=i+1;j<n&&!f;j++){
			if(A[j][i]!=0){
				f=1;
				for(k=i;k<n;k++) {
					c=A[j][k];
					A[j][k] = A[i][k];
					A[i][k] = c;
				}
				c = x[i];
				x[i] = x[j];
				x[j] = c;
			}
		}
	}
}

void transf2(float **A, float *x, int i, int n){
	float c;
	int j,k,f=0;
	if(A[i][i]==0){
		for(j=i-1;j>=0&&!f;j--){
			if(A[j][i]!=0){
				f=1;
				for(k=i;k<n;k++) {
					c=A[j][k];
					A[j][k] = A[i][k];
					A[i][k] = c;
				}
				c = x[i];
				x[i] = x[j];
				x[j] = c;
			}
		}
	}
}
