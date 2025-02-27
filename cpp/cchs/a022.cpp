#include<cstdio>
int n,m;
signed main(){
    scanf("%d%d",&n,&m);
    m+=n*60;
    if(n>=7*60+30&&n<17*60) printf("At School");
    else printf("Off School");
}