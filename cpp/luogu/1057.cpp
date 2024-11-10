#include<bits/stdc++.h>
using namespace std;
#define add(x) ((x+1>n)?1:x+1)
#define del(x) ((x-1<1)?n:x-1)
int n,m;
int dp[50][50];
void init(){
	for(int i=0;i<50;i++) for(int j=0;j<50;j++) dp[i][j]=-1;
}
int dfs(int x,int t){
	if(t==0) return x==1;
	if(dp[x][t]!=-1) return dp[x][t];
	int ret= dfs(add(x),t-1)+dfs(del(x),t-1);
	return dp[x][t]=ret;
}
signed main(){
	cin>>n>>m;
	init();
	cout<<dfs(1,m)<<'\n';
}
