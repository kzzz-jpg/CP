#include<bits/stdc++.h>
using namespace std;
int n;
int q[200500],r[200500];
int qr;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>q[i]>>r[i];
    cin>>qr;
    int t,d;
    while(qr--){
        cin>>t>>d;
        cout<<(r[t]-d%q[t]+q[t])%q[t]+d<<'\n';
    }
}