#include<bits/stdc++.h>
using namespace std;
bitset<1000000> bs;
int n,a,sum;
int main(){
    cin>>n;
    bs[0]=1;
    while(n--){
        cin>>a;
        bs|=bs<<a;
        sum+=a;
    }
    if(sum&1){
        cout<<0<<'\n';
    }else if(bs[sum>>1]){
        cout<<1<<'\n';
    }else{
        cout<<0<<'\n';
    }
}