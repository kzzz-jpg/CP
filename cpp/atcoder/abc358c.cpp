#include<bits/stdc++.h>
using namespace std;
int n,m,chk,ans=9999;
int a[12];
void dfs(int x,int d,int nw){
        if(x>n){
                if(nw==chk) ans=min(ans,d);
                return;
        }
        dfs(x+1,d+1,nw|a[x]);
        dfs(x+1,d,nw);
}
signed main(){
        cin>>n>>m;
        chk=(1<<m)-1;
        string s;
        for(int i=1;i<=n;i++){
                cin>>s;
                for(int j=0;j<m;j++){
                        a[i]<<=1;
                        if(s[j]=='o') a[i]|=1;
                }
        }
        dfs(1,0,0);
        cout<<ans<<'\n';
}
