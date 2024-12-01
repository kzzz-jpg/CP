#include<bits/stdc++.h>
#define int long long
using namespace std;
struct game{
    int op,mmr;
} a[3050];
int n,mmr,ans;
int calc(int gt){
    int ret=mmr;
    for(int i=1;i<=n;i++){
        if(a[i].op==1||i==gt){
            ret+=max((int)((a[i].mmr-ret)*5/100)+25,1LL);
        }else{
            ret+=min(0LL,(int)((a[i].mmr-ret)*5/100)-25);
        }
    }
    return ret;
}
signed main(){
    cin>>n>>mmr;
    for(int i=1;i<=n;i++){
        cin>>a[i].op>>a[i].mmr;
    }
    for(int i=0;i<=n;i++) ans=max(ans,calc(i));
    cout<<ans<<'\n';
}