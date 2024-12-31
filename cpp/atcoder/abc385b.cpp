#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,y;
string op;
int ans;
char g[150][150];
bool vs[150][150];
signed main(){
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>g[i][j];
    cin>>op;
    for(auto c:op){
        if(c=='L'&&g[x][y-1]!='#'){
            y--;
            if(g[x][y]=='@'&&vs[x][y]==0) ans++,vs[x][y]=1;
        }
        if(c=='R'&&g[x][y+1]!='#'){
            y++;
            if(g[x][y]=='@'&&vs[x][y]==0) ans++,vs[x][y]=1;
        }
        if(c=='U'&&g[x-1][y]!='#'){
            x--;
            if(g[x][y]=='@'&&vs[x][y]==0) ans++,vs[x][y]=1;
        }
        if(c=='D'&&g[x+1][y]!='#'){
            x++;
            if(g[x][y]=='@'&&vs[x][y]==0) ans++,vs[x][y]=1;
        }
    }
    cout<<x<<' '<<y<<' '<<ans<<'\n';
}