#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXNUM 1000001

int n, m, mintime = MAXNUM;
vector<int> staff;

long long binary_search(long long s, long long e) {
    if (s > e) return -1;
    long long mid = (s + e) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mid / staff[i];
    }

    if (sum >= m) {
        long long candidtae = binary_search(s, mid - 1);
        if (candidtae != -1 && candidtae < mid) {
            return candidtae;
        }
        else {
            return mid;
        }
    }
    return binary_search(mid + 1, e);
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        int time;
        scanf("%d", &time);
        if (mintime > time) mintime = time;
        staff.push_back(time);
    }

    long long upper_bound = (long long)mintime * (long long)m;
    long long answer = binary_search(0, upper_bound);

    printf("%lld\n", answer);

    return 0;
}