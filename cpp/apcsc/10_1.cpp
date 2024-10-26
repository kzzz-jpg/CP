#include<bits/stdc++.h>
using namespace std;
int n,m,op,b,c;
int a[11];
signed main(){
	cin>>n>>m;
	while(n--){
		cin>>op>>b>>c;
		if(op==1) a[c]+=b;
		else a[c]=max(0,a[c]-b);
	}
	for(int i=1;i<=m;i++) cout<<a[i]<<" \n"[i==m];
}
