#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;

int make_num(int num) {
	int cnt = 1;
	int ret = num%10;
	while (int tempnum = num / int(pow(10, cnt++))) ret += tempnum % 10;
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num; cin >> num;
	
	
	
	int maxvalue = -1, minvalue = 987654321;
	
	function <pii(int)> solution = [&](int num)-> pii {
		if (num < 10) return num % 2 ? make_pair(1, 1) : make_pair(0, 0);
		else if (num < 100) {
			int cnt = 0;
			if (num % 10)cnt++;
			if ((num / 10) % 10)cnt++;
			pair nxt = solution(num % 10 + (num / 10) % 10);
			return { nxt.first+cnt , nxt.second+cnt };
		}
	};
	
	int num;
	return 0;
}