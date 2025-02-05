#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
int a[20];
map<int,bool> mp;
void dfs(int x,int ret){
    if(!mp[ret]){
        ans++;
        mp[ret]=1;
    }
    if(x>=n){
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0) continue;
        for(int j=1;j<=n;j++){
            if(i==j||a[j]==0) continue;
            int ob=a[i];
            ret^=a[i];
            ret^=a[j];
            a[j]+=a[i];
            a[i]=0;
            ret^=a[j];
            dfs(x+1,ret);
            ret^=a[j];
            a[i]=ob;
            a[j]-=ob;
            ret^=a[i];
            ret^=a[j];
        }
    }
}
signed main(){
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum^=a[i];
    dfs(1,sum);
    cout<<ans<<'\n';
}