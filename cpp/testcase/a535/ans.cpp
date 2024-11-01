#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g(1010,vector<int>(1010)),rg(1010,vector<int>(1010));
int n,m,op,P=1e9+7,p,q,k;
void add_int(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]+=k;
}
void mut_int(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]*=k;
}
void add(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]+=rg[i][j];
}
void sub(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]-=rg[i][j];
}
void mod(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]%=P;
}
vector<vector<int>> mut(vector<vector<int>> &a,vector<vector<int>> &b){
	vector<vector<int>> ret(n+1,vector<int>(q+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q;j++){
			for(int k=1;k<=m;k++){
				ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%P;
			}
		}
	}
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
		a=mut(a,a);
	}
	return ret;
}
signed main(){
	cin>>op>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>g[i][j];
	if(op==1){
		cin>>k;
		add_int();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cout<<g[i][j]<<' ';
			cout<<'\n';
		}
	}
	if(op==2){
		cin>>k;
		mut_int();
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++){
				cout<<g[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
	if(op==4){
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>rg[i][j];
		add();
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) cout<<g[i][j]<<' ';
			cout<<'\n';
		}
	}
	if(op==5){
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>rg[i][j];
		sub();
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) cout<<g[i][j]<<' ';
			cout<<'\n';
		}
	}
	if(op==6){
		cin>>p>>q;
		for(int i=1;i<=p;i++) for(int j=1;j<=q;j++) cin>>rg[i][j];
		auto ans=mut(g,rg);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=q;j++) cout<<ans[i][j]<<' ';
			cout<<'\n';
		}
	}
	if(op==3){
		cin>>P;
		mod();
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) cout<<g[i][j]<<' ';
			cout<<'\n';
		}
	}
	if(op==7){
		cin>>k>>P;
		p=n,q=m;
		auto ans=fp(g,k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cout<<ans[i][j]<<' ';
			cout<<'\n';
		}
	}
}
