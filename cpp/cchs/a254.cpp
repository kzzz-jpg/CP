#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,tgcd,tlcm=1,tmp;
int a[200500];
int clcm(int a,int b){
    return a*b/__gcd(a,b);
}
signed main(){
    while(scanf("%lld",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%lld",&tmp);
            if(i==1) tgcd=tmp,tlcm=tmp;
            else tgcd=__gcd(tmp,tgcd),tlcm=clcm(tmp,tlcm);
        }
        printf("%lld %lld\n",tgcd,tlcm);
    }
}