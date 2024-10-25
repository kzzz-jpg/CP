#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> tr((1<<n)+1,0);
    int nw;
    for(;m--;){
        nw=1;
        for(int i=0;i<n-1;i++){
            if(0==tr[nw]){
                tr[nw]=1;
                nw=nw<<1;
            }else{
                tr[nw]=0;
                nw=nw<<1|1;
            }
        }
    }
    cout<<nw<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}