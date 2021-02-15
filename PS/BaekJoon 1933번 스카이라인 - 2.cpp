#include<bits/stdc++.h>
#include <regex>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define INF (int)1e9+7
#define X first
#define Y second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T> istream& operator>> (istream& in, pair<T, T>& i) { in >> i.X >> i.Y; return in; }

int N;
vector<pii> vec;
map<int, int> mp;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int L, H, R; cin >> L >> H >> R;
		vec.push_back({ L,H });
		vec.push_back({ R,-H });
	}
}
void solution() {
	sort(all(vec));
	//마지막에 벽하나 있다고 생각. 그래야 마지막 빌딩의 끝이 down되고 위치가 변환함.
	vec.push_back({ INF,INF });
	//Multiset의 자료구조가 사용된 이유는 넓은 범위 속의 몇개 없는 자료만을 필요로 하는 MAP적 성향 
	//그리고 같은 자리에 여러 빌딩의 존재가능.
	//따라서 현재 고려중인 buliding들이 multiset에 있다고 생각하면 될 듯.
	multiset<int> S;
	S.insert(0);//0번째의 위치는 0으로 설정됨. 그래서 위치가 변화하면 바로 인식할 수 있도록
	int prex = vec[0].first;
	int prey = -1;
	for (int i = 0; i < 2 * N;) {
		while (prex == vec[i].first) {
			auto [nx, ny] = vec[i];
			//높이가 -y된 위치에 도달하게 되면 높이가 y위치였던 빌딩을 빼야함.
			//그런 발상.
			if (ny < 0) S.erase(S.find(-ny));
			else S.insert(ny);
			i++;
		}
		//X좌표순으로 처리하는 거 맞음.
		//그래서 현재 고려중인 높이를 가진 buliding을 지우면서 그 위치 중 최고높이를 계속 출력함.
		int val = *prev(S.end());
		if (val != prey) {
			cout << prex << ' ' << *prev(S.end()) << ' ';
			prey = val;
		}
		prex = vec[i].first;
	}	
}

int main() {
	fastio;
	input();
	solution();
}