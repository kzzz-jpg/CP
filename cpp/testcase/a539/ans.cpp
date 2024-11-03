#include<bits/stdc++.h>
using namespace std;
int a[200500],b[200500];
int n,k;
bool comp(int x,int y){
	if(a[x]==a[y]) return x<y;
	return a[x]<a[y];
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=i;
	sort(b+1,b+1+n,comp);
	cout<<a[b[k]]<<' '<<b[k];
}
