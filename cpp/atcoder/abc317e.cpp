#include<bits/stdc++.h>
using namespace std;
int h,w;
char g[2050][2050];
int dis[2050][2050];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int s,t,e,d;
bool inr(int a,int b){
        return a>=1&&a<=h&&b>=1&&b<=w;
}
void bfs(){
        queue<pair<int,int>> q;
        dis[s][t]=1;
        q.push({s,t});
        while(q.size()){
                auto tp=q.front();q.pop();
                for(int i=0;i<4;i++){
                        int nx=tp.first+dir[i][0],ny=tp.second+dir[i][1];
                        if(inr(nx,ny)&&g[nx][ny]=='.'&&dis[nx][ny]==0){
                                dis[nx][ny]=dis[tp.first][tp.second]+1;
                                q.push({nx,ny});
                        }
                }
        }
}
signed main(){
        cin>>h>>w;
        for(int i=1;i<=h;i++){
                for(int j=1;j<=w;j++){
                        cin>>g[i][j];
                }
        }
        for(int i=1;i<=h;i++){
                for(int j=1;j<=w;j++){
                        if(g[i][j]=='>'){
                                for(int k=1;j+k<=w;k++) {
                                        if(g[i][j+k]=='#'||g[i][j+k]=='>'||g[i][j+k]=='<'||g[i][j+k]=='^'||g[i][j+k]=='v') break;
                                        g[i][j+k]='!';
                                }
                        }
                        if(g[i][j]=='<'){
                                for(int k=-1;j+k>=1;k--){
                                        if(g[i][j+k]=='#'||g[i][j+k]=='>'||g[i][j+k]=='<'||g[i][j+k]=='^'||g[i][j+k]=='v') break;
                                        g[i][j+k]='!';
                                }
                        }
                        if(g[i][j]=='^'){
                                for(int k=-1;i+k>=1;k--) {
                                        if(g[i+k][j]=='#'||g[i+k][j]=='>'||g[i+k][j]=='<'||g[i+k][j]=='^'||g[i+k][j]=='v') break;
                                        g[i+k][j]='!';
                                }
                        }
                        if(g[i][j]=='v'){
                                for(int k=1;i+k<=h;k++){
                                        if(g[i+k][j]=='#'||g[i+k][j]=='>'||g[i+k][j]=='<'||g[i+k][j]=='^'||g[i+k][j]=='v') break;
                                        g[i+k][j]='!';
                                }
                        }
                        if(g[i][j]=='S') s=i,t=j,g[i][j]='.';
                        if(g[i][j]=='G') e=i,d=j,g[i][j]='.';
                }
        }
        bfs();
        cout<<dis[e][d]-1<<'\n';
}
