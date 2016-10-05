#include "lim_harm_ph_string.h"

//================= Непрерывная струна ====================

void lhps_cont::init(float set_l, float set_N, float set_p, float force_y, float set_h, int harm_num){
	a = sqrt(set_N/set_p);
	N = set_N;
	p = set_p;
	l = set_l;
	n = harm_num;
	h = set_h;
	A = force_y;
	wn = pi*a*harm_num/l;
	T = 2*pi/wn;
	tcur = 0;
	draw_number = l/h + 1;
	draw_p = new string_point [draw_number];
	calc_points(0);
}

void lhps_cont::calc_points(float t){
	for (int i = 0; i < draw_number; i++){
		draw_p[i].x = i*h;
		draw_p[i].y = 2*A*cos(wn*t)*sin(n*pi*draw_p[i].x/l);
	}
}


void lhps_cont::change_harm_number(int set_n){  //функция меняет номер отображаемой гармоники
			wn  = wn*set_n/n;
			n = set_n;
			T = 2*pi/wn;
			energy.clear();
		}

void lhps_cont::calc_engraph(float t){
	if(tcur <= 3*T){

        //Множетели 10^-6 из-за миилиметров
		float Enk = 1E-6 * p*A*A*pi*pi*n*n*a*a*sin(pi*n*a*t/l)*sin(pi*n*a*t/l)/(4*l);
		float Enp = 1E-6 * N*A*A*pi*pi*n*n*cos(pi*n*a*t/l)*cos(pi*n*a*t/l)/(4*l);

		energy.add(Enp, Enk, t);
		tcur = t;
	}
}
//================= Дискретная струна ====================

void lhps_discr::init(float set_l, float set_N, int w_numb, float set_m, float force_y,  int harm_num){
	l = set_l;
	m = set_m;
	n = 1;
	N = set_N;

	h = l/(w_numb+1);

	n = harm_num;
	wn = 2*sqrt(N/(m*h))*sin(pi*h*n/(2*l));
	Zn =  sqrt(N*m/h)*pi*h*n/(2*absol(sin(pi*n*h/(2*l))));
	//A = force_y/(wn*Zn);
	A = force_y;

	draw_number = w_numb;
	draw_p = new string_point[w_numb];
	calc_points(0);

}

void lhps_discr::calc_points(float t){
	for (int i = 1; i <= draw_number; i++){
		draw_p[i-1].x = i*h;
		draw_p[i-1].y = 2*A*cos(wn*t)*sin(pi*n*draw_p[i-1].x/l);
	}
}


void lhps_discr::change_harm_number(int set_n){  //функция меняет номер отображаемой гармоники
			n = set_n;
			wn = 2*sqrt(N/(m*h))*sin(pi*h*n/(2*l));
			Zn =  sqrt(N*m/h)*pi*h*n/(2*absol(sin(pi*n*h/(2*l))));

}
