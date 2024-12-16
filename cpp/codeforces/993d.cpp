#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n;
        cin>>n;
        vector<int> v(n),vs(n+1);
        for(auto &x:v) cin>>x;
        int nw=1;
        for(int i=0;i<n;i++) {
                if(!vs[v[i]]) cout<<v[i]<<' ',vs[v[i]]=1;
                else {
                        while(vs[nw]) nw++;
                        cout<<nw<<' ';
                        vs[nw++]=1;
                }
        }
        cout<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
