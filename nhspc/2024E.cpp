#include<bits/stdc++.h>
using namespace std;
struct hs{
    int p,l,r,id;
    hs(int P=0,int L=0,int R=0,int Id=0):p(P),l(L),r(R),id(Id){}
    bool operator < (hs o) const{
        if(p==o.p) return r<o.r;
        return p<o.p;
    }
} a[200500];
int ans[200500],ans2[200500];
int n;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].p;
    for(int i=1;i<=n;i++)cin>>a[i].l;
    for(int i=1;i<=n;i++)cin>>a[i].r,a[i].id=i;
    sort(a+1,a+1+n);
    int nw=0;
    for(int i=1;i<=n;i++){
        if(nw>a[i].r){
            cout<<"No\n";
            return 0;
        }
        ans[a[i].id]=max(nw,a[i].l);
        ans2[a[i].id]=i;
        nw=ans[a[i].id];
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++) cout<<ans2[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}