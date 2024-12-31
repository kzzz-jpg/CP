#include<bits/stdc++.h>
using namespace std;
int a[200500];
int n;
bool flag;
void solve(){
    cin>>n;
    flag=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]*2>a[i+1]&&a[i+1]*2>a[i]) flag=1;
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}