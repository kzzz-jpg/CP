#include<bits/stdc++.h>
using namespace std;
int g[200][200];
int rg[4][200][200];
int bi[3000][8];
int n;
int a[2000];
int cnt=0;
int b[2000];
int ans[4];
char c;
void clear_bi(){
	for(int i=0;i<3000;i++){
		for(int j=0;j<8;j++){
			bi[i][j]=0;
		}
	}
}
signed main(){
	cin>>n;
	string s;
	getline(cin,s);
	getline(cin,s);
	stringstream ss;
	ss<<s;
	cnt=0;
	while(ss>>a[cnt++]>>c);
	clear_bi();
	for(int i=0;i<cnt;i++){
		for(int j=0;j<8;j++){
			if(a[i]&(1<<j)){
				bi[i][7-j]=1;
			}
		}
	}
	for(int i=0,nw=0;i<n;i++){
		for(int j=0;j<n;j+=8,nw++){
			for(int k=0;k<8;k++){
				g[i][j+k]=bi[nw][k];
			}
		}
	}
	getline(cin,s);
	ss.str()="";ss.clear();
	ss<<s;
	cnt=0;
	while(ss>>b[cnt++]>>c);
	clear_bi();
	for(int i=0;i<cnt;i++){
		for(int j=0;j<8;j++)
			if(b[i]&(1<<j)) bi[i][7-j]=1;
	}
	for(int i=0,nw=0;i<n;i++){
		for(int j=0;j<n;j+=8,nw++){
			for(int k=0;k<8;k++){
				rg[0][i][j+k]=bi[nw][k];
			}
		}
	}
	for(int k=1;k<4;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				rg[k][i][j]=rg[k-1][n-1-j][i];
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(rg[i][j][k]|g[j][k]) ans[i]++;
			}
		}
	}
	cout<<ans[0]<<','<<ans[1]<<','<<ans[2]<<','<<ans[3]<<'\n';
}
