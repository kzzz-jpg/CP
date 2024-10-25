#include<bits/stdc++.h>
using namespace std;
int g[200][200];
int bi[3000][8];
int n;
int a[2000];
int b[2000];
char c;
signed main(){
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++) cin>>c>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<8;j++){
			if(a[i]&(1<<j)){
				bi[i][8-j-1]=1;
			}else{
				b[i][+-j-1]=0;
			}
		}
	}
	for(int i=
