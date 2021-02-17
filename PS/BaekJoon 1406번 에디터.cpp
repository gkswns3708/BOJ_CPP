#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> s >> n;

	list <char> editor(s.begin(), s.end());
	list<char>::iterator cursor = editor.end();
	while (n--)
	{
		char cmd;
		cin >> cmd;

		if (cmd == 'L' && cursor != editor.begin())
		{
			cursor--;
		}
		else if (cmd == 'D' && cursor != editor.end())
		{
			cursor++;
		}
		else if (cmd == 'B' && cursor != editor.begin())
		{
			cursor--;
			cursor = editor.erase(cursor);
		}
		else if (cmd == 'P')
		{
			cin >> cmd;
			editor.insert(cursor, cmd);
		}
	}
	for (auto t : editor)
	{
		cout << t;
	}
	return 0;
}