#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		vec.push_back(temp);
	}


	return 0;
}