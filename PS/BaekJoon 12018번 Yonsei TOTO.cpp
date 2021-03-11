#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 



int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;  cin >> N >> M;
	vector<int> ans;
	for (int TC = 0; TC < N; TC++) {
		int P, L; cin >> P >> L;
		vector<int> vec(P);
		for (int i = 0; i < P; i++) cin >> vec[i];
		if (L > P) {
			ans.push_back(1);
			continue;
		}
		sort(vec.begin(), vec.end(), [](int a, int b) {return a > b; });
		ans.push_back({ vec[L - 1] });
	}
	sort(ans.begin(), ans.end());
	int cnt = 0;
	for (auto now : ans) {
		if (M >= now) {
			M -= now;
			cnt++;
		}
		else break;
	}
	cout << cnt;
}