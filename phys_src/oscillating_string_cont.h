#pragma once

#include "ph_string.h"

//============ Описание =============
// Моделирование конечной непрерывной струны


class osc_string_cont: public ph_string{
	public:
		void init(float set_l, float set_N, float set_p, float x_force, float y_force, float dl_set);
		//l - длина струны[м], N - сила натяжения[Н],
		// p - линейная плотнасть струны[кг/м], x_force - точка приложения, 0<x_force<l [м]
		// dl - растояние между сосоедними отрисовывающимися точками
		void calc_func(float dharm);
		// dharm - растояние между сосведними отсисовывающимися точками при разложении на гармоники

		void points_place(float t);
		//вычистить положения точек
		void deinit();

		energy_list energy;
		string_point *harm;
		int harmn;
		int harm_numb;
		int harm_max;

		void point_place_harm(float t);

		void calc_engraph(float t);

		float A;

        bool four_yes;


	private:
		fourlist place_func;
		float dl; //растояние между точками для отрисовки

		float point_place(float x, float t);
		//место пложение точеки x в момент времени t

		float derivative_t(float x, float t);
		//частная производная по времени в точке
		float derivative_x(float x, float t);
		//частная производная по времени в точке

		float four_int_sin(int n);

		float a;
		//уравнение колебаний струны: d^2u/dt^2 = a^2 * d^2u/dx^2, a = N/p
		float N, p;
		float T, tcur;
};
