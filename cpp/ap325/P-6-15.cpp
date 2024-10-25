#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
int main() {
	fast;
	int n;
	vector<int> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		auto it = lower_bound(ans.begin(), ans.end(), a);
		if (it == ans.end()) ans.push_back(a);
		else *it = a;
	}
	cout << ans.size()<<endl;
	return 0; 
}