#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <memory.h>
#define int long long int
using namespace std;

string s;
int N;
int cnt;
int cost[100];

int DP(int now) {
	if (now <= 0) return 1;
	if (cost[now] != -1) return cost[now];

	cost[now] = 0;
	if ((s[now - 1] != '0')) cost[now] += DP(now - 1);
	if (now - 2 >=0 &&(s[now - 2] != '0')) cost[now] += DP(now - 2);
	return cost[now];	
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	fill(&cost[0], &cost[50 + 1], -1);
	cout << DP(N-1);
	return 0;
}