#include<bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 rg(rd());
int solve1(int n,int a[]){
	cerr<<1<<'\n';
	int pre[200500],mx[200500];
	int nw=0,ans=0;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i],mx[i]=max(pre[i],mx[i-1]);
	for(int i=1;i<=n;i++){
		ans=max(ans,nw+mx[i]);
		nw+=pre[i];
	}
	return ans;
}
int solve2(int n,int a[]){
	int nw=0,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			nw+=a[j];
			ans=max(ans,nw);
		}
	}
	return ans;
}
signed main(){
	/*
	for(int t=1;t<=20000;t++){
		if(t%1000==0) cout<<"successful : "<<t<<'\n';
		int n=200;
		int a[201];
		for(int i=1;i<=n;i++){
			a[i]=rg()%1000-rg()%1000;
		}
		int fr=solve1(n,a);
		int sc=solve2(n,a);
		if(fr!=sc) cout<<fr<<' '<<sc<<'\n';
	}*/
	int n,a[200500];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=solve2(n,a);
	cout<<ans<<'\n';
}
