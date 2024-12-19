#include<bits/stdc++.h>
#define int long long
using namespace std;
int vs[250];
int x[250],y[250],p[250];
int n,ret;
void dfs(int nw,int s){
        vs[nw]=1;
        ret++;
        for(int i=1;i<=n;i++){
                if(vs[i]) continue;
                if(abs(x[nw]-x[i])+abs(y[nw]-y[i])<=s*p[nw]) dfs(i,s);
        }
}
bool solve(int s){
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) vs[j]=0;
                ret=0;
                dfs(i,s);
                if(ret==n) return 1;
        }
        return 0;
}
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>p[i];
        int ans=4e9;
        for(int j=4e9;j;j>>=1){
                while(ans-j>0&&solve(ans-j)) ans-=j;
        }
        cout<<ans<<'\n';
}
