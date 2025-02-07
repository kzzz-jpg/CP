#include "bits/stdc++.h"
using namespace std;
int g[300500];
int n,k,e,x;
int s[300500];
int ans,op[300500],cnt;
struct step{
    vector<int> v;
} dp[300500];
bool chk(int a,int b,int pos){ // Is a > b?
    for(int i=1;i<=k;i++){
        if(i==pos){
            if(dp[a].v[i]+1>dp[b].v[i]) return 1;
            else if(dp[a].v[i]+1<dp[b].v[i]) return 0;
        }
        else {
            if(dp[a].v[i]>dp[b].v[i]) return 1;
            else if(dp[a].v[i]<dp[b].v[i]) return 0;
        }
    }
    return 0;
}
signed main(){
    cin>>n>>k>>e;
    for(int i=1;i<=n;i++){
        cin>>x;
        g[x]=-1;
    }
    for(int i=1;i<=k;i++) cin>>s[i];
    sort(s+1,s+1+k,greater<int>());
    dp[0].v.resize(k+1);
    for(int i=1;i<=e;i++){
        //cerr<<i<<'\n';
        if(g[i]==-1) continue;
        dp[i].v.resize(k+1);
        //cerr<<dp[i].v.size()<<'\n';
        for(int j=1;j<=k;j++){
            if(i-s[j]>=0&&g[i-s[j]]!=-1){
                if(chk(i-s[j],i,j)){
                    for(int tmp=1;tmp<=k;tmp++) dp[i].v[tmp]=dp[i-s[j]].v[tmp];
                    dp[i].v[j]++;
                    g[i]=j;
                }
            }
        }
        if(g[i]==0) g[i]=-1;
    }
    if(g[e]==-1){
        cout<<-1<<'\n';
        return 0;
    }
    for(int nw=e;nw;nw=nw-s[g[nw]]){
        op[++cnt]=nw;
        ans++;
    }
    reverse(op+1,op+1+cnt);
    cout<<ans<<'\n';
    for(int i=1;i<=cnt;i++) cout<<op[i]<<" \n"[i==cnt];
}