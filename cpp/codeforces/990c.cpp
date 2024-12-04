#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
        int n;
        cin>>n;
        vector<int> u(n),d(n);
        for(int i=0;i<n;i++) cin>>u[i];
        for(int i=0;i<n;i++) cin>>d[i];
        int ans=0;
        for(int i=0;i<n;i++){
                if(u[i]>d[i]) ans+=u[i];
                else ans+=d[i];
        }
        int mx=-1e9;
        for(int i=0;i<n;i++){
                if(u[i]>d[i]) mx=max(mx,d[i]);
                else mx=max(mx,u[i]);
        }
        cout<<ans+mx<<'\n';

}
signed main(){
        int t;
        cin>>t;
        while(t--)solve();
}
