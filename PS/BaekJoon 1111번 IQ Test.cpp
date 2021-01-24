#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> vec;
int N;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp; vec.push_back(temp);
	}
}

void solution() {
	int ans;
	int a, b;
	bool check = false;
	if (N == 1) cout << "A";
	else if (N == 2) {
		if (vec[0] == vec[1]) cout << vec[0];
		else cout << "A";
	}
	else {
		if (vec[0] == vec[1]) {
			int temp = vec[0];
			for (auto now : vec) 
				if (temp != now) {
					check = true;
					break;
				}
			if (check) cout << "B";
			else cout << vec[0];
		}
		else {
			if (vec[1] == vec[2]) {
				a = 0;
				b = vec[1];
			}
			else {
				if ((vec[1] - vec[2]) % (vec[0] - vec[1]) != 0)	check = true;
				else {
					a = (vec[1] - vec[2]) / (vec[0] - vec[1]);
					b = vec[1] - a * vec[0];
				}
			}	
			if (!check) for (int i = 3; i < N; i++) if (vec[i] != vec[i - 1] * a + b) check = true;
			if (check) cout << "B";
			else cout << vec[N - 1] * a + b;
		}		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}
