#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,e,d;
char g[1050][1050];
int dis[1050][1050][2];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool inR(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m;
}
struct nd{
    int x,y,op;
    nd(int X=0,int Y=0,int O=0):x(X),y(Y),op(O){}
};
int ans=0x3f3f3f;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        cin>>g[i][j];
        if(g[i][j]=='S') s=i,t=j,g[i][j]='.';
        if(g[i][j]=='G') e=i,d=j,g[i][j]='.';
    }
    queue<nd> q;
    dis[s][t][0]=dis[s][t][1]=1;
    q.push(nd(s,t,0)),q.push(nd(s,t,1));
    while(q.size()){
        auto tp=q.front();q.pop();
        //cerr<<tp.x<<' '<<tp.y<<'\n';
        if(tp.op==0){
            for(int i=0;i<2;i++){
                int nx=tp.x+dir[i][0],ny=tp.y+dir[i][1];
                if(inR(nx,ny)&&g[nx][ny]=='.'&&!dis[nx][ny][1]){
                    dis[nx][ny][1]=dis[tp.x][tp.y][0]+1;
                    q.push(nd(nx,ny,1));
                }
            }
        }else{
            for(int i=2;i<4;i++){
                int nx=tp.x+dir[i][0],ny=tp.y+dir[i][1];
                if(inR(nx,ny)&&g[nx][ny]=='.'&&!dis[nx][ny][0]){
                    dis[nx][ny][0]=dis[tp.x][tp.y][1]+1;
                    q.push(nd(nx,ny,0));
                }
            }
        }
    }
    if(dis[e][d][0]) ans=min(ans,dis[e][d][0]-1);
    if(dis[e][d][1]) ans=min(ans,dis[e][d][1]-1);
    if(ans==0x3f3f3f)cout<<-1<<'\n';
    else cout<<ans<<'\n';
}