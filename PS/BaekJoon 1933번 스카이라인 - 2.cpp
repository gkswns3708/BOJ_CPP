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
	//�������� ���ϳ� �ִٰ� ����. �׷��� ������ ������ ���� down�ǰ� ��ġ�� ��ȯ��.
	vec.push_back({ INF,INF });
	//Multiset�� �ڷᱸ���� ���� ������ ���� ���� ���� � ���� �ڷḸ�� �ʿ�� �ϴ� MAP�� ���� 
	//�׸��� ���� �ڸ��� ���� ������ ���簡��.
	//���� ���� ������� buliding���� multiset�� �ִٰ� �����ϸ� �� ��.
	multiset<int> S;
	S.insert(0);//0��°�� ��ġ�� 0���� ������. �׷��� ��ġ�� ��ȭ�ϸ� �ٷ� �ν��� �� �ֵ���
	int prex = vec[0].first;
	int prey = -1;
	for (int i = 0; i < 2 * N;) {
		while (prex == vec[i].first) {
			auto [nx, ny] = vec[i];
			//���̰� -y�� ��ġ�� �����ϰ� �Ǹ� ���̰� y��ġ���� ������ ������.
			//�׷� �߻�.
			if (ny < 0) S.erase(S.find(-ny));
			else S.insert(ny);
			i++;
		}
		//X��ǥ������ ó���ϴ� �� ����.
		//�׷��� ���� ������� ���̸� ���� buliding�� ����鼭 �� ��ġ �� �ְ���̸� ��� �����.
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