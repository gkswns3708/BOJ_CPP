#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

string s;
char trans[100];
int board[512 + 1][512+1];
int pos = 0;
//'B'°¡ 1

void solution(int y, int x, int len) {
	if (s[pos] == 'Q') {
		pos++;
		solution( y, x, len / 2);
		solution( y, x + len / 2, len / 2);
		solution( y + len / 2, x, len / 2);
		solution( y + len / 2, x + len / 2, len / 2);
	}
	else {
		for (int i = 0; i < len; i++) for (int j = 0; j < len; j++) board[y + i][x + j] = trans[s[pos]];
		pos++;
	}
}

int32_t main()
{
	int N; cin >> N;
	cin >> s;
	trans['B'] = 1, trans['W'] = 0;
	solution(0, 0, N);
	cout << "#define quadtree_width " << N << "\n";
	cout << "#define quadtree_height " << N << "\n";
	cout << "static char quadtree_bits[] = {\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j+=8) {
			int cal = 1, tmp = 0;
			for (int k = 0; k < 8; k++) {
				tmp += cal * board[i][j + k];
				cal <<= 1;
			}
			printf("0x%02llx,", tmp);
		}
		cout << "\n";
	}
	cout << "};\n";
	return 0;
}