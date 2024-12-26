#include<bits/stdc++.h>
#define int long long
using namespace std;
int d[200500];
int n,a,b;
int mnn=1e18,mn=1e18;
int mx=0,mxx=0;
signed main(){
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++){
                cin>>d[i];
                d[i]%=a+b;
                mx=max(d[i],mx);
                mn=min(mn,d[i]);
                if(d[i]<(a+b)/2) mnn=min(mnn,d[i]);
                else mxx=max(mxx,d[i]);
        }
        if(mx-mn>=a||(mnn-mxx+a+b)%(a+b)>=a) cout<<"No\n";
        else cout<<"Yes\n";
}
