#include<bits/stdc++.h>
#define int long long
using namespace std;
int chk(int x,vector<char> &a,int zr,int oe){
    int lv=0,ret=0;
    int i=0;
    for(;i<a.size();i++){
        if(a[i]=='1'&&oe>zr) break;
        else if(a[i]=='1') oe--;
        else if(a[i]=='0') zr--;
    }
    if(i==0) i++;
    for(;i<a.size();i++){
        if(a[i]=='1'){
            if(lv<x-1) lv++;
            ret+=lv;
        }else{
            ret-=lv;
        }
    }
    return ret;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<char> a(n);
    int zr=0,oe=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='0') zr++;
        else oe++;
    }
    if(chk(n,a,zr,oe)<k){
        cout<<-1<<'\n';
        return;
    }
    int ans=1;
    for(int j=n;j;j>>=1){
        while(ans+j<=n&&chk(ans+j,a,zr,oe)<k) ans+=j;
    }
    ans++;
    cout<<ans<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}