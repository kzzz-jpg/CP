#include<bits/stdc++.h>
using namespace std;
int n,a,b;
signed main(){
    scanf("%d",&n);
    while(n>=10){
        if(n>=1000){
            a=n/100;
            b=n%100;
            n=(a/10)*(a%10);
            if(b<10) n=n*10+b;
            else {
                b=(b/10)*(b%10);
                if(b>10) n=n*100+b;
                else n=n*10+b;
            }
        }else if(n>=100){
            a=n/100*(n%100/10);
            b=(n%100/10)*(n%10);
            n=a;
            if(b>10) n=n*100+b;
            else n=n*10+b;
        }else if(n>=10){
            n=(n/10)*(n%10);
        }
    }
    printf("%d",n);
}