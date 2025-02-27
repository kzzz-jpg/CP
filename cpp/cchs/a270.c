#include<stdio.h>
#define int long long
int n,m,k,t;
signed main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;;i++){
        if(k&1){
            if(i&1){
                if(n<55) break;
                else {
                    n-=55;
                    if(n==0)printf("%lld: Wayne drinks a Corn soup, and now he doesn't have money.\n",t);
                    else printf("%lld: Wayne drinks a Corn soup, and now he has %lld dollar%s.\n",t,n,n==1?"":"s");
                }
            }else{
                if(n<32) break;
                else {
                    n-=32;
                    if(n==0)printf("%lld: Wayne eats an Apple pie, and now he doesn't have money.\n",t);
                    else printf("%lld: Wayne eats an Apple pie, and now he has %lld dollar%s.\n",t,n,n==1?"":"s");
                }
            }
        }else{
            if((i+1)&1){
                if(n<55) break;
                else {
                    n-=55;
                    if(n==0)printf("%lld: Wayne drinks a Corn soup, and now he doesn't have money.\n",t);
                    else printf("%lld: Wayne drinks a Corn soup, and now he has %lld dollar%s.\n",t,n,n==1?"":"s");
                }
            }else{
                if(n<32) break;
                else {
                    n-=32;
                    if(n==0)printf("%lld: Wayne eats an Apple pie, and now he doesn't have money.\n",t);
                    else printf("%lld: Wayne eats an Apple pie, and now he has %lld dollar%s.\n",t,n,n==1?"":"s");
                }
            }
        }
        t+=m;
    }
    if(t==0) puts("Wayne can't eat and drink.");
}