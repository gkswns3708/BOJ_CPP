#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;
int N;
char arr[5000 + 1];
int ans[5000 + 1][5000 + 1];
void input() {
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	memset(ans, -1, sizeof(ans));
}

int solution(int start, int end) {
	if (start > end) return 0;

	int& answer = ans[start][end];
	if (answer != -1) return answer;
	if (arr[start] == arr[end])//조건 충족한다면
		answer = solution(start + 1, end - 1);
	else answer = min(solution(start + 1, end), solution(start, end - 1)) + 1;

	return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	cout << solution(0, N - 1);
	return 0;
}
