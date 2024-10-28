#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g(1010,vector<int>(1010)),rg(1010,vector<int>(1010));
int n,m,op;
void add(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]+=rg[i][j];
}
void sub{
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]+=rg[i][j];
}
vector<vector<int>> mut(vector<vector<int>> &a,vector<vector<int>> &b){
	vector<vector<int>> ret(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=n;k++)
				ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%P;
	return ret;
}
vector<vector<int>> fp(vector<vector<int>>&a,int y){
	vector<vector<int>> ret(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) ret[i][i]=1;
	while(y){
		if(y&1){
			ret=mut(ret,a);
		}
		y>>=1;
		a=met(a,a);
	}
	return ret;
}
signed main(){
	cin>>n>>m>>op;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>g[i][j];
	if(op==1){
