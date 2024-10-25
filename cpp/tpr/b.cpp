#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
random_device rd;
mt19937 rg(rd());
int x1,x2,ya,yb;
int k;
int ansx,ansy,ans=1e15;
int nwx,nwy;
int geta(int x,int y){
	return abs(k-abs(abs(x-x1)-abs(x-x2))+abs(abs(y-ya)-abs(y-yb)));
}
void sa(){
	double tp=3000,ed=1e-7,low=0.98;
	for(;tp>ed;tp*=low){
		int idx=(rg()*2-rg.max())*tp,idy=(rg()*2-rg.max())*tp;
		nwx+=idx,nwy+=idy;
		int nw=geta(nwx,nwy);
		if(nw<ans) ansx=nwx,ansy=nwy,ans=nw;
		else if(exp((ans-nw)/tp)<(double(rg())/(rg.max()+1)))
			nwx-=idx,nwy-=idy;
	}
}
signed main(){
	cin>>x1>>x2;
	cin>>ya>>yb;
	cin>>k;
	while(double(clock())/CLOCKS_PER_SEC<0.85) sa();
	cout<<ansx<<' '<<ansy<<'\n';
}
