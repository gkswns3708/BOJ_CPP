#include <bits/stdc++.h>
#define int long long int
using namespace std;

int N, M;
char arr[110][20];
char arr2[110][20];
map<char, double> mp;
map<char, int> mp2;
typedef struct contents {
	int x,y;
	char ochar;
	bool Y;
	double score;
	bool operator < (const contents& now) const {
		if (Y != now.Y) return Y;
		if (score != now.score) return score > now.score;
		if (x != now.x) return x < now.x;
		return y < now.y;
	}
}contents;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 5; i++) {
		double dou; cin >> dou;
		mp['A' + i] = dou;
	}
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr2[i][j];
	}
	vector<contents> ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'W') continue;
			contents cont;
			cont.score = mp[arr2[i][j]];
			cont.ochar = arr2[i][j];
			cont.Y = arr[i][j] == 'Y';
			cont.y = i;
			cont.x = j;
			ans.push_back(cont);
		}
	}

	sort(ans.begin(), ans.end());
	cout << fixed << setprecision(1);
	for (auto now : ans) cout << now.ochar << " " << now.score <<" " << now.y <<" " << now.x <<"\n";


	return 0;
}