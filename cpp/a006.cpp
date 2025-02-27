#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,e,f,flag=1;
int F(int x){
    int ret=0;
    ret+=a*x*x*x*x*x;
    ret+=b*x*x*x*x;
    ret+=c*x*x*x;
    ret+=d*x*x;
    ret+=e*x;
    ret+=f;
    return ret;
}
signed main(){
    scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
    if((a|b|c|d|e|f)==0) {
        puts("Too many... = =\"");
        return 0;
    }
    for(int x=-35;x<=35;x++){
        if(F(x)*F(x-1)<0) printf("%lld %lld\n",x-1,x),flag=0;
        else if(F(x)==0) printf("%lld %lld\n",x,x),flag=0;
    }
    if(flag) puts("N0THING! >\\\\\\<");
}