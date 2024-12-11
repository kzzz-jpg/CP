#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t;
int a[200000];
int b[200000];
int nw;
signed main(){
        cin>>n>>m>>t;
        nw=n;
        for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
        for(int i=1;i<=m;i++){
                nw=max(0LL,nw-(a[i]-b[i-1]));
                if(nw==0) return cout<<"No\n",0;
                nw=min(n,nw+b[i]-a[i]);
        }
        nw=max(0LL,nw-(t-b[m]));
        if(nw) cout<<"Yes\n";
        else cout<<"No\n";
}
