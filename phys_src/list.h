#include <stdio.h>

struct list_el{
	double a, b;
	int n;
	list_el* next;
};

class fourlist{
	public:
		fourlist();
		~fourlist();

		int clearlist();
		int addinlist(double a, double b, int n);
		bool takefromlist(int n1,double &a, double &b);

		int maxn();
	private:
		
		list_el* begin;
};



