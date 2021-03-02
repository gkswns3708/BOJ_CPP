#include <bits/stdc++.h>
#define INF 1000000000+1
using namespace std;

const int SZ = 1 << 20;
char read_buf[SZ], write_buf[SZ];

namespace IO {
	int read_idx, next_idx, write_idx;
	inline bool is_blank(char c) { return c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r'; }
	inline bool is_end(char c) { return c == '\0'; }
	inline char readChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	inline int readInt() {
		int ret = 0;
		char cur = readChar();
		bool flag = 0;
		while (is_blank(cur)) cur = readChar();
		if (cur == '-') {
			flag = 1;
			cur = readChar();
		}
		while (!is_blank(cur) && !is_end(cur)) {
			ret = 10 * ret + cur - '0';
			cur = readChar();
		}
		return flag ? -ret : ret;
	}
	inline long long readLL() {
		long long ret = 0;
		char cur = readChar();
		bool flag = 0;
		while (is_blank(cur)) cur = readChar();
		if (cur == '-') {
			flag = 1;
			cur = readChar();
		}
		while (!is_blank(cur) && !is_end(cur)) {
			ret = 10 * ret + cur - '0';
			cur = readChar();
		}
		return flag ? -ret : ret;
	}
	inline string readString() {
		string ret;
		char cur = readChar();
		while (is_blank(cur)) cur = readChar();
		while (!is_blank(cur) && !is_end(cur)) {
			ret.push_back(cur);
			cur = readChar();
		}
		return ret;
	}
	template <typename T>
	inline int getSize(T n) {
		int ret = 1;
		if (n < 0) n = -n;
		while (n >= 10) {
			ret++;
			n /= 10;
		}
		return ret;
	}
	inline void bflush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	inline void writeChar(char c) {
		if (write_idx == SZ) bflush();
		write_buf[write_idx++] = c;
	}
	inline void newLine() { writeChar('\n'); }
	inline void writeInt(int n) {
		int sz = getSize(n);
		if (write_idx + sz >= SZ) bflush();
		if (n < 0) {
			write_buf[write_idx++] = '-';
			n = -n;
		}
		for (int i = sz - 1; i >= 0; i--) {
			write_buf[write_idx + i] = n % 10 + '0';
			n /= 10;
		}
		write_idx += sz;
	}
	inline void writeLL(long long n) {
		int sz = getSize(n);
		if (write_idx + sz >= SZ) bflush();
		if (n < 0) {
			write_buf[write_idx++] = '-';
			n = -n;
		}
		for (int i = sz - 1; i >= 0; i--) {
			write_buf[write_idx + i] = n % 10 + '0';
			n /= 10;
		}
		write_idx += sz;
	}
	inline void writeString(string s) {
		for (auto& c : s) writeChar(c);
	}
}
using namespace IO;

int N, D, ST;
vector<pair<int, int>> edge[10000 + 10];
int costarr[10000 + 10];

void input() {
	N = readInt();
	D = readInt();
	ST = readInt();
	//assert(N >= 15000);
	for (int i = 1; i <= N; i++) edge[i].clear(), costarr[i] = INF;
	for (int i = 1; i <= D; i++) {
		int from, to, cost;
		from = readInt();
		to = readInt();
		cost = readInt();
		edge[to].push_back({ from,cost });
	}
}

void solution() {
	queue<pair<int,int>> que;
	que.push({ 0,ST });
	costarr[ST] = 0;
	while (!que.empty()) {
		auto [ncost, npos] = que.front();
		que.pop();
		for (auto nxt : edge[npos]) {
			auto [nxtpos, nxtcost] = nxt;
			if (costarr[nxtpos] > nxtcost + ncost) {
				que.push({ ncost + nxtcost, nxtpos});
				costarr[nxtpos] = ncost + nxtcost;
			}
		}
	}
	int cnt = 0;
	int lasttime = 0;
	for (int i = 1; i <= N; i++) if (costarr[i] != INF) {
		cnt++;
		lasttime = max(lasttime, costarr[i]);
	}

	writeString(to_string(cnt) + ' ');
	writeInt(lasttime);
	newLine();
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int TC; TC = readInt();
	while (TC--) {
		input();
		solution();
	}
	bflush();
	return 0;
}