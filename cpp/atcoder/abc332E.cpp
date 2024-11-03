#include<bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 rg(rd());
int d,n,w[16];
int a[16];
int sum[16];
double avg,ans=999999999;
double getn(){
	double ret=0;
	for(int i=1;i<=d;i++) ret+=(sum[i]-avg)*(sum[i]-avg);
	return ret/d;
}
void sa(){
	double T=10000,ed=1e-7,low=0.991;
	for(;T>ed;T*=low){
		int id=rg()%n+1;
		int ori=a[id];
		a[id]=rg()%d+1;
		sum[ori]-=w[id];
		sum[a[id]]+=w[id];
		double nw=getn();
		if(nw<ans) ans=nw;
		else if(exp((ans-nw)/T)<(double(rg())/(rg.max()+1))){
			sum[a[id]]-=w[id];
			sum[ori]+=w[id];
			a[id]=ori;
		}
	}
}
signed main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		a[i]=rg()%d+1;
		sum[a[i]]+=w[i];
		avg+=w[i];
	}
	avg/=d;
	while(double(clock())/CLOCKS_PER_SEC<0.95) sa();
	cout<<fixed<<setprecision(8)<<ans<<'\n';
}
