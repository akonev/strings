#pragma once

#include "calc.h"

//============ Описание =============
// Общее для всех струн

struct string_point{
	float x, y;

	string_point() {
        x = 0.0f;
        y = 0.0f;
	}

	string_point(const float& x_in, const float& y_in) {
        x = x_in;
        y = y_in;
	}
};

class ph_string{
	public:
		ph_string(){
			dx_func1 = 0.4;
		}
		//точки для отрисовки их количество
		string_point *draw_p;
		int draw_number;
				float l;
						float x_c;

	protected:
		//коэффициенты для краевых условий
		float cof_1;
		float cof_2[3];
		float cof_3[2];

		//вершина начальной кривой


		//длина струны


		//расчёт коэффициентов для краевых условий
		void calc_cof(float cent_x, float cent_y);
		//расчёт начального положения точки x
		float init_conditions_func(float x);

	private:
		float dx_func1;

};

struct enlist_el{
	float kin, pot, t;
	enlist_el* next;
};

class energy_list{
	public:
		enlist_el* begin;
		 energy_list(){
			 begin = NULL;
		 }

		 void add(float po, float ki, float at){
			 if(begin == NULL){
				 begin = new enlist_el;
				 begin->pot = po; begin->kin = ki; begin->t = at;
				 begin->next = NULL;
			 }
			 else{
				 enlist_el *p;
				 p = begin;
				 while(p->next!=NULL) p = p->next;
				 p->next =  new enlist_el;
				 p = p->next;
				 p->pot = po; p->kin = ki; p->t = at;
				 p->next = NULL;
			 }
		 }

		 void clear(){
			 if(begin!=NULL){
				 enlist_el *p = begin, *p1_ = p->next;
				 while(p!=NULL){
					 delete p;
					 p = p1_;
					 if(p!=NULL) p1_ = p->next;
				 };
				 begin = NULL;
			 }
		 }

};
