#include<bits/stdc++.h>
using namespace std;
int n;
int hd[300500],to[600500],nxt[600500];
int deg[300500];
int cnt=1;
void addE(int a,int b){
        to[cnt]=b;
        nxt[cnt]=hd[a];
        hd[a]=cnt++;
}
int tmp[300500];
int ans;
void dfs(int x,int par){
        cnt=0;
        for(int e=hd[x];e;e=nxt[e]){
                tmp[++cnt]=deg[to[e]];
        }
        sort(tmp+1,tmp+1+cnt);
        for(int i=1;i<=cnt;i++){
                ans=max(tmp[i]*(cnt-i+1)+1,ans);
        }
        for(int e=hd[x];e;e=nxt[e]){
                if(to[e]!=par) dfs(to[e],x);
        }
}
signed main(){
        cin>>n;
        for(int i=0,x,y;i<n-1;i++){
                cin>>x>>y;
                addE(x,y),addE(y,x);
                deg[x]++,deg[y]++;
        }
        dfs(1,1);
        cout<<(n-ans)<<'\n';
}
