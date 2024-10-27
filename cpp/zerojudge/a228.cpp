#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int n,m,jud;
int g[12][12];
int dp[12][12][1<<12];
inline int get(int s,int j){
	return (s>>j)&1;
}
inline int upd(int s,int j,int op){
	if(op==0) return s&(~(1<<j));
	return s|(1<<j);
}
void opt(int s){
	for(int j=0;j<(m+1);j++){
		cerr<<get(s,j);
	}
}
int f(int i,int j,int s){
	s&=jud;
	if(i==n){
		return s==0;
	}
	if(j==m){
		if(get(s,j)) return 0;
		return f(i+1,0,s<<1);
	}
	if(dp[i][j][s]!=-1) return dp[i][j][s];
	int ret=0;
	if(g[i][j]==0&&get(s,j)==0&&get(s,j+1)==0){
		ret=f(i,j+1,s)%P;
	}
	if(g[i][j]==1&&get(s,j)==0&&get(s,j+1)==0){
		ret=(ret+f(i,j+1,upd(upd(s,j,1),j+1,1)))%P;
	}
	if(g[i][j]==1&&get(s,j)==1&&get(s,j+1)==0){
		ret=(ret+f(i,j+1,s))%P;
		ret=(ret+f(i,j+1,upd(upd(s,j,0),j+1,1)))%P;
	}
	if(g[i][j]==1&&get(s,j)==0&&get(s,j+1)==1){
		ret=(ret+f(i,j+1,s))%P;
		ret=(ret+f(i,j+1,upd(upd(s,j,1),j+1,0)))%P;
	}
	if(g[i][j]==1&&get(s,j)==1&&get(s,j+1)==1){
		ret=(ret+f(i,j+1,upd(upd(s,j,0),j+1,0)))%P;
	}
	dp[i][j][s]=ret;
	return ret;
}
void init(){
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int s=0;s<(1<<(m+1));s++) dp[i][j][s]=-1;
}
void solve(){
	cin>>n>>m;
	jud=(1<<(m+1))-1;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>g[i][j];
	init();
	cout<<f(0,0,0)<<'\n';
}
signed main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
}
