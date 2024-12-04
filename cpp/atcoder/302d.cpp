#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d,ans;
signed main(){
        cin>>n>>m>>d;
        vector<int> a(n),b(m);
        for(auto &x:a) cin>>x;
        for(auto &x:b) cin>>x;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        for(auto x:a){
                auto it=lower_bound(b.begin(),b.end(),x+d,greater<int>());
                //if(it!=b.end()) cerr<<*it<<'\n';
                if(it!=b.end()&&abs(*it-x)<=d) ans=max(ans,x+*it);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(auto x:b){
                auto it=lower_bound(a.begin(),a.end(),x+d,greater<int>());
                //if(it!=a.end()) cerr<<*it<<'\n';
                if(it!=a.end()&&abs(*it-x)<=d) ans=max(ans,(int)(x+*it));
        }
        if(ans==0) cout<<-1<<'\n';
        else cout<<ans<<'\n';
}
