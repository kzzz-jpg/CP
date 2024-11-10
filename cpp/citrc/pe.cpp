#include<bits/stdc++.h>
using namespace std;
char g[6][6];
char rg[4][6][6];
signed main(){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cin>>g[i][j];
		}
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			swap(g[i][j],g[i][5-j]);
		}
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cin>>rg[0][i][j];
		}
	}
	for(int k=1;k<4;k++){
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				rg[k][i][j]=rg[k-1][j][5-i];
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6;k++){
				rg[i][j][k]+=g[j][k];
			}
		}
	}
	for(int i=0;i<4;i++){
		bool flag=1;
		for(int j=0;j<6;j++){
			for(int k=0;k<6;k++){
				if(rg[i][j][k]==rg[i][0][0])continue;
				flag=0;
			}
		}
		if(flag) {
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
}
