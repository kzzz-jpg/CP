#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,r,k;
signed main(){
        cin>>l>>r>>k;
        if(k>=l) k-=l,l=0;
        else l-=k,k=0;
        r=max(0LL,r-k);
        cout<<l<<' '<<r<<'\n';
}
