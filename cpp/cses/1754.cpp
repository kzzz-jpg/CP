#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e9+7;
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(b>a) swap(a,b);
		int t=a-b;
		a-=2*t;
		b-=t;
		if(a>=0&&a%3==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
