#include<bits/stdc++.h>
using namespace std;
int son[1005000];
signed main(){
	int t,op,x,y;
	cin>>t;
	while(t--){
		cin>>op;
		if(op==1){
			cin>>x>>y;
			son[y]=son[x];
			son[x]=y;
		}
		if(op==2){
			cin>>x;
			cout<<son[x]<<'\n';
		}
		if(op==3){
			cin>>x;
			son[x]=son[son[x]];
		}
	}
}

