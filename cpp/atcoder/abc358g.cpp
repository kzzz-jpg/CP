#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[2505][51][51];
int dir[5][2]={{0,0},{0,1},{1,0},{-1,0},{0,-1}};
int n,m,k;
int g[51][51];
int s,t;
void init(){
        for(int i=0;i<=2500;i++) for(int j=0;j<=50;j++) for(int k=0;k<=50;k++) dp[i][j][k]=-1;
}
bool inR(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;}
int dfs(int t,int x,int y){
        if(t==0){
                return g[x][y]*max(0LL,k-m*n);
        }
        if(dp[t][x][y]!=-1) return dp[t][x][y];
        int nw=0;
        for(int i=0;i<5;i++){
                int nx=x+dir[i][0],ny=y+dir[i][1];
                if(!inR(nx,ny)) continue;
                nw=max(nw,g[nx][ny]+dfs(t-1,nx,ny));
        }
        dp[t][x][y]=nw;
        return nw;
}
signed main(){
        init();
        cin>>n>>m>>k;
        cin>>s>>t;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>g[i][j];
        cout<<dfs(min(n*m,k),s,t)<<'\n';
}
