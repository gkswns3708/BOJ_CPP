#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;
int N;
int arr[1001];
int pos, len;
int first = 1001, last, longestpos;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    while (N--)
    {
        cin >> pos >> len;
        arr[pos] = len;
        if (last < pos) last = pos;
        if (first > pos) first = pos;
        if (len > arr[longestpos]) longestpos = pos;
    }

    for (int i = first; i <= longestpos; i++)
    {
        if (arr[i])
        {
            if (stk.empty()) stk.push(arr[i]);
            else if (arr[i] > stk.top()) stk.push(arr[i]);
        }
        ans += stk.top();
    }

    while (!stk.empty()) stk.pop();

    for (int i = last; i > longestpos; i--)
    {
        if (arr[i])
        {
            if (stk.empty()) stk.push(arr[i]);
            else if (arr[i] > stk.top()) stk.push(arr[i]);
        }
        ans += stk.top();
    }

    cout << ans;

    return 0;
}
