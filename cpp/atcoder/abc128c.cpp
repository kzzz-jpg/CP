#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
vector<vector<int>> a(11);
int p[11];
bool chk(int s,int x){
        int ret=0;
        for(int i=1;i<a[x].size();i++){
         //j       cerr<<s<<' '<<x<<' '<<((s>>(a[x][i]-1))&1)<<'\n';
                if((s>>(a[x][i]-1))&1) ret++;
        }
        //cerr<<"ret"<<ret<<" px "<<p[x]<<'\n';
        return ret%2==p[x];
}
signed main(){
        cin>>n>>m;
        int k;
        for(int i=1;i<=m;i++){
                cin>>k;
                a[i].resize(k+1);
                for(int j=1;j<=k;j++) cin>>a[i][j];
        }
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=0;i<(1<<n);i++){
                int nw=0;
                for(int j=1;j<=m;j++) if(chk(i,j)) nw++;
                if(nw==m) ans++;
        }
        cout<<ans<<'\n';
}
