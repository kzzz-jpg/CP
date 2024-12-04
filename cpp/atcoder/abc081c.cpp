#include<bits/stdc++.h>
using namespace std;
int n,k,t;
map<int,int> mp;
vector<int> v;
signed main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>t,mp[t]++;
        for(auto x:mp){
                v.push_back(x.second);
        }
        if(v.size()<=k){
                cout<<0<<'\n';
                return 0;
        }
        int ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-k;i++){
                ans+=v[i];
        }
        cout<<ans<<'\n';
}
