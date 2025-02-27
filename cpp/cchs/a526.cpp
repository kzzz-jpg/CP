#include<cstdio>
int x,y;
signed main(){
    scanf("%d%d",&x,&y);
    if((x-3)*(x-3)+(y-4)*(y-4)<=100) printf("Inside");
    else printf("Outside");
}