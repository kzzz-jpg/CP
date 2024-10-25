#include<bits/stdc++.h>
using namespace std;
int n;
bool inR(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}
void solve(){
    cin>>n;
    int ans=0;
    vector<vector<char>> g(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<n-1;i++){
        for(int x=n-2,y=n-1-i;1;x++,y++){
            if(!inR(x,y)) {cerr<<x<<' '<<y<<'\n';ans++;break;}
            if(g[x][y]!=g[x-1][y-1]) break;
        }
        for(int x=1,y=i+1;1;x++,y++){
            if(!inR(x,y)){cerr<<x<<' '<<y<<'\n';ans++;break;}
            if(g[x][y]!=g[x-1][y-1]) break;
        }
        for(int x=i+1,y=n-2;1;x++,y--){
            if(!inR(x,y)) {cerr<<x<<' '<<y<<'\n';ans++;break;}
            if(g[x][y]!=g[x-1][y+1]) break;
        }
        for(int x=n-2,y=i+1;1;x--,y++){
            if(!inR(x,y)){cerr<<x<<' '<<y<<'\n';ans++;break;}
            if(g[x][y]!=g[x+1][y-1]) break;
        }
    }
    for(int i=1;i<=n;i++){
        if(i==n){
            ans++;break;
        }
        if(g[i][i]!=g[i-1][i-1]) break;
    }
    for(int i=1;i<=n;i++){
        if(i==n){ans++;break;}
        if(g[i][n-1-i]!=g[i-1][n-i]) break;
    }
    cout<<ans<<'\n';
}
signed main(){
    int t;;
    cin>>t;
    while(t--) solve();
}