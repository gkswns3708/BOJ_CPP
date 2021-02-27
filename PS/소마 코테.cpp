#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int M;
const int INF = 987654321;
vector<pair<int, int>> bus[501];
int value_arr[501] = { 0, };
bool cycle = false;

int bellman_ford(int excute_num)
{
	int isChanged = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int t = 1; t <= N; t++)
		{
			int busNum = bus[t].size();
			for (int k = 0; k < busNum; k++)
			{
				int new_val = (value_arr[t] + bus[t][k].second);
				int before_val = (value_arr[bus[t][k].first]);

				if ((value_arr[i] != INF) && (new_val < before_val)) {
					isChanged = 1;
					if (isChanged * excute_num) return isChanged;
					value_arr[bus[t][k].first] = new_val;
				}
			}
		}
	}
	return isChanged;
}

int main()
{
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		bus[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= N; i++) value_arr[i] = INF;

	value_arr[1] = 0;
	bellman_ford(0);

	if (bellman_ford(1) == 1) {
		cout << -1;
	}

	else {
		for (int i = 2; i <= N; i++)
			if (value_arr[i] != INF) cout << value_arr[i] << "\n";
			else cout << -1 << "\n";
	}
	return 0;
}