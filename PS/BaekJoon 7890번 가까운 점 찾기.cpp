#include <bits/stdc++.h>
#define int int64_t
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

struct Node {
	pii pt;
	bool flag; //standard. false면 x좌표 비교, true면 y좌표 비교
	int sx, ex, sy, ey;
};

Node kdtree[500000 + 1];

bool is_exist[500000 + 1];
pii save_temp[100000 + 1];
pii point[100000 + 1];
int ans;
int square(int a) {
	return a * a;
}

bool xcmp(pii a, pii b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

bool ycmp(pii a, pii b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void maketree(int l, int r, int idx) {
	int minx = 2e9, maxx = -2e9, miny = 2e9, maxy = -2e9;
	for (int i = l; i <= r; i++) {
		minx = min(minx, point[i].first);
		maxx = max(maxx, point[i].first);
		miny = min(miny, point[i].second);
		maxy = max(maxy, point[i].second);
	}
	kdtree[idx].sx = minx;
	kdtree[idx].ex = maxx;
	kdtree[idx].sy = miny;
	kdtree[idx].ey = maxy;
	// cout << idx << " " << minx << " " << maxx << " " << miny << " " << maxy << "\n";
	is_exist[idx] = true;
	if (idx == 1) kdtree[idx].flag = false; // 루트노드는 x좌표를 비교하게 설정함.
	else kdtree[idx].flag = !kdtree[idx / 2].flag;

	if (kdtree[idx].flag) sort(point + l, point + r + 1, ycmp);
	else sort(point + l, point + r + 1, xcmp);

	int mid = (l + r) / 2;
	kdtree[idx].pt = point[mid];
	//재귀로 들어온 위치를 현재 kdtree 서브트리의 root의 점으로 저장(정확한 root는 제일 처음 선언에만 적용됨)
	if (l <= mid - 1) maketree(l, mid - 1, idx * 2);
	if (mid + 1 <= r) maketree(mid + 1, r, idx * 2 + 1);
}

void getans(int idx, pii now) {
	if (now != kdtree[idx].pt) ans = min(ans, square(kdtree[idx].pt.first - now.first) + square(kdtree[idx].pt.second - now.second));
	// 유의해야 할 점은 존재하지 않는 노드로는 들어가면 안됨
	if (kdtree[idx].flag) { // y좌표 기준으로 비교하는 level인 경우
		if (now.second < kdtree[idx].pt.second) {
			if (is_exist[idx * 2]) getans(idx * 2, now);
			if (is_exist[idx * 2 + 1] && square(kdtree[idx * 2 + 1].sy - now.second) < ans)  getans(idx * 2 + 1, now);
		}
		else {
			if (is_exist[idx * 2 + 1]) getans(idx * 2 + 1, now);
			if (is_exist[idx * 2] && square(kdtree[idx * 2].ey - now.second) < ans)  getans(idx * 2, now);
		}
	}
	else {
		if (now.first < kdtree[idx].pt.first) {
			if (is_exist[idx * 2]) getans(idx * 2, now);
			if (is_exist[idx * 2 + 1] && square(kdtree[idx * 2 + 1].sx - now.first) < ans) getans(idx * 2 + 1, now);
		}
		else {
			if (is_exist[idx * 2 + 1]) getans(idx * 2 + 1, now);
			if (is_exist[idx * 2] && square(kdtree[idx * 2].ex - now.first) < ans) getans(idx * 2, now);
		}
	}
}


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		memset(is_exist, 0, sizeof(is_exist));
		int N; cin >> N;
		vector<pii> vec;
		for (int i = 0; i < N; i++) {
			int x, y; cin >> x >> y;
			vec.push_back({ x, y });
			save_temp[i] = vec[i];
		}
		sort(vec.begin(), vec.end(), xcmp);
		vector<pii> set_temp;
		point[0] = vec[0];
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			if (vec[i - 1] != vec[i]) point[cnt++] = vec[i];
			else set_temp.push_back(vec[i]);
		}
		maketree(0, cnt - 1, 1);
		for (int i = 0; i < N; i++) {
			if (!set_temp.empty() && *lower_bound(set_temp.begin(), set_temp.end(), save_temp[i]) == save_temp[i]) cout << "0\n"; // TODO : 여기 채우기
			else {
				ans = 4e18 + 1;
				getans(1, save_temp[i]);
				cout << ans << "\n";
			}
		}
	}
	return 0;
}