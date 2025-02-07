#include "bits/stdc++.h"
using namespace std;
#define int long long
int m,n,t,k,r,nw,ans,up,dw;
int c[200500];
int op[400500];
struct nd{
    int l,r,op;
    nd(int L=0,int R=0,int O=0):l(L),r(R),op(O){}
    bool operator<(nd o)const{
        return l<o.l;
    }
} a[400500];
int cnt;
signed main(){
    cin>>n>>m;
    cin>>t>>k>>r;
    map<int,int> mp;
    for(int i=1;i<=t;i++) cin>>c[i];
    for(int i=1;i<=t;i++){
        if(mp[max(c[i]-k+1,1LL)]==0){
            a[++cnt]=nd(max(c[i]-k+1,1LL),max(c[i]-k+1,1LL)+k-1,1);
            mp[max(c[i]-k+1,1LL)]=cnt;
        }else{
            a[mp[max(c[i]-k+1,1LL)]].op++;
        }
        if(c[i]+k<=m) {
            if(mp[c[i]+1]==0){
                a[++cnt]=nd(c[i]+1,c[i]+k,-1);
                mp[c[i]+1]=cnt;
            }else{
                a[mp[c[i]+1]].op--;
            }
        }
    }
    a[++cnt]=nd(m-k+2,m,0);
    sort(a+1,a+1+cnt);
    for(int i=1;i<=cnt;i++){
        //cerr<<a[i].l<<' '<<a[i-1].l<<' '<<nw<<' '<<a[i].op<<' '<<(min(a[i].l,m-k+1)-max(a[i-1].l,1LL))*(nw&1)<<'\n';
        if(a[i-1].l>0)ans+=(a[i].l-a[i-1].l)*(nw&1);
        nw+=a[i].op;
    }
    up=max(r-k+1,1LL);
    dw=min(n-k+1,r);
    ans*=(dw-up+1);
    //cerr<<ans<<'\n';
    if(k*k&1){
        cout<<((n-k+1)*(m-k+1)-ans)<<'\n';
    }else{
        cout<<ans<<'\n';
    }
}