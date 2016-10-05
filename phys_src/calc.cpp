#include "calc.h"

double eps = 0.0001;
double h = 0.00001;
double h1 = 0.0001;

namespace calc{
double absol(double x){
	if(x>=0)
		return x;
	else
		return -x;
}

/*double sqrt(double x){
	double x1,x2;
	x1 = 1;
	x2 = (x1 + x/x1)/2;
	while(absol(x1-x2)>eps){
		x2 = x1;
		x1 = (x1 + x/x1)/2;
	}
	return x1;
}*/

/*double cos(double x){
	while (x < 0){
		x += 2*pi;
	};
	while (x > 2*pi){
		x = x - 2*pi;
	};

	double sum = 0, a0 = 1, a1 = 0;
	int iter = 0;
	while(absol(a0-a1)>eps){
		sum += a0;
		a1 = a0;
		iter += 2;
		a0 *= (-1)*x*x/((iter-1)*iter);
	};
	if(absol(sum) < eps) sum = 0;
	return sum;
}

double sin(double x){

	while (x < 0){
		x += 2*pi;
	};
	while (x > 2*pi){
		x -= 2*pi;
	};

	double sum = 0, a0 = x, a1 = 0;
	int iter = 1;
	while(absol(a0-a1)>eps){
		sum += a0;
		a1 = a0;
		iter += 2;
		a0 *= (-1)*x*x/((iter-1)*iter);
	};
	if(absol(sum) < eps) sum = 0;
	return sum;
}*/

int integer_pow(double a, int b){
	if(b > 0)
		for(int i = 0; i < b - 1 ; i++)
			a *= a;
	if(b < 0)
		for(int i = 0; i > b; i--)
			a /= a;
	return a;
}

int fact(int n){
	float nf = 1;
	for(int i = 1; i < n; i ++)
		nf *= i;
	return nf;
}

double arcsin(double x){
	float a = 1;
	float S = x;
	int n = 1;
	while ( a/n > eps){
		a *= n/(n+1)*x*x;
		n += 2;
		S += a/n;
	};
	return S;
}



double deg_rad(double d){
	return d*pi/180;
}

double rad_deg(double r){
	return r*180/pi;
}


//================= Разложение функции ф(t) в ряд Фурье =================
/*
double fi_fourcos_int(double n, double (*f)(double , double , double , double , double (*func)(double, double, double), double& , double), double l, double w, double fimax){
	double S = 0, x1 = 0;
	double fs;

	//Начальные условия для функции ф(t)
	double vl = 0;
	double fp = f(x1,fimax,vl,x1,&penenq,vl,w);
	double fp1,fs1;


	while(absol(x1-l)>=h1){
		fp1 = f(x1, fp, vl, x1+h1,func,vl,w);
		fs = fp * cos(2*n*(x1)*pi/l)*h1;
		fs1 = fp1 * cos(2*n*(x1+h)*pi/l)*h1;
		S += (fs+fs1)/2;
		x1 += h1;
		fp = fp1;
	};
	S = 2*S/l;
	return S;

}

double fi_foursin_int(double n, double (*f)(double , double , double , double , double (*func)(double, double, double), double& , double), double l, double w, double fimax){
	double S = 0, x1 = 0;
	double fs;

	//Начальные условия для функции ф(t)
	double vl = 0;
	double fp = f(x1,fimax,vl,x1,func,vl,w);
	double fp1,fs1;


	while(absol(x1-l)>=h1){
		fp1 = f(x1, fp, vl, x1+h1,&penenq,vl,w);
		fs = fp * sin(2*n*(x1)*pi/l)*h1;
		fs1 = fp1 * sin(2*n*(x1+h)*pi/l)*h1;
		S += (fs+fs1)/2;
		x1 += h1;
		fp = fp1;
	};
	S = 2*S/l;
	return S;

}

double fi_fourint(double n, double (*f)(double , double , double , double , double (*func)(double, double, double), double& , double), double l, double w, double fimax, double &Ssin){
	double Scos = 0, x1 = 0;
	double Ssin1 = 0;

	//Начальные условия для функции ф(t)
	double vl = 0;
	//double fp = f(x1,fimax,vl,x1,&penenq,vl,w);
	double fp1,fc,fc1,fs,fs1;

	int it_numb = l/h1;
	double *fp = new double [it_numb];
	fp[0] = f(x1,fimax,vl,x1,&penenq,vl,w);

	for(int i = 1; i < it_numb; i++)
		fp[i] = f(x1+(i-1)*h1, fp[i-1], vl, x1+i*h1,&penenq,vl,w);
	int i;
#pragma omp parallel for reduction (+:Scos) reduction (+:Ssin1) private (fc,fc1,fs,fs1,i) schedule(dynamic,4)
	for(i = 1; i < it_numb; i++){
		//fp1 = f(x1, fp, vl, x1+h1,&penenq,vl,w);

		fc = fp[i-1] * cos(2*n*(x1+i*h1)*pi/l)*h1;
		fc1 = fp[i] * cos(2*n*(x1+(i+1)*h1)*pi/l)*h1;
		fs = fp[i-1] * sin(2*n*(x1+i*h1)*pi/l)*h1;
		fs1 = fp[i] * sin(2*n*(x1+(i+1)*h1)*pi/l)*h1;

		Scos += (fc+fc1)/2;
		Ssin1 += (fs+fs1)/2;
	}
	Scos = 2*Scos/l;
	Ssin = 2*Ssin1/l;
	return Scos;

}

int fi_four_sire(fourlist& fourfactor, double (*f)(double , double , double , double , double (*func)(double, double, double), double& , double), double T, double w, double fimax){
	int n = 0;
	double an, bn = 0;
	an = fi_fourcos_int(n,f,T,w,fimax)/2;
	fourfactor.addinlist(an,bn,n);
	while(sqrt(an*an + bn*bn) > eps && n < 5){
		n++;
		an = fi_fourint(n,f,T,w,fimax,bn);
		fourfactor.addinlist(an,bn,n);
	};
	return 0;
}
*/
}


