#pragma once

#include "ph_string.h"

//=============== ќписание ================
// ћоделирование конечной дискретной струны
// ¬ данном классе расчитываютс€ только точки, содержащие массу, остальные достраиваютс€ по пр€мым

class osc_string_discr: public ph_string{
	public:

		void init(float l_set, int w_numb, float w_set, int n_force, float y_force, float N);
		//l - длина струны[м], w_numb - количество грузов
		//w_set - масса грузов[кг], (n_force, y_force) - вершина начальной кривой, здесь n - номер груза
		//N_set - сила нат€жени€ нити
		void deinit();

		void points_place(float t);
		//расчЄт точек в момент времени
		energy_list *energy;
		float A; //амплитуда

        float N;

	private:

		float a;// a = N/(m*dl)
		float mass;
		float t_prev;
		float *speeds;

		float dl;


		float *s_add;
		string_point *d_add;
		string_point *calcm;
		float dsp_func(int n, float un, float unp, float unn);
};
