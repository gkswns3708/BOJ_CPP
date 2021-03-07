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

int N, K;

vector<int> vec;
vector<int> gap;
int sum;
void input() {
	cin >> N >> K;
	vec.resize(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
}

void solution() {
	if (K >= N) {
		cout << "0\n";
		return;
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	gap.resize(vec.size());
	sum = vec[vec.size() - 1] - vec[0];
	for (int i = 1; i < vec.size(); i++) gap[i - 1] = vec[i] - vec[i - 1];
	sort(all(gap),greater<long long int>());
	for (int i = 0; i < K-1; i++) sum -= gap[i];
	cout << sum;
}

int main() {
	fastio;
	input();
	solution();
}