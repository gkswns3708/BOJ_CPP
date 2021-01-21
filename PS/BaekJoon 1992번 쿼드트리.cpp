#include <bits/stdc++.h>
#pragma warning(disable:4996)
int arr[70][70] = { 0, };
int width;

void DaC(int y, int x, int size) {
	int firstnum = arr[y][x];
	int breakcheck = 0;
	if (size == 1) {
		printf("%d", arr[y][x]);
		return;
	}
	else {
		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				if (arr[i][j] != firstnum) {
					printf("(");
					DaC(y, x, size / 2);
					DaC(y, x + size / 2, size / 2);
					DaC(y + size / 2, x, size / 2);
					DaC(y + size / 2, x + size / 2, size / 2);
					breakcheck = 1;
					printf(")");
					break;
				}
			}
			if (breakcheck == 1) {
				break;
			}
		}
	}
	if (breakcheck != 1) {
		printf("%d", firstnum);
	}
}

int main() {
	scanf("%d", &width);
	int tempnum;
	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= width; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	DaC(1, 1, width);
	return 0;
}