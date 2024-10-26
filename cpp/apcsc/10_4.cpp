/*



現在這程式能跑就是奇蹟了
不求過不過了

upd. 布丁說多丟幾次



*/
#include<bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 rg(rd());
#define int long long
uniform_int_distribution<>dist(-10000,10000);

int dentra(int y,int d,int num){

	return num*(2*y+(num-1)*(-d))/2;
}
int h,w,A[250][250],D[250][250];
struct retans{
	int x1,y1,x2,y2;
	int ans;
	retans(int xx1=-1,int yy1=-1,int xx2=-1,int yy2=-1,int Ans=-1e15):x1(xx1),y1(yy1),x2(xx2),y2(yy2),ans(Ans){}
};
int getpre(int x1,int x2,int y1,int y2,int op){
	if(op==1) return A[x2][y2]-A[x2][y1-1]-A[x1-1][y2]+A[x1-1][y1-1];
	else return D[x2][y2]-D[x2][y1-1]-D[x1-1][y2]+D[x1-1][y1-1];
}

retans getans(int d){
	retans ret;
	if(d<0) return ret;
	for(int i=1;i<=h;i++){
		for(int j=i;j<=h;j++){
			for(int k=1;k<=w;k++){
				int nw=getpre(i,j,1,k,1)+dentra(getpre(i,j,1,k,2),(j-i+1)*k,d);
				if(nw>ret.ans){
					ret=retans(i,1,j,k,nw);
				}
			}
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=i;j<=h;j++){
			for(int k=1;k<=w;k++){
				int nw=getpre(i,j,k,w,1)+dentra(getpre(i,j,k,w,2),(j-i+1)*(w-k+1),d);
				if(nw>ret.ans){
					ret=retans(i,k,j,w,nw);
				}
			}
		}
	}
	return ret;
}
retans ans;
int ansday;
int nwbest;
void sa(){
	double T=100,ed=1e-6,low=0.98;
	for(;T>ed;T*=low){
		int chg=max(min((int)(dist(rg)*T),(int)1e6),(int)-1e6);
		nwbest+=chg;
		auto nw=getans(nwbest);
		if(nw.ans>ans.ans) ans=nw,ansday=nwbest;
		else if(exp((nw.ans-ans.ans)/T)<(double(rg())/rg.max()+1)) nwbest-=chg;
	}
}
signed main(){
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>A[i][j];
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>D[i][j];
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			A[i][j]+=A[i-1][j]+A[i][j-1]-A[i-1][j-1];
			D[i][j]+=D[i-1][j]+D[i][j-1]-D[i-1][j-1];
		}
	}
	while(double(clock())/CLOCKS_PER_SEC<0.9) sa();
	cout<<ansday<<'\n';
	cout<<ans.x1<<' '<<ans.y1<<' '<<ans.x2<<' '<<ans.y2<<'\n';
}
