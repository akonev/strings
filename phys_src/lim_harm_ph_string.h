#pragma once

#include "ph_string.h"

using namespace calc;

class lim_harm_ph_string{
	public:
		virtual void change_harm_number(int set_n) = 0;  //функция меняет номер отображаемой гармоники


		string_point *draw_p;
		int draw_number;
		energy_list energy;

		void deinit(){
			delete []draw_p;
			energy.clear();
		}

				float l; //длина струны

	protected:

		int n; //отоброжаемая гармоника
		float wn; //частота отображаемой гармоники
};

class lhps_cont: public lim_harm_ph_string{
	public:
		void init(float set_l, float N, float p, float force_y, float set_h, int harm_num);
		// set_l - длина струны, N - сила натяжения, p - плотность струны
		//force_y - амплитуда силы, колеблющей струну
		//set_h шаг разбиения.
		void change_harm_number(int set_n);

		void calc_points(float t);

		void calc_engraph(float t);

				float a;//коэффициент уравннеия a = N/p
		float A;//амплетуда колебаний
	private:

		float h;
		float N,p;
		float T,tcur;
};

class lhps_discr: public lim_harm_ph_string{
	public:
		void init(float set_l, float set_N, int w_numb, float set_m, float force_y,  int harm_num);
		// set_l - длина струны, N - сила натяжения, w_numb - количество грузов
		// set_m - масса груза, force_y - амплитуда силы, колеблющей струну
		void change_harm_number(int set_n);

		void calc_points(float t);

				float A, m; // амплетуда и масса

	private:

		float Zn; //импеданс
		float h; //растояние между грузами
		float N;
};
