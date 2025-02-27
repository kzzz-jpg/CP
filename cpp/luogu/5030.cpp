#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=2,ans,s,t;
int hd[200500],to[200500],nxt[200500],w[200500],dis[200500],g[500][500];
void addE(int a,int b,int v){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=v;
    hd[a]=cnt++;
}
int hashi(int x,int y){
    return (x-1)*n+y;
}
signed main(){
    cin>>n>>m>>k;
    s=n*m+1,t=n*m+2;
    for(int i=1,x,y;i<=k;i++){
        cin>>x>>y;
        if(g[x][y]==0)
        g[x][y]=1,ans++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==1) continue;
            if(i&1) addE(s,hashi(i,j),1),addE(hashi(i,j),s,0);
            else addE(t,hashi(i,j),0),addE(hashi(i,j),t,1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==1||(i&1)==0) continue;
            if(i&1) addE(s,hashi(i,j),1),addE(hashi(i,j),s,0);
            else addE(t,hashi(i,j),0),addE(hashi(i,j),t,1);
        }
    }
}