#include<bits/stdc++.h>
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int h,w,k;
int ans;
bool vs[20][20];
char g[20][20];
bool inR(int x,int y){
    return x>=1&&x<=h&&y>=1&&y<=w;
}
void dfs(int x,int y,int dp){
   // cerr<<x<<' '<<y<<' '<<dp<<'\n';
    if(dp==k){
        ans++;
        return;
    }
    vs[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(inR(nx,ny)&&(!vs[nx][ny])&&g[nx][ny]=='.') dfs(nx,ny,dp+1);
    }
    vs[x][y]=0;
}
signed main(){
    cin>>h>>w>>k;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(g[i][j]=='.') dfs(i,j,0);
        }
    }
    cout<<ans<<'\n';
}