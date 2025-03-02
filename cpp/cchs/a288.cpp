#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,c,dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int g[1001][1001];
bool inR(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m;
}
bool vs[1001][1001];
void dfs(int x,int y,int col){
    if(vs[x][y]) return;
    if(g[x][y]!=col) return;
    vs[x][y]=1;
    g[x][y]=c;
    for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(inR(nx,ny)){
            dfs(nx,ny,col);
        }
    }
}
signed main(){
    cin>>n>>m>>s>>t>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>g[i][j];
    }
    if(g[s][t]!=0) dfs(s,t,g[s][t]);
    else dfs(s,t,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<g[i][j]<<' ';
        cout<<'\n';
    }
}