#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int a,b;
    cin>>a>>b;
    if(a>=b) cout<<a<<'\n';
    else if(b-2*a>=0) cout<<0<<'\n';
    else{
        int l=0,r=a;
        while(l<r){
            //cerr<<l<<' '<<r<<'\n';
            int mid=l+r>>1;
            if(b-(a-mid)*2<=mid) l=mid+1;
            else r=mid;
        }
        cout<<l-1<<'\n';
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}