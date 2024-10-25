#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
using namespace std;
vector<int> b;
void func(vector<int> f) {
	sort(f.begin(), f.end());
	b.push_back(f[0]);
	for (int i = 1; i < f.size(); i++) {
		if (f[i] != f[i - 1])b.push_back(f[i]);
	}
	return;
}
int main() {
	fast
	int n;
	cin >> n;
	vector<int> f(n);
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	func(f);
	for (int i = 0; i < n; i++) {
		cout << lower_bound(b.begin(), b.end(), f[i]) - b.begin() << " ";
	}
	cout << endl;
	return 0;
}