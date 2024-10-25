#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,g;
int mn=0,mx=0;
int mmn[10050],mmx[10050];
void solve(){
	cin>>l>>n;
	int nn=n;
	while(n--){
		cin>>g;
		mmn[n]=min({l-g+1,g});
		mmx[n]=max({l-g+1,g});
	}
	for(int i=0;i<nn;i++){
		mx=max(mmx[i],mx);
		mn=max(mmn[i],mn);
	}
	cout<<mn<<' '<<mx<<'\n';
}
signed main(){
	int t=1;
	while(t--) solve();
}
