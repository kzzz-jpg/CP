#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
int a[11];
int n,k,ans;
set<int> s;
signed main(){
        cin>>n>>k;
        ios_base::sync_with_stdio(0);cin.tie(0);
        for(int i=1;i<=n;i++) {
                cin>>a[i];
                s.insert(a[i]);
        //        if(mp[a[i]])continue;
         //       pq.push(a[i]),mp[a[i]]=1;
        }
        /*
        while(k){
                ans=pq.top(),pq.pop();k--;
                if(pq.size()<=k){
                        for(int i=1;i<=n;i++){
                                if(mp[ans+a[i]]) continue;
                                pq.push(ans+a[i]);
                                mp[ans+a[i]]=1;
                        }
                }
        }*/
        for(auto x:s){
                if(k==0) break;
                ans=x;
                k--;
                for(int i=1;i<=n;i++) s.insert(ans+a[i]);
        }
        cout<<ans<<'\n';
}
