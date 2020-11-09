//초항 200개를 구하는 naive dp
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

//dp[i][state]: i 미만은 다 채워져있고 i행의 상태가 state일 때의 경우의 수

const int MOD = int(1e9) + 7;
int dp[201][1 << 16] = { 1 };
vector<int> nxt;
vector<int> adj[16] = {
	{ 1, 2, 4, 8 },
	{ 0, 3, 5, 9 },
	{ 3, 0, 6, 10 },
	{ 2, 1, 7, 11 },

	{ 5, 6, 0, 12 },
	{ 4, 7, 1, 13 },
	{ 7, 4, 2, 14 },
	{ 6, 5, 3, 15 },

	{ 9, 10, 12, 0 },
	{ 8, 11, 13, 1 },
	{ 11, 8, 14, 2 },
	{ 10, 9, 15, 3 },

	{ 13, 14, 8, 4 },
	{ 12, 15, 9, 5 },
	{ 15, 12, 10, 6 },
	{ 14, 13, 11, 7 }
};
void dfs(int prev, int cur) {
	if (prev == (1 << 16) - 1) {
		nxt.push_back(cur);
		return;
	}
	//첫 번째 0의 위치
	//prev의 첫번째 0의 위치를 찾아줌.
	int idx = __builtin_ctz(~prev);
	assert(idx < 16);
	for (auto i : adj[idx]) if (~prev & (1 << i)) dfs(prev | (1 << idx) | (1 << i), cur);
	dfs(prev | (1 << idx), cur | (1 << idx));
}

int main() {
	fastio;
	for (int i = 0; i < 150; i++) {
		for (int state = 0; state < (1 << 16); state++) {
			//이전 p가 state일 때 다음 nxt_state를 결정해야 함.
			//인접한 두 칸(32개 가능)이 둘 다 비어있다면 해당 칸을 가로로 채우거나 또는 세로로 채울 수 있음
			//한 칸만 따로 떨어져있다면 무조건 채워야함. 최종 단게에서 이전 행이 다 채워져있지 않다면 다음 단계로 넘어갈 수 없음.
			nxt.clear();
			dfs(state, 0);
			for (int nxt_state : nxt) dp[i + 1][nxt_state] = (dp[i + 1][nxt_state] + dp[i][state]) % MOD;
		}
		cout << dp[i][0] << ", ";
	}
	
	return 0;
}
