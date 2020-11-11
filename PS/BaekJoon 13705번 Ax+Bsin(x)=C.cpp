#include <cstdio> 
#include <math.h> 
#pragma warning(disable:4996)
using namespace std; 
int main() { 
	int a, b, c; 
	scanf("%d %d %d", &a, &b, &c); 
	double to = (c - b) / (double)a;
	double des = (c + b) / (double)a;
	double mid; int stopper = 50000;
	while (to < des && stopper--) {
		mid = (des + to) / 2;
		if (mid > (c - (b * (long double)sin(mid))) / a) des = mid;
		else if ( mid < (c - (b * (long double)sin(mid))) / a) to = mid +0.00000000000000000001;
	} 
	printf("%.19Lf\n", mid + 0.00000000000000000005);
	return 0; 
}

