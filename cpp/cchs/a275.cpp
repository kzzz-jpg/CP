#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int dp[3050],a[3050],opt[3050];
int lg[3010]={-1},st[13][3010];
int qryMin(int l,int r){
    return min(st[lg[r-l+1]][l],st[lg[r-l+1]][r-(1<<(lg[r-l+1]))+1]);
}
void build(){
    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1;i<=lg[n];i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",st[0]+i);
    build();
    dp[2*k+1]=qryMin(1,2*k+1)*(2*k+1);
    opt[2*k+1]=qryMin(1,2*k+1);
    for(int i=2*k+2;i<=n;i++){
        for(int j=i-1;j>=max(2*k+1,i-(k*2+1)+1);j--){
            if(opt[j]<=qryMin(j+1,i)){
                if(dp[j]+qryMin(j+1,i)*(i-j)>=dp[i])
                    dp[i]=dp[j]+qryMin(j+1,i)*(i-j),opt[i]=qryMin(j+1,i);
            }
        }
        if(dp[i-(2*k+1)]+qryMin(i-2*k,i)*(2*k+1)>=dp[i])
            dp[i]=dp[i-(2*k+1)]+qryMin(i-2*k,i)*(2*k+1),opt[i]=qryMin(i-2*k,i);
    }
    for(int i=1;i<=n;i++) printf("%lld %lld\n",dp[i],opt[i]);
    printf("%lld",dp[n]);
}