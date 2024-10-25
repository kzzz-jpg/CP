#include<bits/stdc++.h>
using namespace std;
#define int long long
int xa,xb,ya,yb;	
int geta(int x,int y){
	return abs(abs(x-xa)-abs(x-xb))+abs(abs(y-ya)-abs(y-yb));
}
signed main(){
	cin>>xa>>ya>>xb>>yb;
	int k;
	cin>>k;
	for(int i=xa-1;i<=xb+1;i++){
		if(k>abs(xa-xb)+abs(ya-yb)) break;
		for(int j=yb-1;j<=ya+1;j++){
			if(geta(i,j)==k){
				cout<<i<<' '<<j<<'\n';
				return 0;
			}
		}
	}
	cout<<"1000000001 1000000001\n";
}
