#include<iostream>
#include<algorithm>
using namespace std;
//���ο� copy�ڵ��Դϴ�.
int t, len[2], a[30001], b[30001], fa[2][30001], num[2][30001];
bool flag;
string s[2];

void findd(int u)
{
	int now = -1;
	for (int i = 1; i <= len[u]; i++) {
		//�Ʒ��� �������� �ڵ�
		if (s[u][i] == '0')	fa[u][i] = now, now = i;
		//���� ����ϴ� �ڵ�(�� ����ؼ� root�� ��ȭ�ϸ鼭 ������ ������.)
		else now = fa[u][now];
	}
}

void cal(int u)
{
	int now = -1;
	for (int i = 1; i <= len[0]; i++) {
		if (s[u][i] = '1'){
			now = i;
			while (now != -1)num[u][now]++,now = fa[u][now];
		}
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		flag = 0;
		cin >> s[0] >> s[1]; 
		//if (s[0].length() != s[1].length()){
		//	cout << "0\n"; continue;
		//}
		//���� �ڼյ��� -1�� ����Ű�� �ʱ�ȭ
		memset(fa[0], -1, sizeof(fa[0]));
		memset(fa[1], -1, sizeof(fa[1]));

		memset(num[0], 0, sizeof(num[0]));
		memset(num[1], 0, sizeof(num[1]));
		findd(0); 
		cal(0); 
		findd(1); 
		cal(1);
		sort(num[0] + 1, num[0] + len[0] + 1);
		sort(num[1] + 1, num[1] + len[1] + 1);
		for (int i = 1; i <= len[0]; i++)
			//������ �ִ� ������ �޶����� error
			if (num[0][i] != num[1][i]){
				cout << "0\n"; 
				flag = 1; break;
			}
		if (!flag) cout << "1\n";
	}
	return 0;
}
