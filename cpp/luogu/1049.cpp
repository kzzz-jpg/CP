#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t,v;
bitset<300000> bs;
signed main(){
	cin>>v>>n;
	bs[0]=1;
	for(int i=0;i<n;i++){
		cin>>t;
		bs|=bs<<t;
	}
	int ans;
	for(int i=v;i>=0;i--) if(bs[i]) {ans=i;break;}
	cout<<v-ans<<'\n';
}
