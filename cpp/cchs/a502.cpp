#include<bits/stdc++.h>
using namespace std;
int getdig(int x){
    int ret=0;
    while(x){
        ret++;
        x/=10;
    }
    return ret;
}
bool chk(int x){
    int dig=getdig(x);
    int tmp=x;
    int ret=0;
    while(tmp){
        ret+=pow(tmp%10,dig);
        tmp/=10;
    }
    return ret==x;
}
signed main(){
    int l,r;
    bool hasans;
    while(cin>>l>>r){
        hasans=0;
        for(int i=r;i>=l;i--){
            if(chk(i)) cout<<i<<'\n',hasans=1;
        } 
        if(!hasans) cout<<0<<'\n';
    }
}