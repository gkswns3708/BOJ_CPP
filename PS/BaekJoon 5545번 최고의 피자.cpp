#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	double A, B,C,ans,price,cal; cin >> A >> B >> C;
	ans = C / A,price = A,cal = C;
	vector<double> vec(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	sort(vec.begin(), vec.end(), greater<double>());
	for (int i = 0; i < N; i++) {
		price += B;
		cal += vec[i];
		if (ans < cal / price) ans = cal / price;
		else break;
	}
	cout << (int)ans;
	return 0;
}