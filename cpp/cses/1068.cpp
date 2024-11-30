#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    scanf("%lld",&n);
    while(n!=1){
        if(n%2==1){
            printf("%lld ",n);
            n=n*3+1;
        }else{
            printf("%lld ",n);
            n/=2;
        }
    }
    printf("1\n");
    return 0;
}