#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7;
int g[2][2],rg[2][2],ret[2][2];
int x1,x2,a,b,n;
void multi(int op){
    if(op==1){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ret[i][j]=(ret[i][j]+g[i][k]*rg[k][j]%P)%P;
                }
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                rg[i][j]=ret[i][j];
                ret[i][j]=0;
            }
        }
    }else{
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ret[i][j]=(ret[i][j]+g[i][k]*g[k][j]%P)%P;
                }
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                g[i][j]=ret[i][j];
                ret[i][j]=0;
            }
        }
    }
}
void fp(int y){
    rg[0][0]=1;
    rg[0][1]=0;
    rg[1][0]=0;
    rg[1][1]=1;
    while(y){
        if(y&1) multi(1);
        multi(0);
        y>>=1;
    }
}
signed main(){
    while(scanf("%lld%lld%lld%lld%lld",&x1,&x2,&a,&b,&n)!=EOF){
        g[0][0]=b;
        g[0][1]=a;
        g[1][0]=1;
        g[1][1]=0;
        if(n==1) printf("%lld",x1);
        else if(n==2) printf("%lld",x2);
        else {
            fp(n-2);
            printf("%lld\n",(x2*rg[0][0]%P+x1*rg[0][1]%P)%P);
        }
    }
}