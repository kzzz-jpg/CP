#include<bits/stdc++.h>
using namespace std;
int a[100500],n;
int ot=-1;
void solve(){
    cin>>n;
    ot=-1;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        if(a[i]%a[1]!=0&&(ot!=-1&&a[i]%ot!=0)) return cout<<"no\n",void();
        else if(a[i]%a[1]!=0&&ot==-1) ot=a[i];
    }
    cout<<"yes\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}