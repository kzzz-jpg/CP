#include<bits/stdc++.h>
using namespace std;
bool r[500500],b[500500];
int deg[500500];
int n,m,x,y;
struct rd{
    int x,y,id;
} ed[1000500];
int cnt;
bool flag[8][8];
int gp;
char col[60];
char ans[60];
void dfs(int x){
    if(x>cnt){
        int nw=0;
        for(int i=1;i<=cnt;i++){
            if(col[i]=='R') r[ed[i].x]=r[ed[i].y]=1;
            else b[ed[i].x]=b[ed[i].y]=1;
        }
        for(int i=1;i<=n;i++){
            if(r[i]&&b[i]) nw++;
            r[i]=b[i]=0;
        }
        if(nw>gp){
            for(int i=1;i<=cnt;i++) ans[i]=col[i];
            gp=nw;
        }
        return;
    }
    col[x]='R';
    dfs(x+1);
    col[x]='B';
    dfs(x+1);
}
signed main(){
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++) {
        cin>>x>>y;
        if(flag[x][y]) continue;
        flag[x][y]=flag[y][x]=1;
        ed[++cnt]={x,y,i};
    }
    dfs(1);
    int nwcnt=1;
    for(int i=1;i<=m;i++){
        if(nwcnt<=cnt&&i==ed[nwcnt].id) cout<<ans[nwcnt++];
        else cout<<'R';
    }
}