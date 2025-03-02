#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
#define CP
#define int long long
int n,k,ans;
const int P=1e9+7;
int hd[200500],to[200500],nxt[200500],cnt=1,a[200500];
void addE(int a,int b){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt++;
}
void dfs(int x,int par){
    int nw=0;
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]==par) continue;
        if(nw){
            a[to[e]]=nw-1;
        }else{
            if(par){
                a[to[e]]=k-2;
            }else{
                a[to[e]]=k-1;
            }
        }
        nw=a[to[e]];
    }
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]!=par) dfs(to[e],x);
    }
    //cerr<<x<<' '<<a[x]<<'\n';
}
signed main(){
    #ifdef  CP 
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    freopen("err.out","w",stderr);
    #endif
    scanf("%lld%lld",&n,&k);
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&x,&y);
        addE(x,y);
        addE(y,x);
    }
    a[1]=k;
    dfs(1,0);
    ans=1;
    for(int i=1;i<=n;i++){
        if(a[i]<=0){
            putchar('0');
            putchar('\n');
            return 0;
        }
        ans=(ans%P*a[i]%P)%P;
    }
    printf("%lld",ans);
}