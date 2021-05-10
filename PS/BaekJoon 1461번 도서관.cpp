#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N,M; cin >> N >> M;
	vector<int> vec,vec1;
	for (int i = 0; i < N; i++){
		int a; cin >> a; 
		if (a > 0) vec.push_back(a);
		else if (a == 0) continue;
		else vec1.push_back(-a);
	}
	bool flag = false, flag1 = false;
	sort(vec.begin(),vec.end(),less());
	sort(vec1.begin(),vec1.end(),less());


	int ans = -(max(vec.empty() ? 0 : vec[vec.size() - 1], vec1.empty() ? 0 :vec1[ vec1.size() - 1]));

	while (M < vec.size()) {
		ans += 2*vec[vec.size() - 1];
		for (int i = 0; i < M; i++) vec.pop_back();
	}
	while (M < vec1.size()) {
		ans += 2*vec1[vec1.size() - 1];
		for (int i = 0; i < M; i++) vec1.pop_back();
	}

	int vec1value = vec1.empty() ? 0 : vec1[vec1.size() - 1];
	int vecvalue = vec.empty() ? 0 : vec[vec.size() - 1];
	ans += vec1value * 2 + vecvalue * 2;
	cout << ans;

	return 0;
}