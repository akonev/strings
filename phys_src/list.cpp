#include "list.h"

fourlist::fourlist(){
	begin = 0;
}

fourlist::~fourlist(){
	list_el *p = begin;
	list_el *p1_;
	if(p!=0)
		p1_ = p->next;
	while(p!=0){
		delete p;
		p = p1_;
		if(p!=0) p1_ = p->next;
	};
}

int fourlist::addinlist(double a, double b, int n){
	list_el *p = begin;
	if(p==0){
		begin = new list_el;
		begin->a = a;
		begin->b = b;
		begin->n = n;
		begin->next = 0;
	}
	else{
		while(p->next!=0) p = p->next;
		p->next = new list_el;
		p = p->next;
		p->a = a;
		p->b = b;
		p->n = n;
		p->next = 0;
	}
	return 0;
}

bool fourlist::takefromlist(int n1, double &a, double &b){
	list_el *p = begin;
	while(p!=0 && p->n!=n1) p = p->next;
	if(p==0) return false;
	else{
		a = p->a;
		b = p->b;
		return true;
	}
}

int fourlist::maxn(){
	list_el *p = begin;
	int max = 0;
	while(p!=0){
		if(p->n > max) max = p->n;
		p = p->next;
	};
	return max;
}

int fourlist::clearlist(){
	if(begin!=NULL){
		list_el *p = begin, *p1_ = p->next;
		while(p!=NULL){
			delete p;
			p = p1_;
			if(p!=NULL) p1_ = p->next;
		};
		begin = NULL;
	}
	return 0;
}

