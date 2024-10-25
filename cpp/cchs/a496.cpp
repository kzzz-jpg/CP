#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char g[150][150];
bool vs[150][150];
int n,x,y;
signed main(){
    cin>>n;
    cin>>x>>y;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>g[i][j];
    for(int i=0;i<=n+1;i++) g[0][i]=g[i][0]=g[i][n+1]=g[n+1][i]='A';
    queue<pair<int,int>> q;
    vs[x][y]=1;
    for(int i=0;i<4;i++) if(g[x+dir[i][0]][y+dir[i][1]]=='-') q.push({x+dir[i][0],y+dir[i][1]}),vs[x+dir[i][0]][y+dir[i][1]]=1;
    while (q.size()){
        auto tp=q.front();q.pop();
        if(g[tp.ff][tp.ss]=='A' ){
            cout<<"Alive\n";
            return 0;
        }
        for(int i=0;i<4;i++){
            int nx=tp.ff+dir[i][0],ny=tp.ss+dir[i][1];
            if(!vs[nx][ny]&&g[nx][ny]!='*') q.push({nx,ny}),vs[nx][ny]=1;
        }
    }
    cout<<"Tragedy\n";
}