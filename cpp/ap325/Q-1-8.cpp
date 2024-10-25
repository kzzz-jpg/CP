#include<bits/stdc++.h>

using namespace std;
long long p;
int n;
long long maxi=0;
long long a[26];
void func(int i,int index){
    if(i>=n){
        if(index>maxi&&index<p){
            maxi=index;
        }
        return;
    }
    func(i+1,index+a[i]);
    func(i+1,index);
}
int main()
{
    scanf("%d%lld",&n,&p);
    for(int i=0;i<n;i++)
    scanf("%lld",a+i);
    func(0,0);
    printf("%lld",maxi);
    return 0;
}