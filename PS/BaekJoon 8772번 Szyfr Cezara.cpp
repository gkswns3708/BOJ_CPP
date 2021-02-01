#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string s;
char t;
void input() {
	int n; 
	cin >> n >> s >> t; 
}

void solution() {
	cout << t;
	int gap = s[0] - t;
	for (int i = 1; i < s.size(); i++) {
		int now = (s[i] - gap - 'a');
		if (now < 0)now += 26;
		cout << char( (now % 26) + 'a');
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int TC; cin >> TC;
	while(TC--){
		input();
		solution();
	}
	return 0;
}