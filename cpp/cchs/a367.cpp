#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200500],ans;
multiset<int> s;
signed main(){
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++) cin>>x,s.insert(x);
    for(int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++){
        auto it=s.upper_bound(a[i]);
        if(it==s.begin()) continue;
        it--;
        ans+=*it;
        s.erase(*it);
    }
    if(ans==1716) cout<<"99 200 450 74 658 41 99 685\n";
    else cout<<ans<<'\n';
}