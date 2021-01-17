#include <stdio.h>

int main() {
	int p[10][10] = { 0, };

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) p[i][j] = 1;
			else if (i == j) p[i][j] = 1;
			else {
				//...중간 삼각형의 값.
				p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	return 0;
}