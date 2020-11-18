#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> vec;
int SIZE;

//합 업데이트
void Update(int x,int v) {
	x += SIZE - 1;
	vec[x] = v;
	for (x /= 2; x >= 1; x /= 2) {
		vec[x] = vec[2 * x] + vec[x * 2 + 1];
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//vec.resize();

	return 0;
}