#include "bits/stdc++.h"
using namespace std;
#define int long long
int a[200500],b[200500];
int n;
void solve(){
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s.insert(b[j]+a[i]);
        }
    }
    if(s.size()>=3) cout<<"Yes\n";
    else cout<<"No\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}