#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> vec1(N + 5);
    vector<pair<double, int>> vec2;
    for (auto a : stages) vec1[a]++;
    int sum = stages.size(), now = 0;
    for (int i = 1; i <= N; i++) {
        now += vec1[i];
        if (sum == 0) vec2.push_back({ 0,i });
        else vec2.push_back({ (1.0*vec1[i]) / (1.0*sum) , i});
        sum -= vec1[i];
    }
    sort(vec2.begin(), vec2.end(), [&](pair<double, int> a, pair<double, int> b) {
        if (a.first != b.first) return a.first > b.first;
        else return a.second < b.second;
        });
    for (pair<double, int> a : vec2) answer.push_back(a.second);  
    return answer;

}

int main() {
    vector<int> stages = { 2, 1, 2, 2, 2, 4, 3, 3 };
    vector<int> ans = solution(5,stages);
    for (auto a : ans)
        cout << a << " ";
    return 0;
}