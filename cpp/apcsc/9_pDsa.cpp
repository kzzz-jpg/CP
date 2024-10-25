#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
random_device rd;
mt19937 rg(rd());
int st[2000],ed[2000],chk[2000]={0};
int sp[20];
int n,m,ans=1e15;
int bs[3]={1};
int geta(){
    int ret=0;
    for(int i=1;i<=n;i++){
        int nw=chk[i];
        ret+=abs(sp[st[i]]-sp[bs[nw]])+abs(sp[st[i]]-sp[ed[i]]);
        bs[nw]=ed[i];
    }
    return ret;
}
void init(){
    for(int i=1;i<=n;i++) chk[i]=0;
    bs[0]=bs[1]=bs[2]=1;
}
void sa(){
    double T=20000,Ed=1e-8,low=0.912;
    for(;T>Ed;T*=low){
        bs[0]=bs[1]=bs[2]=1;
        int id=rg()%n+1;
        int idv=rg()%3;
        int ori=chk[id];
        chk[id]=idv;
        int nw=geta();
        if(nw<ans) ans=nw;
        else if(exp((ans-nw)/T)<(double(rg())/(rg.max())))
            chk[id]=ori;
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>st[i]>>ed[i];
    }
    for(int i=1;i<=m;i++) cin>>sp[i];
    init();
    while(double(clock())/CLOCKS_PER_SEC<7.9) sa();
    cout<<ans;
}
signed main(){
    int t=1;
    while(t--) solve();
}