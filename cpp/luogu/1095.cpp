#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,s,t;
signed main(){
    cin>>m>>s>>t;
    int nw=0;
    for(int i=1;i<=t;i++){
        if(m>=10){
            nw+=60;
            m-=10;
        }else if(nw+34>=s&&t-i>=2){
            cout<<"Yes\n"<<i+2<<'\n';
            return 0;
        }else if(nw+17>=s&&t>i){
            cout<<"Yes\n"<<i+1<<'\n';
            return 0;
        }else{
            m+=4;
        }
        if(nw>=s) {
            cout<<"Yes\n"<<i<<'\n';
            return 0;
        }
    }
    cout<<"No\n"<<max({nw,(m<=16)?nw+17:0,(m<=6)?nw+34:0})<<'\n';
}