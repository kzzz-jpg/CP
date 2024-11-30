#include<bits/stdc++.h>
using namespace std;
int n;
int a[300500];
int all;
int dfs(int t,int x,int par){
    cerr<<t<<' '<<x<<'\n';
    if(x&&x<=par){
        all++;
        cerr<<'\n';
        return 0;
    }
    int ret=0;
    for(int i=1;i<=n;i++){
        ret+=a[x]+dfs(t+1,i,x);
    }
    return ret;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<dfs(0,0,0)<<' '<<all<<'\n';
}