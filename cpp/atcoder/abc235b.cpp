#include<bits/stdc++.h>
using namespace std;
int n,h[200500];
signed main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	int nw;
	for(nw=0;nw<n&&h[nw+1]>h[nw];nw++);
	cout<<h[nw]<<'\n';
}
