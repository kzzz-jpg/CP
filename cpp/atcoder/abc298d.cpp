#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int fp(int y){
    int x=10;
    int ret=1;
    while(y){
        if(y&1) ret=(ret*x)%P;
        x=(x*x)%P;
        y>>=1;
    }
    return ret;
}
int q,ans=1;
signed main(){
    queue<int> s;
    s.push(1);
    cin>>q;
    int op,x;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>x;
            s.push(x);
            ans=(ans*10+x)%P;
        }else if(op==2){
            ans=(ans-fp(s.size()-1)*s.front()+10*P)%P;
            s.pop();
        }else{
            cout<<ans<<'\n';
        }
    }
}
