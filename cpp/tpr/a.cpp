#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int a,b,k;
	cin>>a>>b>>k;
	for(int i=-3000;i<=3000;i++){
		if(abs(abs(a-i)-abs(b-i))==k){
			cout<<i<<'\n';
			return 0;
		}
	}
	cout<<1000000001<<'\n';
}
