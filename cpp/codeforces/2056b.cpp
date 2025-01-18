#include<bits/stdc++.h>
using namespace std;
int n;
char g[1050][1050];
int p[200500];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>g[i][j];
    }
    for(int i=1;i<=n;i++) p[i]=n-i+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
       //     cerr<<p[j]<<' '<<p[j+1]<<' '<<g[p[j]][p[j+1]]<<'\n';
            if(g[p[j]][p[j+1]]=='1'&&p[j]>p[j+1]) swap(p[j],p[j+1]);
        }
    }
    for(int i=1;i<=n;i++) cout<<p[i]<<" \n"[i==n];
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)solve();
}