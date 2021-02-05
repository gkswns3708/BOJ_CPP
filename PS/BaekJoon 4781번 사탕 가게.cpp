#include <bits/stdc++.h>
#include "BaekJoon 4781¹ø »çÅÁ °¡°Ô.h"
using namespace std;
typedef long long int ll;

int N, M;

vector<pair<int, int>> pii;
int dp[10000+1];
void solution() {
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j<N; j++) {
			if(i-pii[j].first >=0 )	dp[i] = max(dp[i], dp[i - pii[j].first] + pii[j].second);
		}
	}
	cout << dp[M] <<"\n";
}

void input() {
	double dM;
	while (cin >> N >> dM && dM != 0.0 && N != 0) {
		pii.resize(0);
		memset(dp, 0, sizeof(dp));
		M = dM * 100;
		for (int i = 0; i < N; i++) {
			int temp1; double temp2; cin >> temp1>> temp2;
			pii.push_back({ (int)(temp2 * 100 + 0.5) , temp1});
		}
		sort(pii.begin(), pii.end());
		solution();
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	queue<int> que;
	input();
	return 0;
}



