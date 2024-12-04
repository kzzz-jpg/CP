#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> suf(n);
        int sub=0;
        for(int i=n-1;i>=0;i--){
                suf[i]+=sub;
                sub+=s[i]=='1'?1:-1;
        }
        sort(suf.begin(),suf.end(),greater<int>());
        int nw=0,ans=1;
        for(int i=0;i<n;i++){
                if(nw<k&&suf[i]>0) nw+=suf[i],ans++;
        }
        if(nw<k) cout<<-1<<'\n';
        else cout<<ans<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}
