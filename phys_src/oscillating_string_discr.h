#pragma once

#include "ph_string.h"

//=============== �������� ================
// ������������� �������� ���������� ������
// � ������ ������ ������������� ������ �����, ���������� �����, ��������� ������������� �� ������

class osc_string_discr: public ph_string{
	public:

		void init(float l_set, int w_numb, float w_set, int n_force, float y_force, float N);
		//l - ����� ������[�], w_numb - ���������� ������
		//w_set - ����� ������[��], (n_force, y_force) - ������� ��������� ������, ����� n - ����� �����
		//N_set - ���� ��������� ����
		void deinit();

		void points_place(float t);
		//������ ����� � ������ �������
		energy_list *energy;
		float A; //���������

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
