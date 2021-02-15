#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

vector<int> chu;
vector<int> weight;
int N, M;
int dp[30 + 1][30 * 500 + 1];

void solution(int nwn, int nw) {
	if (nwn > N) return;

	int& now = dp[nwn][nw];
	if (now != -1) return;

	now = 1;
	//현재 도달한 무게는 가능하다.
	solution(nwn + 1, nw);
	if (nwn != N) {
		solution(nwn + 1, nw + chu[nwn]);
		solution(nwn + 1, abs(nw - chu[nwn]));
	}
}

int main() {
	fastio;
	cin >> N;
	chu.resize(N);
	for (int i = 0; i < N; i++) cin >> chu[i];
	cin >> M;
	weight.resize(M);
	for (int i = 0; i < M; i++) cin >> weight[i];
	memset(dp, -1, sizeof(dp));
	solution(0, 0);
	for (int i = 0; i < M; i++) {
		if (weight[i] > 15000) cout << "N ";
		else if (dp[N][weight[i]] == 1) cout << "Y ";
		else cout << "N ";
	}
}