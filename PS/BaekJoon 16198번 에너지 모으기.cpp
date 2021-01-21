#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string s;
vector<int> vec;
int N, ans = INT_MIN;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp; vec.push_back(temp);
	}
}

void DFS(int value) {
	int size = vec.size();
	if (size == 2) {
		ans = max(ans,value);
		return;
	}
	
	for (int i = 1; i < size - 1; i++) {
		int temp = vec[i];
		vector<int>::iterator iterpos = vec.begin();
		int tempvalue = vec[i - 1] * vec[i + 1];
		vec.erase(iterpos + i, iterpos + i +1);
		DFS(value + tempvalue);
		vec.insert(iterpos + i, temp);
	}

}

void solution() {
	DFS(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	cout << ans;
	return 0;
}