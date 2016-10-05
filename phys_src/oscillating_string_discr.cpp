#include "oscillating_string_discr.h"

using namespace calc;

void osc_string_discr::init(float l_set, int w_numb, float w_set, int n_force, float y_force, float N_set){
	draw_number = w_numb;
	N = N_set;
	d_add = new string_point [draw_number];
	s_add = new float[draw_number];
	l = l_set;
	A = y_force/1000.0;
	dl = l/(w_numb+1);
	x_c = n_force*dl;
	a = N/(w_set*dl);
	mass = w_set;
	t_prev = 0;
	calc_cof(x_c, A);

	draw_p = new string_point[w_numb];
	speeds = new float [w_numb];
	calcm = new string_point[w_numb];

	energy = new energy_list [w_numb];

	int i;
	int sp = w_numb + 1;
	for(i = 1; i < sp; i++){
		calcm[i-1].x = i*dl;
		calcm[i-1].y = init_conditions_func(calcm[i-1].x);
		draw_p[i-1].x = calcm[i-1].x;
		draw_p[i-1].y = calcm[i-1].y*1000;
		speeds[i-1] = 0;
	}
	A *= 1000;
}

void osc_string_discr::points_place(float t){
	float h = 0.0001;
	float **m , **k;
	m = new float* [draw_number];
	k = new float* [draw_number];
	for(int i = 0; i < draw_number ;i ++){
		m[i] = new float [4];
		k[i] = new float [4];
	}
	if(draw_number > 1){
		while( absol(t-t_prev) > h){
			//запоминаются сратые значения
			for(int i = 0; i < draw_number; i++){
				d_add[i].x = calcm[i].x;
				d_add[i].y = calcm[i].y;
				s_add[i] = speeds[i];
			}


			//метод Рунге-Кута, первые коэффициенты
			for(int i = 1; i < draw_number - 1; i++){
				m[i][0] = h*dsp_func(i,calcm[i].y, calcm[i-1].y, calcm[i+1].y);
				k[i][0] = h*s_add[i];
			}
			m[0][0] = h*dsp_func(0, calcm[0].y, 0, calcm[1].y);
			k[0][0] = h*s_add[0];
			m[draw_number - 1][0] = h*dsp_func(draw_number - 1, calcm[draw_number -1].y,  calcm[draw_number -2].y, 0);
			k[draw_number - 1][0] = h*s_add[draw_number - 1];


			//метод Рунге-Кута, вторые коэффициенты
			for(int i = 1; i < draw_number - 1; i++){
				m[i][1] = h*dsp_func(i,calcm[i].y + m[i][0]/2, calcm[i-1].y + m[i-1][0]/2, calcm[i+1].y + m[i+1][0]/2);
				k[i][1] = h*(s_add[i] + k[i][0]/2);
			}
			m[0][1] = h*dsp_func(0, calcm[0].y, 0 + m[0][0]/2, calcm[1].y + m[1][0]/2);
			k[0][1] = h*(s_add[0] + k[0][0]/2);
			m[draw_number - 1][1] = h*dsp_func(draw_number - 1, calcm[draw_number -1].y + m[draw_number -1][0]/2,  calcm[draw_number -2].y + m[draw_number -2][0]/2, 0);
			k[draw_number - 1][1] = h*(s_add[draw_number - 1] + k[draw_number - 1][0]/2) ;


			//метод Рунге-Кута, третие коэффициенты
			for(int i = 1; i < draw_number - 1; i++){
				m[i][2] = h*dsp_func(i,calcm[i].y + m[i][1]/2, calcm[i-1].y + m[i-1][1]/2, calcm[i+1].y + m[i+1][1]/2);
				k[i][2] = h*(s_add[i] + k[i][1]/2);
			}
			m[0][2] = h*dsp_func(0, calcm[0].y, 0 + m[0][1]/2, calcm[1].y + m[1][1]/2);
			k[0][2] = h*(s_add[0] + k[0][1]/2);
			m[draw_number - 1][2] = h*dsp_func(draw_number - 1, calcm[draw_number -1].y + m[draw_number -1][1]/2,  calcm[draw_number -2].y + m[draw_number -2][1]/2, 0);
			k[draw_number - 1][2] = h*(s_add[draw_number - 1] + k[draw_number - 1][1]/2) ;


			//метод Рунге-Кута, четвёртые коэффициенты
			for(int i = 1; i < draw_number - 1; i++){
				m[i][3] = h*dsp_func(i,calcm[i].y + m[i][2], calcm[i-1].y + m[i-1][2], calcm[i+1].y + m[i+1][2]);
				k[i][3] = h*(s_add[i] + k[i][2]);
			}
			m[0][3] = h*dsp_func(0, calcm[0].y, 0 + m[0][2], calcm[1].y + m[1][2]);
			k[0][3] = h*(s_add[0] + k[0][2]);
			m[draw_number - 1][3] = h*dsp_func(draw_number - 1, calcm[draw_number -1].y + m[draw_number -1][2],  calcm[draw_number -2].y + m[draw_number -2][2], 0);
			k[draw_number - 1][3] = h*(s_add[draw_number - 1] + k[draw_number - 1][1]) ;


			//метод Рунге-Кута, вычисление значений
			for(int i = 0; i < draw_number; i++){
				speeds[i] = s_add[i] + (m[i][0] + 2*m[i][1] + 2*m[i][2] * m[i][3])/6;
				calcm[i].y = d_add[i].y + (k[i][0] + 2*k[i][1] + 2*k[i][2] * k[i][3])/6;
			}

			t_prev += h;
		};
	}
	else
	{
		while( absol(t-t_prev) > h){
			d_add[0].x = calcm[0].x;
			d_add[0].y = calcm[0].y;
			s_add[0] = speeds[0];

			m[0][0] = h*dsp_func(0, calcm[0].y, 0, 0);
			k[0][0] = h*s_add[0];

			m[0][1] = h*dsp_func(0, calcm[0].y, 0 + m[0][0]/2, 0);
			k[0][1] = h*(s_add[0] + k[0][0]/2);


			m[0][2] = h*dsp_func(0, calcm[0].y, 0 + m[0][1]/2, 0);
			k[0][2] = h*(s_add[0] + k[0][1]/2);


			m[0][3] = h*dsp_func(0, calcm[0].y, 0 + m[0][2], 0);
			k[0][3] = h*(s_add[0] + k[0][2]/2);

			speeds[0] = s_add[0] + (m[0][0] + 2*m[0][1] + 2*m[0][2] * m[0][3])/6;
			calcm[0].y = d_add[0].y + (k[0][0] + 2*k[0][1] + 2*k[0][2] * k[0][3])/6;

			t_prev += h;
		};
	}

	for(int i = 0; i < draw_number; i++){
		draw_p[i].y = calcm[i].y*1000;
	}

	for(int i = 0; i < draw_number ;i ++){
		delete []m[i];
		delete []k[i];
	}
	delete []m;
	delete []k;

	float Enk, Enp;
	for(int i = 0; i < draw_number; i++){
		Enk = mass * speeds[i] * speeds[i]/2;
		if(i==0){
			Enp = N*(calcm[i+1].y - calcm[i].y)*(calcm[i+1].y - calcm[i].y)/(2*dl);
		}
		else {
			if(i==draw_number-1){
				Enp = N*(calcm[i].y - calcm[i-1].y)*(calcm[i].y - calcm[i-1].y)/(2*dl);
			}
			else{
		//	Enp = N*absol((calcm[i+1].y -calcm[i-1].y))/(2*dl);
			Enp = N*(calcm[i].y - calcm[i-1].y)*(calcm[i].y - calcm[i-1].y)/(2*dl);
			}
		}
		energy[i].add(Enp,Enk,t);
	}


}

float osc_string_discr::dsp_func(int n, float un, float unp, float unn){
	//unp - un prev, unn - un next
	if(draw_number ==1){
		return a*(-2*un);
	}
	else{
		if(n != draw_number - 1){
			return a*(unn - 2*un + unp);
		}
		else
			return
				a*(unp - 2*un);
	}
}
void osc_string_discr::deinit(){
	delete []draw_p;
	delete []speeds;
	delete []d_add;
	delete []s_add;
	delete []calcm;
	for(int i = 0; i<draw_number; i++)
		energy[i].clear();
}
