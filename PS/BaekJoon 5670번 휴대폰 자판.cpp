#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define TrieNode 26
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

struct Trie {
	Trie* next[TrieNode];
	bool start,finish;
	bool nextChild;
	int cnt = 0;

	Trie() {
		fill(next, next + TrieNode, nullptr);
		start = finish = nextChild = false;
		cnt = 0;
	}
	~Trie() {
		for (int i = 0; i < TrieNode; i++)
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

		return next[nextKey]->insert(key + 1, false);
	}

	int search(const char* key) {
		int ret = 0;
		if (*key == '\0')
			return ret;
		int nextKey = *key - 'a';

		if (cnt >= 2 || (cnt == 1 && finish) || start)
			ret += 1;

		ret += next[nextKey]->search(key + 1);
		return ret;
	}
};

char str[100002][82];

int main() {
	fastio;
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> str[i];

		Trie* root = new Trie;

		for (int i = 0; i < n; i++)
			root->insert(str[i], true);

		int ret = 0;
		for (int i = 0; i < n; i++) {
			ret += root->search(str[i]);
		}
		cout << fixed << setprecision(2) << 1.0 * ret / n << "\n";
		delete root;
	}
	
}