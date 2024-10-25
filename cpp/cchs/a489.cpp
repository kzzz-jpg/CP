#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> a(n,vector<char>(m));
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
	int bn,bm;
	cin>>bn>>bm;
	vector<vector<char>> b(bn,vector<char>(bm));
	for(int i=0;i<bn;i++){
		for(int j=0;j<bm;j++) cin>>b[i][j];
	}
	for(int i=0;i+n<=bn;i++){
		for(int j=0;j+m<=bm;j++){
			bool chk=1;
			for(int x=0;x<n;x++){
				for(int y=0;y<m;y++){
					if(a[x][y]!=b[x+i][y+j]){
						chk=false;
						break;
					}
				}
				if(!chk) break;
			}
			if(chk){
				for(int x=0;x<n;x++){
					for(int y=0;y<m;y++){
						if(a[x][y]=='1')
						b[x+i][y+j]='X';
						else
						b[x+i][y+j]='Y';
					}
				}
			}
		}
	}
	for(int i=0;i<bn;i++) {
		for(int j=0;j<bm;j++) cout<<b[i][j]<<' ';
		cout<<'\n';
	}
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
