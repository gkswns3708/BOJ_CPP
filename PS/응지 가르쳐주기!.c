#include <stdio.h>
#include <string.h>
#pragma warning(disable:6031)
#pragma warning(disable:4996)

/*
	숫자 a,b를 받아서(3자리 수)
	1 2 3 * 4 5 6
	1 2 3 * 6
  1 2 3 * 5
1 2 3 * 4
-------------
1 2 3 * 4 5 6
*/


int main() {
	int a, b; scanf("%d %d", &a, &b);
	int tempb = b;
	//1의 자리수가 0번째 10의자리수가 1번째 100의자리수가 2번째
	int barr[3];
	for (int i = 0; i < 3; i++) {
		barr[i] = tempb % 10;
		tempb /= 10;
	}
	for (int i = 0; i < 3; i++) printf("%d\n", a*barr[i]);
	
	printf("%d", a * b);
}
