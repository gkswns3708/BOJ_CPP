#include <stdio.h>
#include <string.h>
#pragma warning(disable:6031)
#pragma warning(disable:4996)

/*
	���� a,b�� �޾Ƽ�(3�ڸ� ��)
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
	//1�� �ڸ����� 0��° 10���ڸ����� 1��° 100���ڸ����� 2��°
	int barr[3];
	for (int i = 0; i < 3; i++) {
		barr[i] = tempb % 10;
		tempb /= 10;
	}
	for (int i = 0; i < 3; i++) printf("%d\n", a*barr[i]);
	
	printf("%d", a * b);
}
