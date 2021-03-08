#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N;
vector<int> weight;
vector<int> prefix_sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	weight.resize(N);
	prefix_sum.resize(N+1);
	for (int i = 0; i < N; i++) cin >> weight[i];
	sort(weight.begin(), weight.end());
	for (int i = 1; i <= N; i++) prefix_sum[i] = prefix_sum[i - 1] + weight[i-1];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (prefix_sum[i] + 1 < weight[i]) {
			cout << prefix_sum[i] + 1;
			return 0;
		}
	}
	cout << prefix_sum[N] + 1;
	return 0;
}