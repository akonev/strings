#include "harm_ph_env_border.h"

void str_in_two_envs::init(float set_w, float set_N, float set_p1, float set_p2, float force_y, float set_sl, float set_fl, float set_h){
	w = set_w;
	A1 = force_y;
	sl = set_sl;
	fl = set_fl;
	h = set_h;

	p1_ = set_p1;
	p2_ = set_p2;

	float Z1 = sqrt(set_N*set_p1), Z2 = sqrt(set_N*set_p2);
	A2 = 2*Z1*A1/(Z1 + Z2);
	B = (Z1 - Z2)*A1 / (Z1 + Z2);
	if(A1+ B> A2) A = A1 +B;
	else A = A2;

	k1 = w*sqrt(set_p1/set_N);
	k2 = w*sqrt(set_p2/set_N);

	draw_number = absol(fl - sl)/h + 1;
	draw_p = new string_point [draw_number];
}

void str_in_two_envs::move_showl(float dl){
	sl += dl;
	fl += dl;
}

void str_in_two_envs::calc_points(float t){
		for (int i = 0; i < draw_number; i++){
		draw_p[i].x = sl + i*h;
		if(draw_p[i].x <= 0)
			draw_p[i].y = A1*cos(w*t - k1*draw_p[i].x) + B*cos(w*t + k1*draw_p[i].x);
		else
			draw_p[i].y = A2*cos(w*t - k2*draw_p[i].x);
	}
}
