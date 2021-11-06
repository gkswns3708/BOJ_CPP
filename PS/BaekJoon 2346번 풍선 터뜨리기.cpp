#include <cstdio>
#include <list>
#include <utility>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    list<pair<int, int> > ll;
    for (int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        ll.push_back(make_pair(t, i + 1));
    }

    list<pair<int, int> >::iterator it = ll.begin(), tmp;
    while (ll.size()) {
        int tt = (*it).first;
        printf("%d ", (*it).second);

        tmp = it;
        it--;
        ll.erase(tmp);
        if (it == ll.end()) it--;

        if (tt > 0) {
            for (int i = 0; i < tt; i++) {
                it++;
                if (it == ll.end()) it++;
            }
        }
        else if (tt < 0) {
            tt++; tt = -tt;
            for (int i = 0; i < tt; i++) {
                it--;
                if (it == ll.end()) it--;
            }
        }
    }

    return 0;
}