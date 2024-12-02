#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
//struct mp{
//    int w,all;
//    void operator + (mp o){
//        w=(w+o.w)%P;
//        all=(all+o.all)%P;
//    }
//    mp operator = (mp o){
//        w=o.w;
//        all=o.all;
//        return mp(w,all);
//    }
//    mp(int a=0,int b=0):w(a),all(b){}
//} dp[110][110][2];
int fp(int x,int y=P-2){
    int ret=1;
    while(y){
        if(y&1) ret=(ret*x)%P;
        x=(x*x)%P;
        y>>=1;
    }
    return ret;
}
int dp[110][110][2][220];
int n,a,b,p,q;
void init(){
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) for(int k=0;k<=200;k++) dp[i][j][0][k]=dp[i][j][1][k]=-1;
}
int dfs(int anw,int bnw,int who,int tm){
    if(anw==n){
        return fp((fp(q,(tm/2))*fp(p,(tm/2)+1))%P);
    }
    if(bnw==n){
        return 0;
    }
    if(dp[anw][bnw][who][tm]!=-1) return dp[anw][bnw][who][tm];
    int nw=0;
    if(who==0){
        for(int i=1;i<=p;i++){
            nw=(nw+dfs(min(anw+i,n),bnw,1LL,tm+1))%P;
        }
    }else{
        for(int i=1;i<=q;i++){
            nw=(nw+dfs(anw,min(bnw+i,n),0LL,tm+1))%P;
        }
    }
    dp[anw][bnw][who][tm]=nw;
    return nw;
}

signed main(){
    cin>>n>>a>>b>>p>>q;
    init();
    auto ans=dfs(a,b,0,0);
    cout<<ans<<'\n';
}
