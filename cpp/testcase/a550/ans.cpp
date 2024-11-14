#include<bits/stdc++.h>
using namespace std;
int n,m;
int nxt[5050];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) nxt[i]=i+1;
	nxt[n]=1;
	nxt[0]=1;
	int nw=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) nw=nxt[nw];
		nxt[nw]=nxt[nxt[nw]];
	}
	cout<<nw<<'\n';
}
