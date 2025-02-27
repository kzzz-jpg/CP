#include<cstdio>
long long a,b,c;
signed main(){
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF){
        if(a>b&&a>c){
            if(a>b+c) putchar('A');
            else if(b>c) putchar('B');
            else putchar('C');
        }else if(b>c&&b>a){
            if(b>a+c) putchar('B');
            else if(a>c) putchar('A');
            else putchar('C');
        }else{
            if(c>a+b) putchar('C');
            else if(a>b) putchar('A');
            else putchar('B');
        }
        putchar('\n');
    }
}