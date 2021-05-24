#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;
int N, M;
int parents[50 + 1];
bool truth[50 + 1];
vector<int> know;
vector<vector<int>> group(50);
int _Find(int x) {
	return parents[x] == x ? x : parents[x] = _Find(parents[x]);
}

void _Union(int a, int b) {
	a = _Find(a), b = _Find(b);
	a < b ? parents[b] = a : parents[a] = b;	
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int tp; cin >> tp;
	for (int i = 0; i < tp; i++) {
		int num; cin >> num;
		know.push_back(num);
	}

	for (int i = 1; i <= N; i++) parents[i] = i;

	for (int k = 0; k < M; k++) {
		int TC; cin >> TC;
		int num,prev;
		for (int i = 0; i < TC; i++) {
			if (i == 0) cin >> num;
			else {
				prev = num;
				cin >> num;
				_Union(prev, num);
			}
			group[k].push_back(num);
		}
	}
	for (auto TC : group) {
		bool flag = false;
		for (auto list : TC) {
			if (flag)break;
			else for (auto now : know) if (_Find(list) == _Find(now)) flag = true;
		}
		if (flag) M--;
	}
	cout << M;
	return 0;
}