#include "harm_ph_string.h"

using namespace calc;

//================= Общее ====================

void harm_ph_string::deinit(){
	delete []draw_p;
}
void harm_ph_string::move_showl(float dl){
	sl += dl;
	fl += dl;
}

//================= Непрерывная струна ====================

void harm_ph_string_cont::init(float set_w, float force_y, float set_p, float set_N, float set_sl, float set_fl, float set_h){
	w = set_w;
	sl = set_sl;
	fl = set_fl;
	h = set_h;
	//T = 2*pi/w;
	T = 15*pi/w;
	p = set_p;
	N = set_N;
	A = force_y / (w* sqrt(p*N));
    //A = force_y;
	k = w * sqrt(p/N);
	draw_number = absol(fl - sl)/h + 1;
	draw_p = new string_point [draw_number];
}



void harm_ph_string_cont::calc_points(float t){
	for (int i = 0; i < draw_number; i++){
		draw_p[i].x = sl + i*h;
		draw_p[i].y = A*cos(w*t - k*draw_p[i].x);
	}
}


//================= Дискретная струна ====================

void harm_ph_string_discr::init(float set_w, float force_y, float set_N, float set_m, float set_h, float set_sl, float set_fl){
	w = set_w;
	N = set_N;
	m = set_m;
	h = set_h;

	A = force_y*sqrt(h) / (w* sqrt(m*N));
   // A = force_y;
	sl = set_sl;
	fl = set_fl;
	T = 2*pi/w;

	k = 2*arcsin(w*sqrt(m*h/N)/2)/h;
	draw_number = absol(fl - sl)/h + 1;
	draw_p = new string_point [draw_number];
}

void harm_ph_string_discr::calc_points(float t){
	for (int i = 0; i < draw_number; i++){
		draw_p[i].x = sl + i*h;
		draw_p[i].y = A*cos(w*t - k*draw_p[i].x);
	}
}
