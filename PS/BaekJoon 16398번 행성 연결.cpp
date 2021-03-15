#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define int long long int
using namespace std;

int N,ans;
int parents[1000 + 1];
int arr[1000 + 2][1000 + 2];
vector<tuple<int, int, int>> vec;
int find(int x) { return x == parents[x] ? x : parents[x] = find(parents[x]); }
void _Union(int a, int b) {
	a = find(a), b = find(b);
	if (a < b) parents[b] = a;
	else parents[a] = b;
}

int Kruskal() {
	for (auto now : vec) {
		auto [cost, parents, child] = now;
		if (find(parents) == find(child)) continue;
		else ans += cost,_Union(parents, child);
	}
	return ans;
}
//해당 문제는 모든 간선이 1억으로 연결되어 있다면int로는 overflow가 난다 lone long int를 사용하자.
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> arr[i][j];
	for (int i = 1; i <= N; i++) for (int j = i + 1; j <= N; j++) vec.push_back({ arr[i][j],i,j });
	for (int i = 1; i <= N; i++) parents[i] = i;	
	sort(vec.begin(), vec.end());
	cout << Kruskal();
	return 0;
}