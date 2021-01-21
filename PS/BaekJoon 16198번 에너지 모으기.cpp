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

void DFS(vector<int> td, int value) {
	int size = td.size();
	if (size == 2) {
		ans = max(ans,value);
		return;
	}
	
	for (int i = 1; i < size - 1; i++) {
		int temp = td[i];
		vector<int>::iterator iterpos = td.begin();
		int tempvalue = td[i - 1] * td[i + 1];
		td.erase(iterpos + i, iterpos + i +1);
		DFS(td, value + tempvalue);
		td.insert(iterpos + i, temp);
	}

}

void solution() {
	DFS(vec,0);
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