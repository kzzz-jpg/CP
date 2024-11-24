#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int P=998224353;
int fp(int x,int y,int md){
        int ans=1;
        while(y){
                if(y&1) ans=(ans*x)%md;
                x=(x*x)%md;
                y>>=1;
        }
        return ans;
}
int inv(int x){
        return fp(x,P-2,P);
}
int fib(int x){
        if(x==0)return 1;
        return (x*fib(x-1))%P;
}
signed main(){
        cin>>n>>k;
        cerr<<fib(n)<<' '<<inv(fib(k))<<' '<<inv(fib(n-k))<<'\n';
        cerr<<(499122177*6LL)%P<<'\n';
        int ans=(fib(n)*(inv(fib(k))%P)*(inv(fib(n-k))%P))%P;
        cout<<ans<<'\n';
}
