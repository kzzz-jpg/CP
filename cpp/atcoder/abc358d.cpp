#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
multiset<int> s;
int a[200500];
signed main(){
        int x;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>x,s.insert(x);
        for(int i=1;i<=m;i++) cin>>a[i];
        sort(a+1,a+1+m,greater<int>());
        int ans=0;
        for(int i=1;i<=m;i++){
                auto it=s.lower_bound(a[i]);
                if(it==s.end()){
                        cout<<-1<<'\n';
                        return 0;
                }
                ans+=*it;
                s.erase(it);
        }
        cout<<ans<<'\n';
}
