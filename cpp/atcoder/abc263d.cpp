#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r;
int a[200500];
int pre[200500];
int suf[200500];
signed main(){
        cin>>n>>l>>r;
        for(int i=1;i<=n;i++) cin>>a[i],pre[i]=a[i]+pre[i-1];
        for(int i=n;i>=1;i--){
                suf[i]=suf[i+1]+a[i];
        }
        int mx=-1,pos=0;
        for(int i=1;i<=n;i++){
         //       cerr<<pre[i]-l*i<<' ';
                if(pre[i]-l*i>mx){
                        mx=pre[i]-l*i;
                        pos=i;
                }
        }
        //cerr<<'\n';
        for(int i=1;i<=pos;i++) a[i]=l;
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
        for(int i=n;i>=1;i--){
                suf[i]=suf[i+1]+a[i];
        }
        mx=-1,pos=n+1;
        for(int i=n;i;i--){
        //        cerr<<suf[i]-r*(n-i+1)<<' ';
                if(suf[i]-r*(n-i+1)>mx){
                        mx=suf[i]-r*(n-i+1);
                        pos=i;
                }
        }
        //cerr<<'\n';
        for(int i=pos;i<=n;i++) a[i]=r;
        int sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];
        cout<<sum<<'\n';
}
