#pragma once

#include <cmath>

#include "math_and_ph_consts_define.h"
#include "list.h"
#include "gaus_jordan.h"

namespace calc{
double absol(double x);
//double sqrt(double x);
/*double cos(double x);
double sin(double x);*/
double arcsin(double x);
int integer_pow(double a, int b);
int fact(int n);
double deg_rad(double d); //������� �������� � �������
double rad_deg(double r); //������� ������ � �������

/*
double fi_fourcos_int(double n, double (*f)(double , double , double , double , double (*func)(double, double, double), double& , double), double l, double w, double fimax);
//intgral {0,l} �(t)*cos(nt)dt/l
double fi_foursin_int(double n, double (*f)(double , double , double , double , double (*func)(double, double, double), double& , double), double l, double w, double fimax);
//intgral {0,l} �(t)*sin(nt)dt/l
double fi_fourint(double n, double (*f)(double , double , double , double , double (*func)(double, double, double), double& , double), double l, double w, double fimax, double &Ssin);
//����� � ����� � �������. ��� ���������� �������.

int fi_four_sire(fourlist& fourfactor, double (*f)(double , double , double , double , double (*func)(double, double, double), double& , double), double T, double w, double fimax);
//���������� ������� �(t) � ��� �����
*/

}

