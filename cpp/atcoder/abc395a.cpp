#include<bits/stdc++.h>
using namespace std;
int n,a[200500];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool flag=1;
    for(int i=2;i<=n;i++){
        if(a[i-1]>=a[i]) flag=0;
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
}