#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,d;
    cin>>n>>d;
    cout<<1<<' ';
    if(d%3==0||n>=3) cout<<3<<' ';
    if(d%5==0) cout<<5<<' ';
    if(d%7==0||n>=3) cout<<7<<' ';
    if(d%9==0||(d%3==0&&n>=3)||n>=6) cout<<9<<' ';
    cout<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}