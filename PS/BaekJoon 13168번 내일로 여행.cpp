#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define INF 987654321
#define pii pair<int,int>
#define int long long int
using namespace std;

int N, R, M, K;
map<string, int> mp;
map<int, string> mp2;
double dist[100 + 1][100 + 1][2+1];
vector<int> travel;

bool floyd_washall() {
	for (int TC = 0; TC <= 1; TC++) {
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (dist[i][k][TC] == INF || dist[k][j][TC] == INF) continue;
					dist[i][j][TC] = min(dist[i][j][TC], dist[i][k][TC] + dist[k][j][TC]);
				}
			}
		}
	}

	double ans = 0, N_ans = 0;
	for (int i = 1; i < M; i++) {
		int from, to;
		from = travel[i - 1],to = travel[i];
		ans += dist[from][to][0];
		N_ans += dist[from][to][1];
	}
	return N_ans + R < ans;
}


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> R;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		mp[s] = i;
		mp2[i] = s;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		travel.push_back(mp[s]);
	}
	cin >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j][0] = 0,dist[i][j][1] = 0;
			else dist[i][j][0] = INF,dist[i][j][1] = INF;
		}
	}
	for (int i = 0; i < K; i++) {
		string tp, from, to; double cost; cin >> tp >> from >> to >> cost;
		dist[mp[to]][mp[from]][0] = min(dist[mp[to]][mp[from]][0], cost);
		dist[mp[to]][mp[from]][1] = min(dist[mp[to]][mp[from]][1], cost);
		dist[mp[from]][mp[to]][0] = min(dist[mp[from]][mp[to]][0], cost);
		dist[mp[from]][mp[to]][1] = min(dist[mp[from]][mp[to]][1], cost);
		if (tp == "ITX-Saemaeul" || tp == "ITX-Cheongchun" || tp == "Mugunghwa") {
			dist[mp[from]][mp[to]][1] = 0;
			dist[mp[to]][mp[from]][1] = 0;
		}
		else if (tp == "S-Train" || tp == "V-Train") {
			dist[mp[from]][mp[to]][1] = min(dist[mp[from]][mp[to]][1], cost / 2);
			dist[mp[to]][mp[from]][1] = min(dist[mp[to]][mp[from]][1], cost / 2);
		}
	}

	floyd_washall() ? cout << "Yes" : cout << "No";

	return 0;
}