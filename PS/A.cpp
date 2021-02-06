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

int main() {
	fastio;
	int TC; cin >> TC;
	while (TC--) {
		int N, K; cin >> N >> K;
		if (K >= 10000) {
			cout << -1 << "\n";
			continue;
		}
		vector<int> vec(N + 1);
		for (int i = 0; i < N; i++) cin >> vec[i];
		int check = 0;
		for (int i = 1; i <= K; i++) {
			for (int j = 0; j < N - 1; j++) {
				//������ ���� �� ���
				if (vec[j] < vec[j + 1]) {
					vec[j]++;
					if (i == K) check = j+1;
					break;
				}
				//���� �������� ���.
				else {
					if (j == N - 2) {
						check = -1;
						break;
					}
				}
			}
			if (check != 0) {
				if (check == -1) cout << -1 << "\n";
				else cout << check<< "\n";
				break;
			}
		}
	}
}