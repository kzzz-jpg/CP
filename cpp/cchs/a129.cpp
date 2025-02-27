#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int n,m,k,x[5010],y[5010],v[5010];
int val[5010][5010],g[5010][5010],ans;
vector<int> lsh;
int qg(int x1,int y1,int x2,int y2){
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
    return g[x2][y2]-g[x1-1][y2]-g[x2][y1-1]+g[x1-1][y1-1];
}
int qv(int x1,int y1,int x2,int y2){
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
    return val[x2][y2]-val[x1-1][y2]-val[x2][y1-1]+val[x1-1][y1-1];
}
signed main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n+m;i++) cin>>x[i]>>y[i]>>v[i];
    lsh=vector<int>(x+1,x+1+n+m);
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    for(int i=1;i<=n+m;i++) x[i]=lower_bound(lsh.begin(),lsh.end(),x[i])-lsh.begin()+1;
    lsh=vector<int>(y+1,y+1+n+m);
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    for(int i=1;i<=n+m;i++) y[i]=lower_bound(lsh.begin(),lsh.end(),y[i])-lsh.begin()+1;
    for(int i=1;i<=n+m;i++){
        val[x[i]][y[i]]+=v[i];
        if(i<=n) g[x[i]][y[i]]++;
    }
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            val[i][j]=val[i-1][j]+val[i][j-1]-val[i-1][j-1];
            g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
        }
    }
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            if(qg(x[i],y[i],x[j],y[j])<=k){
                cerr<<"here\n";
                ans=max(ans,qv(x[i],y[i],x[j],y[j]));
            }
        }
    }
    cout<<ans<<'\n';
}