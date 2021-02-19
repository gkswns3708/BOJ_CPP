#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[10000+1];

vector<int> vec;

int main()
{
	cin >> n >> k;
	vec.resize(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	arr[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = vec[i]; j <= k; j++) {
			if (j - vec[i] >= 0) arr[j] += arr[j - vec[i]];
		}
	}
	cout << arr[k];
}
//top-down
//bottom-up