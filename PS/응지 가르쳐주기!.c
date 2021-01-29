#include <stdio.h>
#include <string.h>
#pragma warning(disable:6031)
#pragma warning(disable:4996)

int main() {
	int a, b; scanf("%d %d", &a, &b);
	int tempb = b;
	int barr[3];
	for (int i = 0; i < 3; i++) {
		barr[i] = tempb % 10;
		tempb /= 10;
	}
	for (int i = 0; i < 3; i++) printf("%d\n", a*barr[i]);
	
	printf("%d", a * b);
}
