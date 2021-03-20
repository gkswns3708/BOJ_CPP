#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#define int long long int
using namespace std;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stringstream ss;
	int N; cin >> N;
	vector<int> vec(N);
	vector<pair<int, int>> times(N);
		cin.ignore();
	for (int i = 0; i < N; i++) {
		string now;
		getline(cin, now);
		for (int i = 0; i < now.size(); i++) {
			if (now[i] >= '0' && now[i] <= '9') continue;
			else now[i] = ' ';
		}
		ss.clear();
		ss << now;
		int h1, m1, h2, m2;
		ss >> h1 >> m1 >> h2 >> m2;
		//cout << h1 << " " << m1 << " " << h2 << " " << m2 << "\n";
		times[i] = { h1 * 60 + m1, h2 * 60 + m2 };
	}

	int start = 0;
	int last = 23 * 60 + 59;
	for (int i = 0; i < N; i++) {
		auto [ns, ne] = times[i];
		start = max(start, ns);
		last = min(last, ne);
	}

	if (start >= last) cout << -1;
	else {
		if (start / 60 < 10) cout << 0;
		cout << start / 60;
		cout << ":";
		if (start % 60 < 10) cout << 0;
		cout << start % 60 << " ~ ";
		if (last / 60 < 10) cout << 0;
		cout << last / 60 << ":";
		if (last % 60 < 10) cout << 0;
		cout <<  last % 60;
	}

	//if(start % 60 << " ~ " << last / 60 << ":" << last % 60;

	return 0;
}