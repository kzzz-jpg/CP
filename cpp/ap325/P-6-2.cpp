#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
inline char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
inline int nextint() {
	int x = 0, c = getchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = getchar();
	if(c == '-') neg = true, c = getchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = getchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}
int main() {
	fast;
	int n;
	n=nextint();
	vector<int> dp(n + 1, 0);
	vector<int> val(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		val[i]=nextint();
	}
	dp[1] = val[1];
	dp[2] = max(val[2], dp[1]);
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i-1], dp[i-2]+val[i]);
	}
	cout << dp[n] << endl;;
	return 0;
}