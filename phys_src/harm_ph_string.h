#pragma once

#include "ph_string.h"

class harm_ph_string{
	public:
		void move_showl(float dl);
		//����� �������
		void deinit();

		string_point *draw_p;
		int draw_number;

				float sl, fl; //������ � ����� ��������������� �������
		float w, A; //������� � ���������
	protected:

};


class harm_ph_string_cont: public harm_ph_string{
	public:
		void init (float set_w, float force_y, float set_p, float set_N, float set_sl, float set_fl, float set_h);
		//set_w - ������� �����������, force_y - ��������� ����, � - ��������� ������, N - ������������� ����
		//sl - ������ ��������, �� ��������� ��������� ���������
		//fl - ����� ����� �������, h - ��� ���������� �������

		void calc_points(float t);
		float T;

	private:
		float h;
		float k;
		float p, N;

};

class harm_ph_string_discr: public harm_ph_string{
	public:
		void init (float set_w, float set_A, float set_N, float set_m, float set_h, float set_sl, float set_fl);
		//set_w - ������� �����������, � - ���������, N - ������������� ����
		//m - ����� ������� �����, h - ��������� ����� �������
		//sl - ������ ��������, �� ��������� ��������� ���������
		//fl - ����� ����� �������
		void calc_points(float t);

		float T;
	private:
		float N, m;
		float h , k;
};
