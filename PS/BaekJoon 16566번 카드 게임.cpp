#pragma once 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool visited[4000000 + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, K; cin >> N >> M >> K;
	vector<int> vec;
	for (int i = 0; i < M; ++i) {
		int temp; cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < K; ++i) {
		int temp; cin >> temp;
		int idx = upper_bound(vec.begin(), vec.end(), temp) - vec.begin();
		//cout << *iterpos << "\n";
		//vec.erase(iterpos);
	}
	return 0;
}