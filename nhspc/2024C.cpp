#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int hd[500500],nxt[1000500],to[1000500],w[1000500];
int dp[500500][2]; // 0 mx / 1 mn
int ansmx,ansmn=1e18;
int cnt=1;
void addE(int a,int b,int c){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    w[cnt]=c;
    hd[a]=cnt++;
}
void dfs(int x,int par){
    int mn1=1e18,mn2=1e18,mx1=0,mx2=0;
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]==par) continue;
        dfs(to[e],x);
        if(dp[to[e]][0]+w[e]>mx1){
            mx2=mx1;
            mx1=dp[to[e]][0]+w[e];
            
        }else if(dp[to[e]][0]+w[e]>mx2){
            mx2=dp[to[e]][0]+w[e];
        }
        if(dp[to[e]][1]+w[e]<mn1){
            mn2=mn1;
            mn1=dp[to[e]][1]+w[e];
        }else if(dp[to[e]][1]+w[e]<mn2){
            mn2=dp[to[e]][1]+w[e];
        }
    }
    if(mn1==1e18) dp[x][1]=0;
    else dp[x][1]=mn1;
    dp[x][0]=mx1;
    if(x==1&&mn2==1e18) ansmn=min(ansmn,mn1);
    ansmn=min(mn1+mn2,ansmn);
    ansmx=max(ansmx,mx1+mx2);
}
signed main(){
    cin>>n;
    int x,y,v;
    for(int i=1;i<n;i++){
        cin>>x>>y>>v;
        addE(x,y,v);
        addE(y,x,v);
    }
    dfs(1,1);
    cout<<ansmx<<' '<<ansmn<<'\n';
}