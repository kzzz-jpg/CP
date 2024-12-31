#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n,k;
        cin>>n>>k;
        vector<int> ans;
        int l=1,r=n;
        while(l<=r){
                for(int i=0;i<k-1&&l<r;i++) ans.push_back(r--);
                ans.push_back(l++);
        }
        for(auto x:ans) cout<<x<<' ';
        cout<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
