#pragma once
#include <omp.h>

void SLA_solution(float **A, float *x, int n);

void trianglematrix1(float **A, float *x, int n); //���������� ������� � �������� ������������ ����
void trianglematrix2(float **A, float *x, int n); //���������� ������� � ������� ������������ ����
void transf1(float **A, float *x, int i,int n); // ������������ �����
void transf2(float **A, float *x, int i,int n);