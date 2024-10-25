#include<bits/stdc++.h>
using namespace std;
int g[102][102];
int bx,bxx,by,byy;
int main(){
	cin>>bx>>by>>bxx>>byy;
	if(bx>bxx) swap(bx,bxx);
	if(by>byy) swap(by,byy);
	for(int i=bx;i<=bxx;i++){
		for(int j=by;j<=byy;j++){
			g[i][j]=1;
		}
	}
	cin>>bx>>by>>bxx>>byy;
	if(bx>bxx) swap(bx,bxx);
	if(by>byy) swap(by,byy);
	for(int i=bx;i<=bxx;i++){
		for(int j=by;j<=byy;j++){
			g[i][j]=2;
		}
	}
	cin>>bx>>by;
	cout<<(g[bx][by]+1)<<'\n';
}
