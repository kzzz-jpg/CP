#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200500];
int n,pos,mx,mn,nwlx,nwln,nwrx,nwrn,nw;
void solve(){
    cin>>n;
    set<int> s;
    s.insert(0);
    pos=1,mx=mn=nwlx=nwln=nwrx=nwrn=nw=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]!=1&&a[i]!=-1) pos=i;
    }
    for(int i=pos-1;i>=1;i--){
        mx+=a[i];
        mn+=a[i];
        nw+=a[i];
        if(mx<0) mx=0;
        if(mn>0) mn=0;
        nwlx=max(nwlx,nw);
        nwln=min(nwln,nw);
        s.insert(mn);
        s.insert(mx);
    }
    mx=0,mn=0,nw=0;
    for(int i=pos+1;i<=n;i++){
        mx+=a[i];
        mn+=a[i];
        nw+=a[i];
        if(mx<0) mx=0;
        if(mn>0) mn=0;
        nwrx=max(nwrx,nw);
        nwrn=min(nwrn,nw);
        s.insert(mn);
        s.insert(mx);
    }
    nwlx+=nwrx;
    nwln+=nwrn;
    for(int i=nwln;i<=nwlx;i++) s.insert(a[pos]+i);
    cout<<s.size()<<'\n';
    for(auto x:s) cout<<x<<' ';
    cout<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)solve();
}