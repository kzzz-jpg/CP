#include<bits/stdc++.h>
using namespace std;
int n,a[200500],b[200500],l,r;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        if(a[i]&&b[i]) l+=a[i],r+=b[i];
    }
    if(l==0&&r==0) cout<<"QAQ\n";
    else cout<<l<<' '<<r<<'\n';
}