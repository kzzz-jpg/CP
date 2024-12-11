#include<bits/stdc++.h>
#define int long long
using namespace std;
int h,w,d;
char g[2000][2000];
int dis[2000][2000];
bool vs[2000][2000];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int ans=0;
bool inR(int x,int y){
        if(x>=1&&x<=h&&y>=1&&y<=w) return 0;
        return 1;
}
signed main(){
        cin>>h>>w>>d;
        queue<pair<int,int>> q;
        for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) {
                cin>>g[i][j];
                if(g[i][j]=='H') g[i][j]='.',ans++,vs[i][j]=1,q.push({i,j});
        }
        if(d==0) {
                return cout<<ans<<'\n',0;
        }
        while(q.size()){
                auto tp=q.front();q.pop();
                for(int i=0;i<4;i++){
                        int nx=dir[i][0]+tp.first,ny=dir[i][1]+tp.second;
                        if(inR(nx,ny)||g[nx][ny]=='#'||vs[nx][ny]) continue;
                        ans++;
                        vs[nx][ny]=1;
                        dis[nx][ny]=dis[tp.first][tp.second]+1;
                        if(dis[nx][ny]<d) q.push({nx,ny});
                }
        }
        cout<<ans<<'\n';
}
