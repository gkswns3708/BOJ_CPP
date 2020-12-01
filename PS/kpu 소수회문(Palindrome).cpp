#include <bits/stdc++.h>
using namespace std;
bool arr[2000000 + 3];
vector<int> vec;
void makeprime() {
	for (int i = 2; i<= 1003002/2; i++) {
		if (!arr[i]) {
			for (int j = 2; i * j <= 1003002; j++) {
				arr[i * j] = true;
			}
		}
	}
	for (int i = 2; i <= 1003002; i++) {
		if (!arr[i]) vec.push_back(i);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool arr[1000000 + 1] = { 0, };
	int N; cin >> N;
	makeprime();
	vector<int> ans;
	for (auto a: vec) {
		string nstr = to_string(a);
		string pstr = nstr;
		reverse(pstr.begin(),pstr.end());
		if (nstr == pstr){
			ans.push_back(a);
		}
	}
	cout <<*lower_bound(ans.begin(),ans.end(), N);
	
	return 0;
}