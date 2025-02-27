#include<stdio.h>
long long a,b,c,x,y,z;
int v[]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long f(int a,int b,int c){
    int ret=0;
    for(int i=1;i<a;i++){
        if(i%400==0||(i%4==0&&i%100!=0)) ret+=366;
        else ret+=365;
    }
    for(int i=1;i<b;i++){
        if(i==2&&(a%400==0||(a%4==0&&a%100!=0))) ret+=29;
        else ret+=v[i];
    }
    return ret+c;
}
signed main(){
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF){
        scanf("%lld%lld%lld",&x,&y,&z);
        a=f(a,b,c);
        x=f(x,y,z);
        if(a<x) a^=x^=a^=x;
        printf("%lld\n",a-x);
    }
}