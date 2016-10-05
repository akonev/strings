#pragma once

#include "ph_string.h"

using namespace calc;

class str_in_two_envs{
	public:
		void init(float set_w, float set_N, float set_p1, float set_p2, float force_y, float set_sl, float set_fl, float set_h);
		//set_w - ������� �����������, force_y - ��������� ����, �1 - ��������� ����� ������ x>0
		//p2_ - ���������� ����� ������ x<0, N - ������������� ����
		//sl - ������ ��������, �� ��������� ��������� ���������
		//fl - ����� ����� �������, h - ��� ���������� �������

		void move_showl(float dl);
		//����� �������
		void deinit(){
			delete []draw_p;
		}
		string_point *draw_p;
		int draw_number;

		float p1_, p2_;


		float sl, fl; //������ � ����� ��������������� �������
				float k1,k2; //�������� �����
		float A1, A2, B, A; //���������
		void calc_points(float t);
	private:

		float w;

		float h;


};
