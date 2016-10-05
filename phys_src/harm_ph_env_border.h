#pragma once

#include "ph_string.h"

using namespace calc;

class str_in_two_envs{
	public:
		void init(float set_w, float set_N, float set_p1, float set_p2, float force_y, float set_sl, float set_fl, float set_h);
		//set_w - частота воздействия, force_y - амплетуда силы, р1 - плотность части струны x>0
		//p2_ - плостность части струны x<0, N - силанятяжения нити
		//sl - начало отрезока, на которотом сичтаются колебания
		//fl - конец этого отрезка, h - шаг резибиения отрезка

		void move_showl(float dl);
		//сдвиг отрезка
		void deinit(){
			delete []draw_p;
		}
		string_point *draw_p;
		int draw_number;

		float p1_, p2_;


		float sl, fl; //начало и конец отрисовываймого отрезка
				float k1,k2; //волновые числа
		float A1, A2, B, A; //амплитуды
		void calc_points(float t);
	private:

		float w;

		float h;


};
