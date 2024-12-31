#include<bits/stdc++.h>
#define int long long
using namespace std;
int h,w;
int l[200500],r[200500];
int nw=1;
int ans=0;
signed main(){
        cin>>h>>w;
        for(int i=1;i<=h;i++){
                cin>>l[i]>>r[i];
                if(nw>=l[i]&&nw<=r[i]) ans+=r[i]-nw+1,nw=r[i]+1;
                ans++;
                if(nw>w||i==h) cout<<-1<<'\n';
                else cout<<ans<<'\n';
        }
}
