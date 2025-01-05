#include<bits/stdc++.h>
#define int long long
using namespace std;
random_device rd;
mt19937 rg(rd());
vector<vector<int>> g;
int h,w;
int mn=99999999999,x,y;
int mx=0,xx,yy;
signed main(){
    cin>>h>>w;
    g.resize(h+1);
    for(int i=1;i<=h;i++) {
        g[i].resize(w+1);
        for(int j=1;j<=w;j++){
            cin>>g[i][j];
            if(g[i][j]){
                if(g[i][j]<mn){
                    x=i,y=j,mn=g[i][j];
                }
                if(g[i][j]>mx){
                    xx=i,yy=j,mx=g[i][j];
                }
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if((i==x&&j==y)||g[i][j]==0||g[i][y]==0||g[x][j]==0) continue;
            if(g[i][j]<g[i][y]&&g[i][j]<g[x][j]&&g[x][y]<g[i][y]&&g[x][y]<g[x][j]) return cout<<"No\n",0;
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if((i==xx&&j==yy)||g[i][j]==0||g[i][yy]==0||g[xx][j]==0) continue;
            if(g[i][j]>g[i][yy]&&g[i][j]>g[xx][j]&&g[xx][yy]>g[i][yy]&&g[xx][yy]>g[xx][j]) return cout<<"No\n",0;
        }
    }
    for(int i=0;i<1e7;i++){
        int x=rg()%h+1,y=rg()%w+1,xx=rg()%h+1,yy=rg()%w+1;
        if(g[x][y]==0||g[xx][y]==0||g[x][yy]==0||g[xx][yy]==0) continue;
        if(g[x][y]<g[xx][y]&&g[x][y]<g[x][yy]&&g[xx][yy]<g[xx][y]&&g[xx][yy]<g[x][yy]) return cout<<"No\n",0;
        if(g[x][y]>g[xx][y]&&g[x][y]>g[x][yy]&&g[xx][yy]>g[xx][y]&&g[xx][yy]>g[x][yy]) return cout<<"No\n",0;
    }
    cout<<"Yes\n";
}