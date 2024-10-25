#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool chk(int x){
    if(x==1) return false;
    if(x==2) return true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
int ans=0,test;
signed main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        test=0;
        for(int j=i;j<s.size();j++){
            test=test*10+(s[j]-'0');
            if(test>=1000) break;
            if(chk(test)) ans=max(ans,test);
        }
    }
    cout<<ans<<'\n';
}