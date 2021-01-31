#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void input() {

}

void solution() {

}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    stringstream in(play_time);
    vector<int> vec;
    vector<pair<int, int>> vec;
    //로그 추출;
    for (auto& a : logs) {
        a[2] = a[5] = a[8] = a[11] = a[14] = ' ';
        stringstream in(a);
        int st[3] = { 0, }, end[3] = { 0, };
        for (int i = 0; i < 3; i++) in >> st[i];
        for (int i = 0; i < 3; i++) in >> end[i];
        vec.push_back({ st[0] * 3600 + st[1] * 60 + st[2],  end[0] * 3600 + end[1] * 60 + end[2] });
    }

    return answer;
}
