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

int N;
int dist[20 + 1][20 + 1];
bool visited[20 + 1][20 + 1];
int ans;
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> dist[i][j];
			visited[i][j] = true;
		}

}

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (j == k || i == j || i == k) continue;
				if (dist[j][k] == dist[j][i] + dist[i][k]) {
					visited[j][k] = false;
				}
				else if (dist[j][k] > dist[j][i] + dist[i][k]) {
					cout << -1;
					exit(0);
				}
			}
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (visited[i][j]) ans += dist[i][j];
		}
	}
	cout << ans;
}

int main() {
	fastio;
	input();
	solution();
	return 0;
}