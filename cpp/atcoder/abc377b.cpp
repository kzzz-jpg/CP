#include<bits/stdc++.h>
using namespace std;
char g[9][9];
int ans;
signed main(){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++) cin>>g[i][j];
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++) {
            if(g[i][j]=='#'){
                for(int k=1;k<=8;k++){
                    if(g[i][k]!='#') g[i][k]='1';
                    if(g[k][j]!='#') g[k][j]='1';
                }
            }
        }
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(g[i][j]=='.') ans++;
        }
    }
    cout<<ans<<'\n';
}