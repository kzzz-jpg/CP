#include<cstdio>
const int P=10009,mod=1e9+9;
int n,x,y,env[10100],a[30500],dp[2][10009];
long long tmp;
void exgcd(int a,int b){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b);
    int t=x;
    x=y;
    y=t-(a/b)*y;
}
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=P;i++){
        exgcd(i,P);
        x=(x%P+P)%P;
        env[x]=x;
    }
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    dp[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=P;j++){
            tmp=dp[(i-1)&1][j]+dp[(i-1)&1][(long long)j*env[a[i]]%P];
            tmp%=mod;
            dp[i&1][j]=tmp;
        }
    }
    printf("%d",dp[n&1][1]-1);
}