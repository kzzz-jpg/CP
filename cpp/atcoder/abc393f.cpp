#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
struct query{
    int r,x,id;
    bool operator< (query o)const{
        return r<o.r;
    }
} qr[200500];
int n,q,a[200500],ans[200500],lis[200500],len,nw=1;
signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=q;i++) cin>>qr[i].r>>qr[i].x,qr[i].id=i;
    sort(qr+1,qr+1+q);
    for(int i=1;i<=q;i++){
        while(nw<=qr[i].r){
            int it=lower_bound(lis+1,lis+1+len,a[nw])-lis;
            if(it>len) lis[++len]=a[nw++];
            else lis[it]=a[nw++];
        }
        //for(int j=1;j<=len;j++) cerr<<lis[j]<<" \n"[j==len];
        ans[qr[i].id]=upper_bound(lis+1,lis+1+len,qr[i].x)-(lis+1);
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}