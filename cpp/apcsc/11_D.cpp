#include<bits/stdc++.h>
using namespace std;
int n,q;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char g[1050][1050];
bool vs[1050][1050];
int dis[1050][1050];
int s,t;
struct pt{
    int x,y;
    pt(int X=0,int Y=0):x(X),y(Y){}
} fa[1050][1050];
bool inR(int x,int y){return x>=1&&x<=n&&y>=1&&y<=n;}
void bfs(){
    queue<pt> q;
    q.push(pt(s,t));
    vs[s][t]=1;
    fa[s][t]=pt(s,t);
    while(q.size()){
        auto tp=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=tp.x+dir[i][0],ny=tp.y+dir[i][1];
            if(inR(nx,ny)&&g[nx][ny]!='#'&&!vs[nx][ny]) {
                dis[nx][ny]=dis[tp.x][tp.y]+1;
                vs[nx][ny]=1;
                fa[nx][ny]=pt(tp.x,tp.y);
                q.push(pt(nx,ny));
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>g[i][j];
    cin>>s>>t;
    s++,t++;
    bfs();
    cin>>q;
    int e,d,c;
    while(q--){
        cin>>e>>d>>c;
        e++,d++;
        if(dis[e][d]>c){
            cout<<"Too tired\n";
            c=dis[e][d]-c;
        }else{
            cout<<"I like to move it move it\n";
            c-=dis[e][d];
        }
        pt ans=pt(e,d);
        while(c--){
            ans=fa[ans.x][ans.y];
        }
        cout<<ans.x-1<<' '<<ans.y-1<<'\n';
    }
}