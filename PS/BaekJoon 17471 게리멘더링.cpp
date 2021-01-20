#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int ans; 
int n; 
int p[11]; 
vector<int> edge[11]; 
set<int> visited; 
void dfs(int v, set<int>& s) { 
	for (int next : edge[v]) {
		if (visited.find(next) == visited.end() && s.find(next) != s.end()) {
			visited.insert(next); dfs(next, s);
		}
	}
} 
bool is_equal(set<int>& a, set<int>& b) { 
	if (a.size() != b.size()) return false; 
	set<int>::iterator p1 = a.begin(); 
	set<int>::iterator p2 = b.begin(); 
	for (int i = 0; i < a.size(); i++) { 
		if (*p1 != *p2) return false; p1++; p2++; 
	} 
	return true; 
} 
void check(int bit) {
	set<int> a, b;
	int aval, bval; aval = bval = 0;
	for (int i = 0; i < n; i++) {
		int v = (1 << i); if (bit & v) { 
			a.insert(i); aval += p[i]; 
		} 
		else {
			b.insert(i); 
			bval += p[i];
		} 
	} //if (a.size() == 0 || b.size() == 0) return; 
	visited.clear(); 
	visited.insert(*a.begin()); dfs(*a.begin(), a); 
	if (is_equal(visited, a) == false) return;
	visited.clear(); 
	visited.insert(*b.begin()); 
	dfs(*b.begin(), b); if (is_equal(visited, b) == false) return; 
	ans = min(ans, abs(aval - bval));
} 
int main() { 
	ans = INF; 
	cin >> n; 
	for (int i = 0; i < n; i++) 
		cin >> p[i]; 
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		while (v--) { 
			int t; 
			cin >> t;
			edge[i].push_back(t - 1); 
		}
	}
	for (int bit = 1; bit + 1 < (1 << n); bit++) check(bit);
	if (ans == INF) ans = -1; cout << ans << endl;
}
