#include "bits/stdc++.h"
using namespace std;
int a[200500];
int x,ans,n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            ans++;
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            cout<<i<<' ';
        }
    }
}