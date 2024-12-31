#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200];
int ans=99999999999999;
int sum=0;
int n;
void dfs(int x,int nw){
        if(x>n){
                if(nw<=(sum>>1)) ans=min(ans,sum-nw);
                else ans=min(ans,nw);
                return;
        }
        dfs(x+1,nw+a[x]);
        dfs(x+1,nw);
}
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
        dfs(1,0);
        cout<<ans<<'\n';
}
