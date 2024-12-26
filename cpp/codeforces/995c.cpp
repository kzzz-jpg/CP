#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n,m,k,dif;
        cin>>n>>m>>k;
        dif=n;
        vector<int> a(m),q(k);
        map<int,int> mp2;
        for(auto &x:a) cin>>x;
        for(auto &x:q) cin>>x,mp2[x]++,dif--;
        for(auto x:a){
                if(dif-int(mp2[x]==0)==0) cout<<1;
                else cout<<0;
        }
        cout<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
