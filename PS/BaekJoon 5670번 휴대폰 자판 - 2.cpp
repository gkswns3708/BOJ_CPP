
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

const int alphabet = 26;

struct Trie {
	Trie* next[alphabet];
	bool finish, start,nextChild;
	int cnt;

	Trie() {
		fill(next, next + alphabet, nullptr);
		start = finish = nextChild = false;
		cnt = 0;
	}

	~Trie() {
		for (int i = 0; i < alphabet; i++)
			if (next[i]) delete next[i];
	}

	bool insert(const char* key, bool isStart) {
		if (isStart)
			start = true;
		if (*key == '\0') {
			finish = true;
			return true;
		}

		int nextKey = *key - 'a';
		if (!next[nextKey]) {
			next[nextKey] = new Trie;
			cnt++;
		}
		nextChild = true;
		cout << key << " " << key + 1 << " - key¿Í key+1\n";

		return next[nextKey]->insert(key+1,false);
	}

};

void input() {
	
}

void solution() {

}

int main() {
	fastio;
	int TC; cin >> TC;
	while (TC--) {
		input();
		solution();
	}
}