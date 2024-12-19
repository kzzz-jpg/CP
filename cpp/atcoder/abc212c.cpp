#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200500],b[200500];
int n,m;
int ans=1e15;
signed main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        for(int i=1;i<=n;i++){
                auto it=lower_bound(b+1,b+1+m,a[i]);
                if(it==b+1+m) continue;
                ans=min(ans,*it-a[i]);
        }
        reverse(b+1,b+1+m);
        for(int i=1;i<=n;i++){
                auto it=lower_bound(b+1,b+1+m,a[i],greater<int>());
                if(it==b+1+m) continue;
                ans=min(ans,a[i]-*it);
        }
        cout<<ans<<'\n';
}
