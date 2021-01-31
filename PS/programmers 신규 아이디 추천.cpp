#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string s;

void input() {
	cin >> s;
}

string solution(string new_id) {
	string answer = "";
	string temp = "";
	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
			new_id[i] = tolower(new_id[i]);
		}
	}
	//cout << new_id << "1\n";
	for (int i = 0; i < new_id.size(); i++) {
		if (!((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) {
			new_id.erase(i--, 1);
			continue;
		}
	}
	//cout << new_id<<"2\n";
	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] == '.' && new_id[i + 1] == '.') {
			new_id.erase(i--, 1);
		}
	}
	//cout << new_id << "3\n";
	if (new_id[0] == '.') {
		new_id.erase(0,1);
	}
	if (!new_id.empty()&&new_id.back() == '.') {
		new_id.erase(new_id.size()-1,1);
	}
	//cout << new_id << "4\n";
	if (new_id.empty()) {
		new_id = "a";
	}
	//cout << new_id << "5\n";
	if (new_id.size() >= 16) {
		new_id = new_id.substr(0,15);
		if (new_id.back() == '.') new_id.pop_back();
	}
	//cout << new_id << "6\n";
	if (new_id.size() <= 2) {
		while (new_id.size() < 3) {
			new_id.push_back(new_id.back());
		}
	}
	//cout << new_id << "7\n";
	//cout << new_id;
	return new_id;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	input();
	solution(s);
	return 0;
}