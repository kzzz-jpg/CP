#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
using namespace std;
vector<int> b;
long long func(long long x,long long y,long long p) {
	if (y == 0) return 1;
	if (y & 1) return (func(x, y - 1, p) * x) % p;
	long long t = func(x, y / 2, p);
	return (t*t)%p;
}
int main() {
	fast
	long long x, y, p;
	cin >> x >> y >> p;
	cout << func(x, y, p) << endl;
	return 0;
}