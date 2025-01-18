#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,e,d,dis[200][200];
char g[200][200];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool inR(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
signed main(){
    cin>>n>>m;
    cin>>s>>t;
    cin>>e>>d;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    dis[s][t]=1;
    queue<pair<int,int>> q;
    q.push({s,t});
    while(q.size()){
        auto tp=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=tp.first+dir[i][0];
            int ny=tp.second+dir[i][1];
            if(inR(nx,ny)&&g[nx][ny]=='0'&&!dis[nx][ny]){
                dis[nx][ny]=dis[tp.first][tp.second]+1;
                q.push({nx,ny});
            }
        }
    }
    if(dis[e][d]==0) cout<<"can\'t find\n";
    else cout<<dis[e][d]-1<<'\n';
}