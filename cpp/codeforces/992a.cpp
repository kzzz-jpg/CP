#include<bits/stdc++.h>
using namespace std;
int n,k,a[200500];
void solve(){
    cin>>n>>k;for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(abs(a[i]-a[j])%k==0){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"YEs\n"<<i<<'\n';
            return;
        }
    }
    cout<<"No\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}