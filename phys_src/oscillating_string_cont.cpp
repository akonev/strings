#include "oscillating_string_cont.h"

double h3 = 1E-3;
double eps3 = 1E-5;
using namespace calc;

void osc_string_cont::init(float set_l, float set_N, float set_p, float x_force, float y_force, float dl_set){
	l = set_l;
	N = set_N;
	p = set_p * 1E-3;
	a = sqrt(N/p);
	x_c = x_force;
	A = y_force/1000.0;
	calc_cof(x_force, A);
	dl = dl_set;
	draw_number = l/dl + 2;
	draw_p = new string_point [draw_number];
	harm_numb = -1;
	tcur = 0;
	//T = 2*l/a;
	T = 15*l/a;

	int i;
#pragma omp parallel for
	for(i = 0; i < draw_number; i++){
		draw_p[i].x = i*dl;
		draw_p[i].y = init_conditions_func(draw_p[i].x)*1000;
	}
	A *= 1000;

}


void osc_string_cont::calc_func(float dharm){
	four_yes = true;
	double an, bn;

	int n = 1;
	an = four_int_sin(n);

	place_func.addinlist(an, 0, n);
	n++;

	while( absol(an) >= eps3 ){
		an = four_int_sin(n);
		place_func.addinlist(an,0,n);
		n++;
	};


	harmn = l/dharm + 2;
	harm = new string_point [harmn];
	harm_numb = 1;
	harm_max = place_func.maxn();
	place_func.takefromlist(1,an,bn);
	int i;
	for(i = 0; i < harmn; i++){
		harm[i].x = i*dharm;
		harm[i].y =  an*sin(pi*i*harm[i].x/l);
	}
}


float osc_string_cont::four_int_sin(int n){
	int numb = l/h3;
	int i;
	float Ssum = 0;
	float df1, df2;

    //Трапеции
    /*for(i = 0; i < numb - 1; i++){
		df1 = init_conditions_func(i*h3) * sin(pi*n*(i*h3)/l)*h3;
		df2 = init_conditions_func((i+1)*h3) * sin(pi*n*((i+1)*h3)/l) *h3;
		Ssum += (df1 + df2)/2;
	}
*/
	//Симпсон
	for(int i = 1; i < numb - 1; i++){
	    df1 = i*h3; //первый аргумент
	    df2 = (2*i-1)*h3/2; //второй аргумент
        Ssum += 2 * init_conditions_func(df1)*sin(pi*n*df1/l) + 4 * init_conditions_func(df2)*sin(pi*n*df2/l);
    }
    //sin(0) = 0 поэтому на слогаемое меньше
    df1 = (numb-1) * h3;
    df2 = (2*numb - 3) * h3 / 2;
    Ssum += init_conditions_func(df1)*sin(pi*n*df1/l) + 4 * init_conditions_func(df2)*sin(pi*n*df2/l);
    Ssum *= h3 / 6;


   	Ssum *= 2/l; //это множитель от коэффициента Фурье
	return Ssum;
}

float osc_string_cont::point_place(float x, float t){
	float T_part, X_part;
	float U = 0;

	double an, bn;
	int i;

	int numb = place_func.maxn();

#pragma omp parallel for private(T_part, X_part) reduction (+:U) schedule(dynamic,4)
	for(i = 1; i <= numb; i++){
		place_func.takefromlist(i,an,bn);
		T_part = an*cos(pi*i*a*t/l) + bn*sin(pi*i*a*t/l);
		X_part = sin(pi*i*x/l);
		U += T_part * X_part;
	}
	return U;
}

void osc_string_cont::points_place(float t){
	int i;
#pragma omp parallel for
	for(i = 0; i < draw_number; i++){
		draw_p[i].y = point_place(draw_p[i].x, t)*1000;
	}
}

void osc_string_cont::deinit(){
	four_yes = false;
	delete []draw_p;
	energy.clear();
	place_func.clearlist();
	if(harm_numb != -1)
    {
        harm_numb = -1;
        delete []harm;
    }

}

float osc_string_cont::derivative_t(float x, float t){
	float D = 0;
	int numb = place_func.maxn();
	float T_part, X_part;
	double an, bn;
	int i;

#pragma omp parallel for private(T_part, X_part) reduction (+:D) schedule(dynamic,4)
	for(i = 1; i <= numb; i++){
		place_func.takefromlist(i,an,bn);
		T_part = pi*i*a*(-an*sin(pi*i*a*t/l) + bn*cos(pi*i*a*t/l))/l;
		X_part = sin(pi*i*x/l);
		D += T_part * X_part;
	}
	return D;
}

float osc_string_cont::derivative_x(float x, float t){
	float D = 0;
	int numb = place_func.maxn();
	float T_part, X_part;
	double an, bn;
	int i;

#pragma omp parallel for private(T_part, X_part) reduction (+:D) schedule(dynamic,4)
	for(i = 1; i <= numb; i++){
		place_func.takefromlist(i,an,bn);
		T_part = an*cos(pi*i*a*t/l) + bn*sin(pi*i*a*t/l);
		X_part = pi*i*cos(pi*i*x/l)/l;
		D += T_part * X_part;
	}
	return D;
}

void osc_string_cont::calc_engraph(float t){
	if(tcur <= 3*T){
		float Enp = 0, Enk = 0;
		int numb = place_func.maxn();
		double an, bn;
		for(int i = 1; i <= numb; i++){
			place_func.takefromlist(i,an,bn);
			Enk += p*an*an*pi*pi*i*i*a*a*sin(pi*i*a*t/l)*sin(pi*i*a*t/l)/(4*l);
			Enp += N*an*an*pi*pi*i*i*cos(pi*i*a*t/l)*cos(pi*i*a*t/l)/(4*l);
		}
		energy.add(Enp, Enk, t);
		tcur = t;
	}
}

void osc_string_cont::point_place_harm(float t){
	double an, bn;
	place_func.takefromlist(harm_numb, an, bn);
	for(int i = 0; i < harmn; i++){
		harm[i].y = (an*cos(pi*harm_numb*a*t/l) + bn*sin(pi*harm_numb*a*t/l))*sin(pi*harm_numb*harm[i].x/l);
	}
}



