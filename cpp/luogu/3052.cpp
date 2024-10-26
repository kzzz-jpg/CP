#include<bits/stdc++.h>
using namespace std;
#define int long long
struct ev{
	int ti,pe;
	ev(int t=1e15,int p=1e15):ti(t),pe(p){}
	bool operator< (ev o) const{
		if(ti==o.ti) return pe<o.pe;
		return ti<o.ti;
	}
} dp[1<<19];
int w,a[20],n;
signed main(){
	cin>>n>>w;
	for(int i=0;i<n;i++) cin>>a[i];
	dp[0]=ev(1,0);
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			ev nw;
			if(i&(1<<j)){
				nw=dp[i&(~(1<<j))];
				if(nw.pe+a[j]>w) nw.ti++,nw.pe=a[j];
				else nw.pe+=a[j];
			}
			dp[i]=min(dp[i],nw);
		}
	}
	cout<<dp[(1<<n)-1].ti<<'\n';
}
