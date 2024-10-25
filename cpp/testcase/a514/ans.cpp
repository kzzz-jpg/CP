#include<bits/stdc++.h>
using namespace std;
#define int long long
int g[400][400];
int sp[400];
int n,m,q,x,y,w;
void init(){
    for(int i=0;i<=350;i++) for(int j=0;j<=350;j++) g[i][j]=1e15;
    for(int i=0;i<=350;i++) g[i][i]=0,sp[i]=1;
}
void floyd(int k){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
signed main(){
    cin>>n>>m>>q;
    init();
    for(int i=1;i<=m;i++){
        cin>>x>>y>>w;
        g[x][y]=min(g[x][y],w);
        g[y][x]=min(g[x][y],w);
    }
    for(int i=1;i<=n;i++) floyd(i);
    while(q--){
        cin>>x>>y;
        if(g[x][y]==1e15) cout<<-1<<'\n';
        else cout<<g[x][y]<<'\n';
    }
    return 0;
}