#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector<int> lis;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		if (lis.empty()) lis.push_back(temp);
		else if (lis.back() < temp) lis.push_back(temp);
		else *lower_bound(lis.begin(), lis.end(), temp) = temp;
	}
	cout << lis.size();
	return 0;
}