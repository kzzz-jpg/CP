#include<bits/stdc++.h>
<<<<<<< HEAD
#define int long long
using namespace std;
int n;
int a[200500];
int dp[3050][3050];
int ans=0;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        for(int j=1;i-j>=1;j++){
            if(a[i]==a[i-j]){
                dp[i][j]=max(dp[i][j],dp[i-j][j]+1);
            }
            ans=max(ans,dp[i][j]);
           // cerr<<dp[i][j]<<' ';
        }
       // cerr<<'\n';
    }
    cout<<ans+1<<'\n';
}
=======
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
>>>>>>> af6444576b03fae9756fdce3bba9bbe49c13ac97
