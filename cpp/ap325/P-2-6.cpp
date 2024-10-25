#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
int main() {
	int m, n, k, t;
	cin >> m >> n >> k;
	set<int> A;
	set<int> B;
	for (int i = 0; i < m; i++) {
		cin >> t;
		A.insert(t);
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		B.insert(t);
	}
	int sum=0;
	for (auto &x : A) {
		if (B.count(k-x)) {
			sum++;
		}
	}
	cout << sum << endl;
return 0;
}