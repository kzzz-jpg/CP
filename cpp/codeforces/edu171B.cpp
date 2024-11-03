#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int> a(n),b,c;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==1) {
		cout<<1<<'\n';
		return;
	}
	if(n==2){
		cout<<(a[1]-a[0])<<'\n';
		return ;
	}
	for(int i=0;i<n;i+=2) {
		b.push_back(a[i+1]-a[i]);
	}
	if(n&1) b.push_back(1);
	sort(b.begin(),b.end(),greater<int>());
	cout<<b[1]<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}

/*


1
1
1
2
2
1 2
1
3
2
1 3
2
2 3
3
1 2 3
1
4
2
1 4
2
2 4
3
1 2 4
2
3 4
3
1 3 4
3
2 3 4
4
1 2 3 4
1
5
2
1 5
2
2 5
3
1 2 5
2
3 5
3
1 3 5
3
2 3 5
4
1 2 3 5
2
4 5
3
1 4 5
3
2 4 5
4
1 2 4 5
3
3 4 5
4
1 3 4 5
4
2 3 4 5
5
1 2 3 4 5
1
6
2
1 6
2
2 6
3
1 2 6
2
3 6
3
1 3 6
3
2 3 6
4
1 2 3 6
2
4 6
3
1 4 6
3
2 4 6
4
1 2 4 6
3
3 4 6
4
1 3 4 6
4
2 3 4 6
5
1 2 3 4 6
2
5 6
3
1 5 6
3
2 5 6
4
1 2 5 6
3
3 5 6
4
1 3 5 6
*/