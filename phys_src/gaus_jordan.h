#pragma once
#include <omp.h>

void SLA_solution(float **A, float *x, int n);

void trianglematrix1(float **A, float *x, int n); //Приведение матрицы к верхнему треугольному виду
void trianglematrix2(float **A, float *x, int n); //Приведение матрицы к нижнему треугольному виду
void transf1(float **A, float *x, int i,int n); // перестановка строк
void transf2(float **A, float *x, int i,int n);