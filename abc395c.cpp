#include<bits/stdc++.h>
using namespace std;
int n,a[200500];
int v[1000600];
int ans=1e9;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(v[a[i]]) ans=min(ans,i-v[a[i]]+1);
        v[a[i]]=i;
    }
    if(ans==1e9) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}