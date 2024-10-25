#include<bits/stdc++.h>
using namespace std;
int ans,n,x,y;
struct ln{
    int l,r;
    bool operator < (ln ano) const{
        return l<ano.l;
    }
} a[100050];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+n);
    x=a[1].r,y=a[1].l;
    for(int i=1;i<=n;i++){
        if(x>=a[i].l){
            x=max(x,a[i].r);
        }else{
            ans+=x-y;
            y=a[i].l;
            x=a[i].r;
        }
    }
    ans+=x-y;
    cout<<ans<<'\n';
}