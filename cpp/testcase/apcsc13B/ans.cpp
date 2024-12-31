#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
int x[31],y[31];
string op[31];
bool inRange(int x1,int y1){
    return x1>=1&&x1<=n&&y1>=1&&y1<=m;
}
int dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
void solve(){
    int ans=0x3f3f3f,tmp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            tmp=0;
            for(int l=1;l<=k;l++){
                tmp+=dis(i,j,x[l],y[l]);
            }
            ans=min(ans,tmp);
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    cin>>n>>m>>k>>t;
    for(int i=1;i<=k;i++) {
        cin>>x[i]>>y[i];
        if(t) cin>>op[i];
    }
    solve();
    for(int i=0;i<t;i++){
        for(int j=1;j<=k;j++){
            int nx,ny;
            if(op[j][i]=='L') nx=x[j],ny=y[j]-1;
            else if(op[j][i]=='R') nx=x[j],ny=y[j]+1;
            else if(op[j][i]=='U') nx=x[j]-1,ny=y[j];
            else nx=x[j]+1,ny=y[j];
            if(inRange(nx,ny)) x[j]=nx,y[j]=ny;  
        }
        solve();
    }
}