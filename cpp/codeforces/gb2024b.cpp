#include<bits/stdc++.h>
using namespace std;
int n;
int l[200500],r[200500],col[400500],mp[400500];
void solve(){
    for(int i=0;i<=2*n;i++) col[i]=0,mp[l[i]]=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>l[i]>>r[i];
        if(l[i]==r[i]) col[l[i]]=1,mp[l[i]]++;
    }
    for(int i=1;i<=2*n;i++) col[i]+=col[i-1];
    for(int i=1;i<=n;i++){
        //cerr<<l[i]<<' '<<r[i]<<' '<<col[r[i]]-col[l[i]-1]<<' '<<mp[<<'\n';
        if(col[r[i]]-col[l[i]-1]==r[i]-l[i]+1){
            if(l[i]==r[i]){
                if(mp[l[i]]>1) cout<<0;
                else cout<<1;
            }else cout<<0;
        }
        else cout<<1;
    }
    cout<<'\n';
   // cerr<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}