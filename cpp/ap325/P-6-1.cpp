#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
int main() {
	fast;
	long long n;
	cin >> n;
	vector<long long> val(n + 1, 0);
	vector<long long> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	dp[1] = val[1];
	dp[2] = val[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 1], dp[i - 2]) + val[i];
	}
	cout << dp[n] << endl;
	return 0;
}