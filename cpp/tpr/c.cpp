#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
random_device rd;
mt19937 rg(rd());
int chk[2000];
int n;
int ans;
int a[2000];
int geta(){
	int ret=0;
	int i=0;
	for(;chk[i];i++);
	ret=a[i];
	for(i=i+1;i<n;i++) if(chk[i]==0) ret=__gcd(a[i],ret);
	return ret;
}
void sa(){
	double tp=3000,ed=1e-7,low=0.98;
	for(;tp>ed;tp*=low){
		int x=rg()%n;
		int y=rg()%n;
		swap(chk[x],chk[y]);
		int nw=geta();
		if(nw>ans) ans=nw;
		else if(exp((nw-ans)/tp)<(double(rg())/(rg.max()+1)))
			swap(chk[x],chk[y]);
	}
}
signed main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	chk[0]=chk[1]=1;
	while(double(clock())/CLOCKS_PER_SEC<0.85) sa();
	cout<<ans<<'\n';
}	
