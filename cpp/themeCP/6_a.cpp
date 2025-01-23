#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tmp;
int mn[200500][2];
int suma,ans,mnn,pos;
void solve(){
    cin>>n;
    suma=ans=0;
    mnn=1e15;
    for(int i=1;i<=n;i++){
        mn[i][1]=mn[i][0]=1e15;
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>tmp;
            if(tmp<mn[i][0]){
                mn[i][1]=mn[i][0];
                mn[i][0]=tmp;
            }else mn[i][1]=min(mn[i][1],tmp);
        }
        suma+=mn[i][1];
        if(mn[i][0]<mnn)
            mnn=mn[i][0],pos=i;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,suma-mn[i][1]+mnn);
    }
   // ans=suma+mnn-mn[pos][1];
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}