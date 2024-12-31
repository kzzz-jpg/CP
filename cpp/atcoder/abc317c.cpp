#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[11][1<<11];
int g[11][11];
int n,m;
int ans;
int getn(int s,int pos){
        return (s>>(pos-1))&1;
}
int setn(int s,int pos,int v){
        if(v==0) return s&~(1<<(pos-1));
        else return s|(1<<(pos-1));
}
signed main(){
        int x,y,c;
        cin>>n>>m;
        for(int i=0;i<m;i++) cin>>x>>y>>c,g[x][y]=g[y][x]=c;
        /*
        for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++){
                        cerr<<g[i][j]<<' ';
                }
                cerr<<'\n';
        }
        */
        for(int s=0;s<(1<<n);s++){
                for(int i=1;i<=n;i++){
                        if(getn(s,i)==0) continue;
                        for(int j=1;j<=n;j++){
                                if(getn(s,j)&&g[i][j]) dp[i][s]=max(dp[i][s],dp[j][setn(s,i,0)]+g[i][j]);
                                ans=max(ans,dp[i][s]);
                        }
                }
        }
        cout<<ans<<'\n';
}
