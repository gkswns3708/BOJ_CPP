#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
using namespace std;
typedef long long int ll;

bool isp[100000000];
vector<ll> p;
void linear_sieve(int n)
{
	memset(isp, 1, sizeof isp);
	for (int i = 2; i <= n; i++)
	{
		if (isp[i]) {
			p.push_back(i);
		}
		int size = p.size();
		for (int j = 0 ; j < size;j++)
		{
			if (i * p[j] > n) break;
			isp[i * p[j]] = 0;
			if (i % p[j] == 0) break;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int pre = GetTickCount();
	int temp; cin >> temp;
	linear_sieve(temp);
	int now = GetTickCount();
	cout <<now <<" " << pre<<" "<< pre - now;

	return 0;
}
//3천만 11578 - if 없을 때
//3천만 8141 - if 있을 때 