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

const int TrieNode = 10;
int N;
bool chk;
struct Trie {
	Trie* next[TrieNode];
	bool finish;
	bool nextChild;

	Trie() {
		fill(next, next + TrieNode, nullptr);
		finish = nextChild = false;
	}

	~Trie() {
		for (int i = 0; i < TrieNode; i++)
			if (next[i])
				delete next[i];
	}

	bool insert(const char* key) {
		if (*key == '\0') {
			finish = true;
			//문자열이 끝났는데도 자식이 있다면 일관성이 없다.
			if (nextChild) return 0;
			else return 1;
		}
		int nextKey = *key - '0';

		if (!next[nextKey])
			next[nextKey] = new Trie;
		nextChild = true;

		bool get = next[nextKey]->insert(key + 1);
		return !finish && get;
	}

};

int main() {
	fastio;
	int TC; cin >> TC;
	while (TC--) {
		cin >> N;
		chk = true;
		Trie* root = new Trie;
		for (int i = 0; i < N; i++) {
			char phone[10 + 1];
			cin >> phone;
			if (chk && root->insert(phone) == 0)
				chk = false;
		}
		if (chk) cout << "YES\n";
		else cout << "NO\n";
		delete root;
	}
	return 0;
}