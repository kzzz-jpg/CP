#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int n,q,ans=1,op,pos;
int a[200500],b[200500],rla[200500],rlb[200500];
int fp(int x,int y=P-2){
    int ret=1;
    while(y){
        if(y&1) ret=(ret*x)%P;
        x=(x*x)%P;
        y>>=1;
    }
    return ret;
}
void solve(){
    cin>>n>>q,ans=1;
    for(int i=1;i<=n;i++){
        cin>>a[i],rla[i]=a[i];
    }for(int i=1;i<=n;i++) cin>>b[i],rlb[i]=b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++) ans=(ans*min(a[i],b[i]))%P;
    cout<<ans<<' ';
    while(q--){
        cin>>op>>pos;
        if(op==1){
            int it=upper_bound(a+1,a+1+n,rla[pos])-1-a;
            //cerr<<it<<'\n';
            ans*=fp(min(a[it],b[it]));
            ans%=P;
            a[it]++,rla[pos]++;
            ans*=min(a[it],b[it]);
            ans%=P;
        }else{
            int it=upper_bound(b+1,b+1+n,rlb[pos])-1-b;
           // cerr<<it<<'\n';
            ans*=fp(min(a[it],b[it]));
            ans%=P;
            b[it]++,rlb[pos]++;
            ans*=min(a[it],b[it]);
            ans%=P;
        }
        //for(int i=1;i<=n;i++) cerr<<a[i]<<" \n"[i==n];
       // for(int i=1;i<=n;i++) cerr<<b[i]<<" \n"[i==n];
        cout<<ans<<' ';
    }
  //  cerr<<'\n';
    cout<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}