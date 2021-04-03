#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T;
	int N, M, K, H;
	int X, Y;

	cin >> T;

	vector<int> v(T);

	for (int i = 0; i < T; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cin >> T;

	vector<int> answer(T);

	for (int i = 0; i < T; i++)
	{
		cin >> K;
		vector<int>::iterator upper = upper_bound(v.begin(), v.end(), K);
		auto lower = lower_bound(v.begin(), v.end(), K);
		answer[i] = upper - lower;
	}

	for (auto n : answer)
	{
		cout << n << " ";
	}

	return 0;
}