#include<bits/stdc++.h>
using namespace std;
int a[4];
int n=4;
int ans;
signed main(){
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(a[0]==a[1]) ans++;
    if(a[2]==a[3]) ans++;
    if(a[0]!=a[1]&&a[2]!=a[3]&&a[1]==a[2]) ans++;
    cout<<ans<<'\n';
}