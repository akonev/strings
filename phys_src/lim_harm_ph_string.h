#pragma once

#include "ph_string.h"

using namespace calc;

class lim_harm_ph_string{
	public:
		virtual void change_harm_number(int set_n) = 0;  //������� ������ ����� ������������ ���������


		string_point *draw_p;
		int draw_number;
		energy_list energy;

		void deinit(){
			delete []draw_p;
			energy.clear();
		}

				float l; //����� ������

	protected:

		int n; //������������ ���������
		float wn; //������� ������������ ���������
};

class lhps_cont: public lim_harm_ph_string{
	public:
		void init(float set_l, float N, float p, float force_y, float set_h, int harm_num);
		// set_l - ����� ������, N - ���� ���������, p - ��������� ������
		//force_y - ��������� ����, ���������� ������
		//set_h ��� ���������.
		void change_harm_number(int set_n);

		void calc_points(float t);

		void calc_engraph(float t);

				float a;//����������� ��������� a = N/p
		float A;//��������� ���������
	private:

		float h;
		float N,p;
		float T,tcur;
};

class lhps_discr: public lim_harm_ph_string{
	public:
		void init(float set_l, float set_N, int w_numb, float set_m, float force_y,  int harm_num);
		// set_l - ����� ������, N - ���� ���������, w_numb - ���������� ������
		// set_m - ����� �����, force_y - ��������� ����, ���������� ������
		void change_harm_number(int set_n);

		void calc_points(float t);

				float A, m; // ��������� � �����

	private:

		float Zn; //��������
		float h; //��������� ����� �������
		float N;
};
