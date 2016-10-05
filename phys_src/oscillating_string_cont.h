#pragma once

#include "ph_string.h"

//============ �������� =============
// ������������� �������� ����������� ������


class osc_string_cont: public ph_string{
	public:
		void init(float set_l, float set_N, float set_p, float x_force, float y_force, float dl_set);
		//l - ����� ������[�], N - ���� ���������[�],
		// p - �������� ��������� ������[��/�], x_force - ����� ����������, 0<x_force<l [�]
		// dl - ��������� ����� ���������� ����������������� �������
		void calc_func(float dharm);
		// dharm - ��������� ����� ���������� ����������������� ������� ��� ���������� �� ���������

		void points_place(float t);
		//��������� ��������� �����
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
		float dl; //��������� ����� ������� ��� ���������

		float point_place(float x, float t);
		//����� �������� ������ x � ������ ������� t

		float derivative_t(float x, float t);
		//������� ����������� �� ������� � �����
		float derivative_x(float x, float t);
		//������� ����������� �� ������� � �����

		float four_int_sin(int n);

		float a;
		//��������� ��������� ������: d^2u/dt^2 = a^2 * d^2u/dx^2, a = N/p
		float N, p;
		float T, tcur;
};
